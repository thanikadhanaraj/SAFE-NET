#include <WiFi.h>
#include <Firebase_ESP_Client.h>
#include <HTTPClient.h>
#include <ArduinoJson.h>

// ================= WIFI =================
#define WIFI_SSID "Thani"
#define WIFI_PASSWORD "12345612"

// ================= FIREBASE =================
#define API_KEY "AIzaSyDZ07Rm9jQUy7QIk6Hcu6_ghNaBoTjLEPE"
#define DATABASE_URL "https://safe-net-448cb-default-rtdb.firebaseio.com/"
#define USER_EMAIL "esp32@safe.net"
#define USER_PASSWORD "12345678"

// ================= WEATHER =================
#define WEATHER_API_KEY "YOUR_OPENWEATHER_KEY"
#define CITY "Chennai"
#define COUNTRY "IN"

// ================= PINS =================
#define TRIG 5
#define ECHO 18
#define SOIL 34   // analog pin

#define CYCLE_INTERVAL 15000   // 15 sec

FirebaseData fbdo;
FirebaseAuth auth;
FirebaseConfig config;

float lastRiverLevel = 0;
int risingCounter = 0;

unsigned long lastCycle = 0;

// ================= READ ULTRASONIC =================
float readRiverLevel() {
  digitalWrite(TRIG, LOW);
  delayMicroseconds(2);
  digitalWrite(TRIG, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIG, LOW);

  long duration = pulseIn(ECHO, HIGH, 30000);
  float distance = duration * 0.034 / 2.0;

  // Convert to normalized risk score (0-10)
  float levelScore = map(distance, 30, 5, 0, 10);
  return constrain(levelScore, 0, 10);
}

// ================= READ SOIL =================
float readSoilMoisture() {
  int value = analogRead(SOIL);
  float moisture = map(value, 4095, 0, 0, 10);
  return constrain(moisture, 0, 10);
}

// ================= FETCH WEATHER =================
float fetchRainForecast() {

  String url = "http://api.openweathermap.org/data/2.5/forecast?q=" +
               String(CITY) + "," + String(COUNTRY) +
               "&appid=" + WEATHER_API_KEY + "&units=metric";

  HTTPClient http;
  http.begin(url);
  int httpCode = http.GET();

  if (httpCode == 200) {
    String payload = http.getString();
    DynamicJsonDocument doc(4096);
    deserializeJson(doc, payload);

    float rain = doc["list"][0]["rain"]["3h"] | 0.0;
    http.end();

    return constrain(rain, 0, 10);
  }

  http.end();
  return 0;
}

// ================= SETUP =================
void setup() {

  Serial.begin(115200);

  pinMode(TRIG, OUTPUT);
  pinMode(ECHO, INPUT);

  WiFi.begin(WIFI_SSID, WIFI_PASSWORD);
  while (WiFi.status() != WL_CONNECTED) delay(500);

  config.api_key = API_KEY;
  config.database_url = DATABASE_URL;
  auth.user.email = USER_EMAIL;
  auth.user.password = USER_PASSWORD;

  Firebase.begin(&config, &auth);
  Firebase.reconnectWiFi(true);

  Serial.println("SAFE-NET REAL MODE STARTED");
}

// ================= LOOP =================
void loop() {

  if (millis() - lastCycle >= CYCLE_INTERVAL) {

    lastCycle = millis();

    float RiverLevel = readRiverLevel();
    float SoilWet = readSoilMoisture();
    float RainForecast = fetchRainForecast();

    float DamRelease = 0;
    if (Firebase.RTDB.getFloat(&fbdo, "/DamReleaseLevel"))
      DamRelease = fbdo.floatData();

    // ================= FLOOD RISK INDEX =================
    float FloodRiskIndex =
        0.45 * RiverLevel +
        0.25 * RainForecast +
        0.20 * DamRelease +
        0.10 * SoilWet;

    int PredictiveWarning = 0;
    int Emergency2h = 0;

    // ================= TREND ANALYSIS =================
    if (RiverLevel > lastRiverLevel)
      risingCounter++;
    else
      risingCounter = 0;

    lastRiverLevel = RiverLevel;

    if (FloodRiskIndex > 5)
      PredictiveWarning = 1;

    if (risingCounter >= 3 && FloodRiskIndex > 7)
      Emergency2h = 1;

    // ================= FIREBASE UPDATE =================
    Firebase.RTDB.setFloat(&fbdo, "/RiverLevel", RiverLevel);
    Firebase.RTDB.setFloat(&fbdo, "/SoilMoisture", SoilWet);
    Firebase.RTDB.setFloat(&fbdo, "/RainForecast", RainForecast);
    Firebase.RTDB.setFloat(&fbdo, "/FloodRiskIndex", FloodRiskIndex);
    Firebase.RTDB.setInt(&fbdo, "/PredictiveWarning", PredictiveWarning);
    Firebase.RTDB.setInt(&fbdo, "/Emergency2h", Emergency2h);

    Serial.println("FloodRiskIndex: " + String(FloodRiskIndex));
  }
}
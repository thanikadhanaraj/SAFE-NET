#include <WiFi.h>
#include <Firebase_ESP_Client.h>
#include <DFRobotDFPlayerMini.h>

// WIFI
#define WIFI_SSID "Thani"
#define WIFI_PASSWORD "12345612"

// FIREBASE
#define API_KEY "AIzaSyDZ07Rm9jQUy7QIk6Hcu6_ghNaBoTjLEPE"
#define DATABASE_URL "https://safe-net-448cb-default-rtdb.firebaseio.com/"
#define USER_EMAIL "esp32@safe.net"
#define USER_PASSWORD "12345678"

FirebaseData fbdo;
FirebaseAuth auth;
FirebaseConfig config;

HardwareSerial mySerial(2);
DFRobotDFPlayerMini player;

int lastPredictive = 0;
int lastEmergency = 0;

void setup() {

  Serial.begin(115200);

  WiFi.begin(WIFI_SSID, WIFI_PASSWORD);
  while (WiFi.status() != WL_CONNECTED) delay(500);

  config.api_key = API_KEY;
  config.database_url = DATABASE_URL;
  auth.user.email = USER_EMAIL;
  auth.user.password = USER_PASSWORD;

  Firebase.begin(&config, &auth);
  Firebase.reconnectWiFi(true);

  mySerial.begin(9600, SERIAL_8N1, 16, 17);

  if (!player.begin(mySerial)) {
    Serial.println("DFPlayer error");
    while (true);
  }

  player.volume(25);
}

void loop() {

  int predictive = 0;
  int emergency = 0;

  if (Firebase.RTDB.getInt(&fbdo, "/PredictiveWarning"))
    predictive = fbdo.intData();

  if (Firebase.RTDB.getInt(&fbdo, "/Emergency2h"))
    emergency = fbdo.intData();

  // Emergency priority
  if (emergency == 1 && lastEmergency == 0) {
    player.play(2);  // 0002.mp3
  }

  else if (predictive == 1 && lastPredictive == 0) {
    player.play(1);  // 0001.mp3
  }

  lastPredictive = predictive;
  lastEmergency = emergency;

  delay(2000);
}
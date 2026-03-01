# SAFE-NET
SAFE-NET is an Edge AI–based Predictive Flood Intelligence System that uses multi-sensor data and a 50K-trained ML model to compute a dynamic FloodRiskIndex, enabling early warning and 2-hour emergency alerts through an Edge-to-Cloud architecture.

###The app looks like:
<img width="620" height="1386" alt="image" src="https://github.com/user-attachments/assets/46a4f401-c631-4979-b6b5-667834b829ca" />
<img width="620" height="1386" alt="image" src="https://github.com/user-attachments/assets/806fc7e9-51ea-41a0-ae36-3ff7bed9ea7e" />
<img width="620" height="1386" alt="image" src="https://github.com/user-attachments/assets/9afcb6e6-070e-4db0-a9d7-9d0b678ddd71" />
<img width="620" height="1386" alt="image" src="https://github.com/user-attachments/assets/5170406e-420c-4555-af18-4e335b138125" />
<img width="620" height="1386" alt="image" src="https://github.com/user-attachments/assets/2aed1e03-de93-414e-9dc5-3bf230fc9fa4" />

##What is your Idea about?
SAFE-NET is an Edge AI–powered Predictive Flood Intelligence System designed to shift disaster management from reactive response to proactive prevention.  Traditional flood monitoring systems detect floods only after water levels cross danger thresholds. SAFE-NET replaces static detection with predictive intelligence by analyzing multi-source environmental data in real time.  The system integrates:  River level sensing (Ultrasonic)  Soil saturation monitoring  Rainfall forecast data  Dam release parameters  These inputs are processed using a trained AI model developed on 50,000 flood-pattern datasets using Google Colab. The model was optimized for lightweight inference and deployed directly on an ESP32 edge device, enabling autonomous decision-making without relying on constant cloud processing.  SAFE-NET computes a dynamic FloodRiskIndex and activates a two-stage alert mechanism:  • Predictive Warning (early escalation detection) • 2-Hour Emergency Alert (trend-confirmed risk)  The system is connected to Firebase for real-time monitoring and includes a mobile application that displays live risk levels and alerts.  SAFE-NET transforms flood response from detection to prediction using Edge AI.

##What problem are you trying to solve?
Flood disasters cause severe economic losses and casualties, largely due to delayed warning systems. Most current flood monitoring solutions rely on static threshold detection, triggering alerts only after critical water levels are reached.  Key limitations of existing systems include:  No short-term predictive intelligence  No trend-based early risk escalation detection  No unified integration of rainfall forecast, dam release, soil saturation, and river rise  Lack of autonomous edge-level processing  Limited deployment in rural and high-risk riverbank regions  As climate variability increases extreme rainfall events, reactive detection models are insufficient.  SAFE-NET addresses these structural gaps by introducing:  Edge AI–based predictive modeling  Multi-factor FloodRiskIndex computation  Trend-based emergency escalation logic  Real-time cloud synchronization  Automated voice-based local alert system  By identifying escalating flood risk before danger thresholds are reached, SAFE-NET enables earlier evacuation and reduces disaster impact.

##Technology Stack being used?
ESP32 Edge AI inference, 50K GPU-trained ML model, multi-sensor fusion, Weather API, Firebase Cloud, Android App, DFPlayer Alerts, distributed Edge-to-Cloud system.

##Impact of your solution
SAFE-NET has the potential to significantly transform flood risk management by introducing predictive intelligence at the community level. Unlike conventional threshold-based monitoring systems that activate alerts only after critical water levels are reached, SAFE-NET detects risk escalation patterns in advance using Edge AI–driven multi-factor analysis.

By computing a dynamic FloodRiskIndex from real-time river levels, rainfall forecasts, soil saturation, and dam release data, SAFE-NET enables earlier warning dissemination. This reduces evacuation latency and enhances preparedness, particularly in rural and riverbank communities where centralized monitoring infrastructure may be limited.

The system’s edge-level autonomous processing ensures that alerts can be generated locally without relying solely on continuous cloud communication. This makes SAFE-NET resilient, scalable, and suitable for deployment in distributed environments.

At scale, SAFE-NET can be integrated with irrigation departments, dam authorities, and disaster management agencies to create a network of intelligent sensing nodes capable of real-time predictive flood analytics. The architecture supports expansion from village-level deployment to district and state-wide monitoring systems.

By shifting disaster response from reactive detection to predictive prevention, SAFE-NET contributes to:

• Reduced casualty rates through earlier evacuation
• Lower economic losses in agriculture and infrastructure
• Improved climate resilience in flood-prone regions
• Faster decision-making through real-time analytics

With increasing climate variability and extreme rainfall events, predictive systems like SAFE-NET represent a necessary evolution in disaster preparedness infrastructure.

SAFE-NET demonstrates how Edge AI, embedded systems, and cloud integration can be combined to build scalable, real-world climate resilience solutions.

##The Project SETUP
<img width="1600" height="1200" alt="image" src="https://github.com/user-attachments/assets/cd96fad2-e5e2-4f8d-aea4-9957ddfc8baa" />
<img width="1200" height="1600" alt="image" src="https://github.com/user-attachments/assets/0c3857a2-1ce5-408b-a959-aff93db58703" />
<img width="1200" height="1600" alt="image" src="https://github.com/user-attachments/assets/001d895c-be0c-489a-b6f6-dfa55b6c941c" />

##YOUTUBE LINK:https://youtu.be/ObL4403vWG8?si=GiO4PmTqKePp5uYi



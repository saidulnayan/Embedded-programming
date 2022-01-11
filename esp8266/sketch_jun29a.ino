 #define BLYNK_PRINT Serial  
 #include <ESP8266WiFi.h>  
 #include <BlynkSimpleEsp8266.h>  
 #define Relay1  D0  
 #define trigPin D1  
 #define echoPin D2  
 long duration;  
 float distanceCm, distanceInch, distanceft ,Watercft ,Waterlitre,Waterft, ECm,Eft,Wft;//fffddc  
  int wper,WCm;   
 // You should get Auth Token in the Blynk App.  
 char auth[] = "6ebEjufhDN07Hx-yqG9PdAwmGxUYXViI";  
 // Your WiFi credentials.  
 // Set password to "" for open networks.  
 char ssid[] = "FreeFire";  
 char pass[] = "123456789###";  
 BlynkTimer timer;  
 void setup()  
 {  
  // Debug console  
  pinMode(trigPin, OUTPUT);  
  pinMode(D0, OUTPUT);// Sets the trigPin as an Output  
  pinMode(echoPin, INPUT);  // Sets the echoPin as an Inpu  
  Serial.begin(9600);  
  Blynk.begin(auth, ssid, pass);  
  // Setup a function to be called every second  
  timer.setInterval(1000L, sendSensor);  
 }  
 void loop()  
 {  
  Blynk.run();  
  timer.run();  
 }  
 void sendSensor()  
 {  
  digitalWrite(trigPin, LOW);  
 delayMicroseconds(2);  
 digitalWrite(trigPin, HIGH);  
 delayMicroseconds(10);  
 digitalWrite(trigPin, LOW);  
 duration = pulseIn(echoPin, HIGH);  
 distanceCm= duration*0.034/2;  
 distanceInch = duration*0.0133/2;  
 Serial.print("Distance: ");  
  Serial.print(distanceInch);    
  Serial.println("Inch");   
 distanceft = distanceInch/12;  
 ECm = (distanceCm-12);  
 WCm = (82-ECm);  
 Eft = (distanceft-0.39);  
 Wft = (2.69-Eft);  
 Watercft = Wft *3.66;   
 Waterlitre = Watercft*28.32;  
 Serial.print("water: ");  
  Serial.print(Waterlitre);    
  Serial.println("litre");   
 wper=(WCm*1.21);  
 Blynk.virtualWrite(V1,Waterlitre);  
 Blynk.virtualWrite(V2,WCm);  
 Blynk.virtualWrite(V3,ECm);  
 Blynk.virtualWrite(V4,wper);  
  delay(400);              
 }  

//بِسْمِ ٱللَّٰهِ ٱلرَّحْمَٰنِ ٱلرَّحِيمِ
#include <ESP8266WiFi.h>                                         
#include <FirebaseArduino.h> 
//#include "DHT.h" 
// #include <Adafruit_Sensor.h>
//#define DHTPIN 4
//#define DHTTYPE DHT11                                  
#define FIREBASE_HOST "temp-and-hum-e4726.firebaseio.com" //Without http:// or https:// schemes
#define FIREBASE_AUTH "PBeCbZWqq7y9PRj85RyvahzbBKeDlFupioGqvSYg"
#define WIFI_SSID "TP-LINK_9F82"
#define WIFI_PASSWORD "huawei10"
//DHT dht(DHTPIN, DHTTYPE);
float tValue;
float hValue;
float temp=1.2;
float hum=20.2;
///////////////
int buttonpin=14;
int relaypin=5;
float btnvalue;
int dt=100;                                                                                
void setup() {
  Serial.begin(9600);                     
  WiFi.begin(WIFI_SSID, WIFI_PASSWORD);                                      
  Serial.print("Connecting:");
 while (WiFi.status() != WL_CONNECTED) {
   Serial.print(".");
  delay(500);
 }
  Serial.println();
  Serial.print("Connected: ");
  Serial.println(WiFi.localIP());                                                     
  Firebase.begin(FIREBASE_HOST, FIREBASE_AUTH);      
  String b;
  pinMode(buttonpin,INPUT);
pinMode(relaypin,OUTPUT); 
 btnvalue=digitalRead(buttonpin); 
 Firebase.setFloat("Button",btnvalue);
                                                       
}
String devicestatus;
float mob;
void loop() {
   btnvalue=digitalRead(buttonpin);
Serial.println("btnvalue");
Serial.println(btnvalue);
delay(dt);
Firebase.setFloat("Button",btnvalue);
mob=Firebase.getFloat("Mobile");  
if(btnvalue==0.00 && mob==0.00)
{
 digitalWrite(relaypin,LOW);
 devicestatus="OFF";
 Firebase.setString("DeviceStatus",devicestatus);
}
else if(btnvalue==1.00 && mob==1.00)
{
 digitalWrite(relaypin,LOW);
 devicestatus="OFF";
 Firebase.setString("DeviceStatus",devicestatus);
}
else if(btnvalue==0.00 && mob==1.00)
{
 digitalWrite(relaypin,HIGH);
 devicestatus="ON";
 Firebase.setString("DeviceStatus",devicestatus);
}
else if(btnvalue==1.00 && mob==0.00)
{
 digitalWrite(relaypin,HIGH);
 devicestatus="ON";
 Firebase.setString("DeviceStatus",devicestatus);
}
 // Firebase.setFloat("Hum",h);
  delay(15000); 
}

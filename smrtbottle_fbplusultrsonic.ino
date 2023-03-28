
#include <WiFi.h>
#include <Firebase_ESP_Client.h>
////////////////////////
#define trigger_pin 5
#define Echo_pin 18
#define LED 2
/* two variables to store duraion and distance value */
long duration;
int distance;
/////////////////////
//Provide the token generation process info.
#include "addons/TokenHelper.h"
//Provide the RTDB payload printing info and other helper functions.
#include "addons/RTDBHelper.h"

// Insert your network credentials

#define WIFI_SSID "Shreya's Galaxy A52s 5G"
#define WIFI_PASSWORD "rrfg9048"

// Insert Firebase project API Key
#define API_KEY "AIzaSyDWR9NOlbsZOCs78ppPgAI3R6NYGMJccMM"

// Insert RTDB URLefine the RTDB URL */
 
#define DATABASE_URL "https://mysmartbottle-41f3b-default-rtdb.asia-southeast1.firebasedatabase.app/"
//Define Firebase Data object
FirebaseData fbdo;

FirebaseAuth auth;
FirebaseConfig config;

unsigned long sendDataPrevMillis = 0;
int count = 0;
bool signupOK = false;

void setup(){
  Serial.begin(115200);
  WiFi.begin(WIFI_SSID, WIFI_PASSWORD);
  Serial.print("Connecting to Wi-Fi");
  while (WiFi.status() != WL_CONNECTED){
    Serial.print(".");
    delay(300);
  }
  Serial.println();
  Serial.print("Connected with IP: ");
  Serial.println(WiFi.localIP());
  Serial.println();

  /* Assign the api key (required) */
  config.api_key = API_KEY;

  /* Assign the RTDB URL (required) */
  config.database_url = DATABASE_URL;

  /* Sign up */
  if (Firebase.signUp(&config, &auth, "", "")){
    Serial.println("ok");
    signupOK = true;
  }
  else{
    Serial.printf("%s\n", config.signer.signupError.message.c_str());
  }

  /* Assign the callback function for the long running token generation task */
  config.token_status_callback = tokenStatusCallback; //see addons/TokenHelper.h
  
  Firebase.begin(&config, &auth);
  Firebase.reconnectWiFi(true);
  ///////////////////////////
  pinMode(trigger_pin, OUTPUT); // configure the trigger_pin(D9) as an Output
pinMode(LED, OUTPUT); // Set the LED (D13) pin as a digital output
pinMode(Echo_pin, INPUT); // configure the Echo_pin(D11) as an Input
  //////////////////////////
}

void loop(){
  ////////////////////////////////
  int lert=0;
  digitalWrite(trigger_pin, LOW); //set trigger signal low for 2us
delayMicroseconds(2);

/*send 10 microsecond pulse to trigger pin of HC-SR04 */
digitalWrite(trigger_pin, HIGH);  // make trigger pin active high
delayMicroseconds(10);            // wait for 10 microseconds
digitalWrite(trigger_pin, LOW);   // make trigger pin active low

/*Measure the Echo output signal duration or pulss width */
duration = pulseIn(Echo_pin, HIGH); // save time duration value in "duration variable
distance= duration*0.034/2; //Convert pulse duration into distance

/* if distance greater than 10cm, turn on LED */
// if ( (17-distance) == 0||(17-distance<2)) {
// Serial.print("Empty ");
// delay(1000);
// digitalWrite(LED, HIGH);
// lert=1;
// }
// if (distance <18) {
// digitalWrite(LED, LOW);

// // print measured distance value on Arduino serial monitor
// Serial.print("Level: ");
// Serial.print(17-distance);
// Serial.println(" cm");
// delay(1000);
// }
// if (distance > 18)
// Serial.println("Please insert bottle.");
// delay(1000);
  /////////////////////////////////
  if (Firebase.ready() && signupOK && (millis() - sendDataPrevMillis > 15000 || sendDataPrevMillis == 0)){
    sendDataPrevMillis = millis();
    // Write an Int number on the database path test/int
// ////////
if(distance>17){
  lert=0;
 if (Firebase.RTDB.setInt(&fbdo, "level/int", -1)){
      Serial.println("PASSED");
      // Serial.println("PATH: " + fbdo.dataPath());
      // Serial.println("TYPE: " + fbdo.dataType());
    }
    else {
      Serial.println("FAILED");
      Serial.println("REASON: " + fbdo.errorReason());
    }  
    if (Firebase.RTDB.setInt(&fbdo, "level/alert",lert )){
      Serial.println("PASSED");
      // Serial.println("PATH: " + fbdo.dataPath());
      // Serial.println("TYPE: " + fbdo.dataType());
    }
    else {
      Serial.println("FAILED");
      Serial.println("REASON: " + fbdo.errorReason());
    }
    delay(1000);
}
///////////////////
if((distance>=15)&&(distance<=17)){
  lert=1;
  if (Firebase.RTDB.setInt(&fbdo, "level/int", 17-distance)){
      Serial.println("PASSED");
      // Serial.println("PATH: " + fbdo.dataPath());
      // Serial.println("TYPE: " + fbdo.dataType());
    }
    else {
      Serial.println("FAILED");
      Serial.println("REASON: " + fbdo.errorReason());
    }
    if (Firebase.RTDB.setInt(&fbdo, "level/alert",lert )){
      Serial.println("PASSED");
      // Serial.println("PATH: " + fbdo.dataPath());
      // Serial.println("TYPE: " + fbdo.dataType());
    }
    else {
      Serial.println("FAILED");
      Serial.println("REASON: " + fbdo.errorReason());
    }
    delay(1000);
}
///////////////////
if(distance<15 && distance>0){
  lert=0;  
   if (Firebase.RTDB.setInt(&fbdo, "level/int", 17-distance)){
      Serial.println("PASSED");
      // Serial.println("PATH: " + fbdo.dataPath());
      // Serial.println("TYPE: " + fbdo.dataType());
    }
    else {
      Serial.println("FAILED");
      Serial.println("REASON: " + fbdo.errorReason());
    }
     if (Firebase.RTDB.setInt(&fbdo, "level/alert",lert )){
      Serial.println("PASSED");
      // Serial.println("PATH: " + fbdo.dataPath());
      // Serial.println("TYPE: " + fbdo.dataType());
    }
    else {
      Serial.println("FAILED");
      Serial.println("REASON: " + fbdo.errorReason());
    }
    delay(1000);
}
///////////////////
if(distance==0){
  lert=0;  
   if (Firebase.RTDB.setInt(&fbdo, "level/int", 17)){
      Serial.println("PASSED");
      // Serial.println("PATH: " + fbdo.dataPath());
      // Serial.println("TYPE: " + fbdo.dataType());
    }
    else {
      Serial.println("FAILED");
      Serial.println("REASON: " + fbdo.errorReason());
    }
     if (Firebase.RTDB.setInt(&fbdo, "level/alert",lert )){
      Serial.println("PASSED");
      // Serial.println("PATH: " + fbdo.dataPath());
      // Serial.println("TYPE: " + fbdo.dataType());
    }
    else {
      Serial.println("FAILED");
      Serial.println("REASON: " + fbdo.errorReason());
    }
    delay(1000);
}
///////////////////
    
  }
}
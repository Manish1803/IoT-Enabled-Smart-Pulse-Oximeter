/****************************************************************************/
#include <Wire.h> //for IIC interface
#include "MAX30100_PulseOximeter.h" //for Sensor 
#define BLYNK_PRINT Serial //for printing on serial monitor
#include <Blynk.h> //for blynk
#include <ESP8266WiFi.h>
#include "OTABlynkCredentials.h"
#include <BlynkSimpleEsp8266.h> //for Blynk on esp8266

/****************************************************************************/
credentials Credentials;

//Variables
char auth_token[33];
bool connected_to_internet = 0;
const int Erasing_button = 0;
/****************************************************************************/
#define REPORTING_PERIOD_MS 1000

// Connections : SCL PIN - D1 , SDA PIN - D2 , INT PIN - D0
PulseOximeter pox;
 
float BPM, SpO2;
uint32_t tsLastReport = 0;
 
 
void onBeatDetected()
{
    Serial.println("Beat Detected!");
}

/****************************************************************************/
//Provide credentials for your ESP server
char* esp_ssid = "Oximeter";
char* esp_pass = "";


void setup() // Code here is executed once

{

  Serial.begin(115200);
  pinMode(Erasing_button, INPUT);


  for (uint8_t t = 4; t > 0; t--) { //4 is 4 times delay 1000
    Serial.println(t);
    delay(1000);
  }

  // Press and hold the button to erase all the credentials
  if (digitalRead(Erasing_button) == LOW)
  {
    Credentials.Erase_eeprom();

  }

  String auth_string = Credentials.EEPROM_Config();
  auth_string.toCharArray(auth_token, 33);

  if (Credentials.credentials_get())
  {

    Blynk.config(auth_token);
    connected_to_internet = 1;

  }
  else
  {
    Credentials.setupAP(esp_ssid, esp_pass);
    connected_to_internet = 0;
  }


  if (connected_to_internet)
  {
/****************************************************************************/
    pinMode(16, OUTPUT);
    Serial.print("Initializing Pulse Oximeter..");
 
    if (!pox.begin())
    {
         Serial.println("FAILED");
         for(;;);
    }
    else
    {
         Serial.println("SUCCESS");
         //pox.setOnBeatDetectedCallback(onBeatDetected);
    }
 
    // The default current for the IR LED is 50mA and it could be changed by uncommenting the following line.
        pox.setIRLedCurrent(MAX30100_LED_CURR_11MA);
/****************************************************************************/
  }

}



void loop()
{
  Credentials.server_loops();

  if (connected_to_internet)
  {
/****************************************************************************/
    pox.update();
    Blynk.run();
 
    BPM = pox.getHeartRate();
    SpO2 = pox.getSpO2();
    if (millis() - tsLastReport > REPORTING_PERIOD_MS)
    {
        Serial.print("Heart rate: ");
        Serial.print(BPM);
        Serial.print(" BPM");
        Serial.print(" SpO2: ");
        Serial.print(SpO2);
        Serial.println(" %");
 
        Blynk.virtualWrite(V3, BPM);
        Blynk.virtualWrite(V4, SpO2);
 
        tsLastReport = millis();
  }
/****************************************************************************/
}
}

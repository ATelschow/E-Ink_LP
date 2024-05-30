
#include <WiFi.h>
#include <PubSubClient.h>
#include <WiFiClient.h>
#include <WebServer.h>
#include <ESPmDNS.h>
#include <Update.h>
#include <GxEPD2_BW.h>
#include <GxEPD2_3C.h>
#include <GxEPD2_7C.h>
#include <Fonts/FreeMonoBold9pt7b.h>
#include <Fonts/FreeMonoBold12pt7b.h>
#include <Fonts/FreeMonoBold18pt7b.h>
#include <Fonts/FreeMonoBold24pt7b.h>

TaskHandle_t Task1;
TaskHandle_t Task2;

#define eink_display TRUE

#include <inserts.h>
// inserts.h contains:
// #if defined(solarfountain)
// char MQTTuser[] = "Your_MQTT_Username";
// char MQTTpassw[] = "Your_MQTT_Password"
// char ssid[] = "Your_WIFI_SSID";          
// char pass[] = "Your_Wifi_Password";     
// char OTAuser[] ="Your_OTA_Username";
// char OTApass[] = "Your_OTA_Password";  
// #endif

#include "variablen.h"
#include "ota.h"
#include "wifi_mqtt.h"

// select the display class and display driver class in the following file (new style):
#include "GxEPD2_display_selection_new_style.h"

// or select the display constructor line in one of the following files (old style):
#include "GxEPD2_display_selection.h"
#include "GxEPD2_display_selection_added.h"


int TIME_TO_SLEEP = 15;


void setup() 
{  
battery();
Serial.begin(115200);
wifirec_setup();
ota_setup();
//io_setup();
taskcreation_setup();

pinMode(36, INPUT);

//Start MQTT
client.setServer(server1, 1885); // Adresse des MQTT-Brokers
client.setCallback(callback);   // Handler für eingehende Nachrichten
reconnect();

//display.init(115200); // default 10ms reset pulse, e.g. for bare panels with DESPI-C02
display.init(115200, true, 2, false); // USE THIS for Waveshare boards with "clever" reset circuit, 2ms reset pulse
Last_Timestamp_1 = millis();
}

void Task1code( void * pvParameters )
  {
  Serial.print("Task1 running on core ");
  Serial.println(xPortGetCoreID());
  for(;;)
    {
    delay(100);
    }
  }
void Task2code( void * pvParameters )
  {
  Serial.print("Task2 running on core ");
  Serial.println(xPortGetCoreID());
  for(;;)
    {
    delay(100);
    }
  }



void loop() 
{

wifirec();
reconnect();
client.loop();
server.handleClient();  
   if (refresh == 4)
      {
      battery2();
      dtostrf(batteryvoltage, 2, 2, stringBuffer1);
      client.publish("batteryvoltage", stringBuffer1);
      dtostrf(batteryvoltage2, 2, 2, stringBuffer1);
      client.publish("batteryvoltage2", stringBuffer1);
      Serial.println(analogRead(36));
      Serial.println(batteryvoltage);
      helloWorld();
      display.hibernate();
      refresh=0;
      startDeepSleep();
      }
// 20000ms Loop
if ( ( millis() - Last_Timestamp_1) > LOOP_20000ms)
   {
   refresh=0;
   startDeepSleep();
   Last_Timestamp_1 = millis();
   }

}

void battery()
{
batteryvoltage=0;
for (int i=0;i<10;i++) 
   {
   batteryvoltage = batteryvoltage + (analogRead(36));
   }
   batteryvoltage= batteryvoltage / 10;
}
void battery2()
{
batteryvoltage2=0;
for (int i=0;i<10;i++) 
   {
   batteryvoltage2 = batteryvoltage2 + (analogRead(36));
   }
   batteryvoltage2= batteryvoltage2 / 10;
}
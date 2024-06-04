
#include <WiFi.h>
#include <PubSubClient.h>
// #include <WiFiClient.h>
//#include <WebServer.h>
//#include <ESPmDNS.h>
//#include <Update.h>

#include <GxEPD2_BW.h>
#include <GxEPD2_3C.h>
#include <GxEPD2_7C.h>
#include <Fonts/FreeMonoBold9pt7b.h>
#include <Fonts/FreeMonoBold12pt7b.h>
#include <Fonts/FreeMonoBold18pt7b.h>
#include <Fonts/FreeMonoBold24pt7b.h>

#define eink_display_xiao TRUE

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
#include "wifi_mqtt.h"

// select the display class and display driver class in the following file (new style):
#include "GxEPD2_display_selection_new_style.h"

// or select the display constructor line in one of the following files (old style):
#include "GxEPD2_display_selection.h"
#include "GxEPD2_display_selection_added.h"





void setup() 
{  
pinMode(4, INPUT);
battery();
// Serial.begin(115200);
wifirec_setup();
//io_setup();



//Start MQTT
client.setServer(server1, 1885); // Adresse des MQTT-Brokers
client.setCallback(callback);   // Handler für eingehende Nachrichten
reconnect();
client.publish(MQTTstatus, "wach");  

display.init(115200, true, 2, false); // USE THIS for Waveshare boards with "clever" reset circuit, 2ms reset pulse
Last_Timestamp_1 = millis();
}

void loop() 
{

wifirec();
reconnect();
client.loop();
// server.handleClient();  
   // if (refresh == 4)
   //    {
   //    battery2();
   //    dtostrf(batteryvoltage, 2, 2, stringBuffer1);
   //    client.publish("batteryvoltage99", stringBuffer1);
   //    dtostrf(batteryvoltage2, 2, 2, stringBuffer1);
   //    client.publish("batteryvoltage98", stringBuffer1);
   //    Serial.println(analogRead(36));
   //    Serial.println(batteryvoltage);
   //    helloWorld();
   //    display.hibernate();
   //    refresh=0;
   //    startDeepSleep();
   //    }
// 20000ms Loop
if (refresh == 6)
   {
      battery2();
      dtostrf(batteryvoltage, 2, 2, stringBuffer1);
      // client.publish("batteryvoltage3", stringBuffer1);
      client.publish("batteryvoltage5", stringBuffer1);
      dtostrf(batteryvoltage2, 2, 2, stringBuffer1);
      // client.publish("batteryvoltage4", stringBuffer1);
      client.publish("batteryvoltage6", stringBuffer1);
      // Serial.println(analogRead(36));
      // Serial.println(batteryvoltage);
      helloWorld();
      display.hibernate();
      refresh=0;
      startDeepSleep();
      Last_Timestamp_1 = millis();

   // refresh=0;
   // startDeepSleep();
   // Last_Timestamp_1 = millis();
   }

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
   batteryvoltage = batteryvoltage + (analogRead(4));
   }
   batteryvoltage= batteryvoltage / 10;

}
void battery2()
{
batteryvoltage2=0;
for (int i=0;i<10;i++) 
   {
   batteryvoltage2 = batteryvoltage2 + (analogRead(4));
   }
   batteryvoltage2= batteryvoltage2 / 10;

}
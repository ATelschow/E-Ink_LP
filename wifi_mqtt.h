#pragma region Wifi_MQTT
void callback(char* topic, byte* payload, unsigned int length) 
{
// Serial.print("Nachricht eingetroffen [");
// Serial.print(topic);
// Serial.print("]: ");
for (int i=0;i<length;i++) 
   {
   Serial.print((char)payload[i]);
   }
   Serial.println("!"); 
// Serial.println();
String myString = String(topic); 
if (myString == "tmpdraus")
   {
   for (int i=0;i<10;i++) 
   {
   tmpdraus_int[i]=0;
   }
   for (int i=0;i<length;i++) 
      {
      tmpdraus_int[i]=payload[i];
      }
   refresh++;
   }
else if (myString == "tmpwozi")
   {
   for (int i=0;i<10;i++) 
   {
   tmpwozi_int[i]=0;
   }
   for (int i=0;i<length;i++) 
      {
      tmpwozi_int[i]=payload[i];
      }
   refresh++;
   }
else if (myString == "humdraus")
   {
   for (int i=0;i<10;i++) 
   {
   humdraus_int[i]=0;
   }
   for (int i=0;i<length;i++) 
      {
      humdraus_int[i]=payload[i];
      }
   refresh++;
   }
else if (myString == "humwozi")
   {
   for (int i=0;i<10;i++) 
   {
   humwozi_int[i]=0;
   }
   for (int i=0;i<length;i++) 
      {
      humwozi_int[i]=payload[i];
      }
   refresh++;
   }

      // Zeit = (((char)payload[0])-48) * 10;
   // Zeit = Zeit + (((char)payload[1])-48);
   // tmpdraus_int[0]=payload[0];
   // tmpdraus_int[1]=payload[1];
   // tmpdraus_int[2]=payload[2];
   // tmpdraus_int[3]=payload[3];
   // tmpdraus_int[4]=payload[4];
   // car0 = payload[0] - 48;
   // // Serial.println(Zeit1);
   // car1 = payload[1] - 48;
   // car3 = payload[3] - 48;
   // Serial.println(Zeit2);
   // Zeit1 = (Zeit1-48)*10;
   // Zeit2 = payload[1] - 0;
   // Zeit2 = (Zeit2-48);
   // Zeit = Zeit1 + Zeit2;

   // Serial.print("Zeit: ");
   // Serial.println(Zeit);
   // if (Zeit < 9) (Zeit = 9);
   // if (Zeit > 19) (Zeit = 19);
   // Tgszeit_breite = (-18 * Zeit) + 342;
   // Serial.print("Tgszeit_breite: ");
   // Serial.println(Tgszeit_breite);
   
// else if (myString == "brextanf")
//    {
//    ExterneAnforderung = payload[0]-48;
//    Serial.println(ExterneAnforderung);
//    }
// else if (myString == "brpmp")
//    {
//    Pumpe_ext_anf_an = payload[0]-48;
//    Serial.println(ExterneAnforderung);
//    }


}

WiFiClient espClient;
PubSubClient client(server1, 1885, callback, espClient);
#pragma endregion Wifi_MQTT
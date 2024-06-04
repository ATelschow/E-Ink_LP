#define LOOP_20000ms 20000

unsigned long Last_Timestamp_1 = 0;


char stringBuffer1[6];


IPAddress server1(192, 168, 178, 66);

// char MQTTclient[] = "eink_display1";
// char MQTTstatus[] = "eink_state1";
char MQTTclient[] = "eink_display2";
char MQTTstatus[] = "eink_state2";
char MQTTsub1[] = "tmpdraus";
char MQTTsub2[] = "tmpwozi";
char MQTTsub3[] = "humdraus";
char MQTTsub4[] = "humwozi";
char MQTTsub5[] = "tmpbado";
char MQTTsub6[] = "humbado";

char tmpdraus_int[10];
char tmpwozi_int[10];
char humdraus_int[10];
char humwozi_int[10];
char tmpbado_int[10];
char humbado_int[10];
int refresh=0;

int batteryvoltage=0;
int batteryvoltage2=0;

#define uS_TO_S_FACTOR 1000000ULL                 //Conversion factor for micro seconds to seconds
#define TIME_TO_SLEEP  15                         //Time ESP32 will go t


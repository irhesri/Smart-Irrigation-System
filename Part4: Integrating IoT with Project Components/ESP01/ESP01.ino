
// TEMPERATURE    V0;
// HUMIDITY       V1;
// PUMP           V2;
// SOIL MOISTURE  V3;
// WATER LEVEL    V4;

#define BLYNK_TEMPLATE_ID           "xxxxxxxxxxxxx"
#define BLYNK_TEMPLATE_NAME         "xxxxxxxxxxxxx"
#define BLYNK_AUTH_TOKEN            "xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx"            

#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>

// wifi credentials
char ssid[] = "xxxxxxxxxxxxx";
char pass[] = "xxxxxxxxxxxxx";

void setup()
{
  Serial.begin(115200);
  
  Blynk.begin(BLYNK_AUTH_TOKEN, ssid, pass);
  if (Blynk.connected())
    Serial.println("connected");
}

void loop()
{
  checkConnection();
  Blynk.run();
  
  char input[21];
  Serial.readBytes(input, 20);
  
  char *data = strtok(input, "\n");
  while (data && strlen(data) > 1)
  {
    switch (data[0])
    {
      case 't':
        Blynk.virtualWrite(V0, atoi(&data[1]));
        break;
      case 'h':
        Blynk.virtualWrite(V1, atoi(&data[1]));
        break;
       case 'p':
        Blynk.virtualWrite(V2, atoi(&data[1]));
        break;
       case 'm':
        Blynk.virtualWrite(V3, atoi(&data[1]));
        break;
       case 'w':
        Blynk.virtualWrite(V4, atoi(&data[1]));
        break;
    }
    data = strtok(0, "\n");
  }
}

BLYNK_WRITE(V2)
{
  Serial.println("p" + String(param.asInt()));
}

void  checkConnection()
{
  if (!Blynk.connected())
  {
    Serial.println("disconnected");
    
    do {
      Blynk.begin(BLYNK_AUTH_TOKEN, ssid, pass);
    } while (!Blynk.connected());
    
    Serial.println("connected");
  }
}

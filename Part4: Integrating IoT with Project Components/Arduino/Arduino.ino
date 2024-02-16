
// libraries
#include <SoftwareSerial.h>
#include "DHT.h"

// pins
SoftwareSerial espSerial(2, 3);
DHT dht(4, DHT11);
#define moisturePin A0
#define relayPin 8

// constants
const int DryValue = 1023;
const int WetValue = 338;

// variables
int   moisture = 0;
int   temperature;
int   humidity;
int   waterLevel;
bool  pump = false;
bool  isConnected = false;


void setup()
{
  turnOffPump();
  
  // esp communication
  espSerial.begin(115200);

  // dht11
  dht.begin();

  // lcd
  initLCD();

  // soil moisture
  pinMode(relayPin, OUTPUT);
  digitalWrite(relayPin, HIGH);

  initWaterLevel();
}

void loop()
{
  readFromEsp();
  // dht
  temperature = dht.readTemperature();
  humidity = dht.readHumidity();
  printOnLCD(temperature, humidity);
  
  // soil moisture
  moisture = analogRead(moisturePin);
  moisture = map(moisture, DryValue, WetValue, 0, 100);
  moisture = constrain(moisture, 0, 100);

  waterLevel = checkWaterLevel();

  // send data to cloud
  if (isConnected)
    sendData();
    
  // pump
  if (moisture < 30)
  {
    pump = turnOnPump();
    delay(1000);
  }
  else if (pump)
    pump = turnOffPump();
    
  delay(1000);
}

bool turnOnPump()
{
  digitalWrite(relayPin, LOW);
  espSerial.println("p1");
  return (true);
}

bool turnOffPump()
{
  digitalWrite(relayPin, HIGH);
  espSerial.println("p0");
  return (false);
}

void readFromEsp()
{
  char input[21];

    espSerial.readBytes(input, 20);
    char *data = strtok(input, "\n");
    while (data && strlen(data) > 1)
    {
      switch (data[0])
      {
        case 'd':
          isConnected = false;
          break;
        case 'c':
          isConnected = true;
          sendData();
          break;
        case 'p':
          pump = data[1] == '1' ? turnOnPump() : turnOffPump();
          break;
      }
      data = strtok(0, "\n");
    }
}

void sendData()
{
  espSerial.println("t" + String(temperature));
  espSerial.println("h" + String(humidity));
  espSerial.println("p" + String(pump ? 1 : 0));
  espSerial.println("m" + String(moisture));
  espSerial.println("w" + String(waterLevel));
}

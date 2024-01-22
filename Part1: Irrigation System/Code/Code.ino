// pins
#define moisturePin A0
#define relayPin 8

// constants
const int DryValue = 1023;
const int WetValue = 338;

// variables
int   moisture = 0;
bool  pump = false;


void setup()
{
  turnOffPump();
  
  Serial.begin(115200);

  pinMode(relayPin, OUTPUT);
  digitalWrite(relayPin, HIGH);
}

void loop()
{
  // soil moisture
  moisture = analogRead(moisturePin);
  moisture = map(moisture, DryValue, WetValue, 0, 100);
  moisture = constrain(moisture, 0, 100);
    
  // pump control
  if (moisture < 5 && !pump)
    pump = turnOnPump();
  else if (moisture > 5 && pump)
    pump = turnOffPump();
    
  delay(1000);
}

bool turnOnPump()
{
  digitalWrite(relayPin, LOW);
  Serial.println("pump ON");
  return (true);
}

bool turnOffPump()
{
  digitalWrite(relayPin, HIGH);
  Serial.println("pump OFF");
  return (false);
}

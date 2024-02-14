#define echoPin 7
#define trigPin 6
#define greenPin 10
#define redPin 11


unsigned long maxDistance;
unsigned long maxDistance_75;
unsigned long maxDistance_50;
unsigned long maxDistance_25;
unsigned long distance;
unsigned long duration;

void setup() {
  pinMode(echoPin, INPUT);
  pinMode(trigPin, OUTPUT);
  pinMode(redPin, OUTPUT);
  pinMode(greenPin, OUTPUT);

  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  
  duration = pulseIn(echoPin, HIGH);
  maxDistance = duration * 0.034;
  maxDistance_75 = maxDistance * 0.75;
  maxDistance_50 = maxDistance * 0.50;
  maxDistance_25 = maxDistance * 0.25;
}

void loop() {
  
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  duration = pulseIn(echoPin, HIGH);
  distance = duration * 0.034;

  if (distance >= maxDistance)
  {
    // LED Red
    digitalWrite(redPin, HIGH);
    digitalWrite(greenPin, LOW);
  }
  else if (distance >= maxDistance_75)
  {
    // LED Orange
    analogWrite(redPin, 255);
    analogWrite(greenPin, 10);    
  }
  else if (distance >= maxDistance_50)
  {
    // LED Yellow
    analogWrite(redPin, 255);
    analogWrite(greenPin, 255);    
  }
  else if (distance >= maxDistance_25)
  {
    // LED Greenish
    analogWrite(redPin, 10);
    analogWrite(greenPin, 255);    
  }
  else
  {
    // LED Green
    analogWrite(redPin, 0);
    analogWrite(greenPin, 255);    
  }

  Serial.print("Distance: ");
  Serial.print(distance);
  Serial.println(" cm");

  delay(3000);
}

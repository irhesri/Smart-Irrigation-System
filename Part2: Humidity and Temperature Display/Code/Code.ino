#include<LiquidCrystal_I2C.h>
#include "DHT.h"

LiquidCrystal_I2C lcd(0x27,16,2);
DHT dht(4, DHT11);

int h, t;

void setup() {
  // initialize the lcd and the dht
  lcd.init();
  lcd.clear();
  dht.begin();
}

void loop() {
  lcd.backlight();
  h = dht.readHumidity();
  t = dht.readTemperature();
  
  lcd.setCursor(3, 0);
  lcd.print("Temp: ");
  lcd.print(t);
  lcd.print((char)223);
  lcd.print("C");

  lcd.setCursor(1, 1);
  lcd.print("Humidity: ");
  lcd.print(h);
  lcd.print("%");
  
  delay(1000);
}

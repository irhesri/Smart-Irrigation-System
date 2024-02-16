#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27, 16, 2);

void    initLCD() {
  lcd.init();
  lcd.clear();
}

void    printOnLCD(int temperature, int humidity) {
    lcd.backlight();
    lcd.setCursor(3, 0);
    lcd.print("Temp: ");
    lcd.print(temperature);
    lcd.print((char)223);
    lcd.print("C");
    lcd.setCursor(1, 1);
    lcd.print("Humidity: ");
    lcd.print(humidity);
    lcd.print("%");
}

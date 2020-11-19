#include "DHT.h"
#include <LiquidCrystal.h>

#define outputPin A0
#define type DHT11

byte degree[8] = {
  B11100,
  B10100,
  B11100,
  B00000,
  B00000,
  B00000,
  B00000,
  B00000,
};

const int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);
DHT sensor(outputPin, type);

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  
  Serial.println("Begin:");

  lcd.begin(16, 2);
  lcd.createChar(0, degree);
}

void loop() {
  // put your main code here, to run repeatedly:
  delay(250);
  
  float currentTemp = sensor.readTemperature();
  //float currentTempF = sensor.readTemperature(true);
  float currentHum = sensor.readHumidity();

  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("Temp: ");
  lcd.print(currentTemp);
  lcd.write(byte(0));
  lcd.print("C");

  lcd.setCursor(0,1);
  lcd.print("Humidity: ");
  lcd.print(currentHum/100);
  lcd.print("RH");

  Serial.print("Temperature: ");
  Serial.print(currentTemp);
  Serial.print("C\n");
  /*Serial.print("Temperature in F: ");
  Serial.print(sensor.convertCtoF(currentTemp));
  Serial.print("F\n");
  Serial.print("Temperature in C again: ");
  Serial.print(sensor.convertFtoC(currentTempF));
  Serial.print("C\n");*/
  Serial.print("Humidity: ");
  Serial.print(currentHum/100);
  Serial.print("%\n");

  delay(2000);
}

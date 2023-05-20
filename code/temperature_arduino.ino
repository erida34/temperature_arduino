/*
  LiquidCrystal Library - Hello World

 Demonstrates the use a 16x2 LCD display.  The LiquidCrystal
 library works with all LCD displays that are compatible with the
 Hitachi HD44780 driver. There are many of them out there, and you
 can usually tell them by the 16-pin interface.

 This sketch prints "Hello World!" to the LCD
 and shows the time.

  The circuit:
 * LCD RS pin to digital pin 12
 * LCD Enable pin to digital pin 11
 * LCD D4 pin to digital pin 5
 * LCD D5 pin to digital pin 4
 * LCD D6 pin to digital pin 3
 * LCD D7 pin to digital pin 2
 * LCD R/W pin to ground
 * LCD VSS pin to ground
 * LCD VCC pin to 5V
 * 10K resistor:
 * ends to +5V and ground
 * wiper to LCD VO pin (pin 3)

 Library originally added 18 Apr 2008
 by David A. Mellis
 library modified 5 Jul 2009
 by Limor Fried (http://www.ladyada.net)
 example added 9 Jul 2009
 by Tom Igoe
 modified 22 Nov 2010
 by Tom Igoe
 modified 7 Nov 2016
 by Arturo Guadalupi

 This example code is in the public domain.

 http://www.arduino.cc/en/Tutorial/LiquidCrystalHelloWorld

*/

// include the library code:
#include <LiquidCrystalRus.h>
#include <dht11.h>
#define DHT11PIN 7

dht11 DHT11;

// initialize the library by associating any needed LCD interface pin
// with the arduino pin number it is connected to
const int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2;
LiquidCrystalRus lcd(rs, en, d4, d5, d6, d7);
byte customCharP[8] = {
  B11111,
  B10001,
  B10001,
  B10001,
  B10001,
  B10001,
  B10001,
  B00000};
byte customCharY[8] = {
  B10001,
  B10001,
  B01010,
  B00110,
  B00100,
  B01000,
  B10000,
  B00000};

byte customCharL[8] = {
  B00111,
  B01001,
  B01001,
  B01001,
  B01001,
  B01001,
  B11001,
  B00000};
byte customCharJ[8] = {
  B10101,
  B10101,
  B10101,
  B01110,
  B10101,
  B10101,
  B10101,
  B00000};

void setup() {
  // set up the LCD's number of columns and rows:
  lcd.begin(16, 2);
  Serial.begin(9600);
  lcd.createChar(0, customCharP);
  lcd.createChar(1, customCharY);
  lcd.createChar(2, customCharL);
  lcd.createChar(3, customCharJ);
}

void loop() {
  // set the cursor to column 0, line 1
  // (note: line 1 is the second row, since counting begins with 0):
  lcd.setCursor(0, 0);

  int chk = DHT11.read(DHT11PIN);
  lcd.print("ТЕМ");
  lcd.write(byte(0));
  lcd.print("ЕРАТ");
  lcd.write(byte(1));
  lcd.print("РА:");
  lcd.print((float)DHT11.temperature, 0);

  lcd.setCursor(0, 1);
  lcd.print("В");
  lcd.write(byte(2));
  lcd.print("А");
  lcd.write(byte(3));
  lcd.print("НОСТЬ:");
  lcd.print((float)DHT11.humidity, 0);
  
  delay(1);
}

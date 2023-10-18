/*---------------------------------------------------*/
/* Автомат поддержания верхней температуры в теплице */
/* author : Abdurazakov Oleg          <olab@email.su>*/
/*---------------------------------------------------*/

/*
  LiquidCrystal Library 

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
#define VERSION 2-02.6
#define DEBUG true

// include the library code:
#include "DHT.h"
#include "Narcoleptic.h"
#include "kiril_lcd.h"
#include <LiquidCrystal.h>

// initialize the library by associating any needed LCD interface pin
// with the arduino pin number it is connected to
const char rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

/* add sensor t/h
  DHT11:
    1->Vcc=5V
    2->signal
    3-nil
    4->GND
    */
#define DHTPIN 7
#define DHTTYPE DHT11
DHT dht(DHTPIN, DHTTYPE);

#define RELEPIN 13
float t_wentilator=35;
const char *test="--test--";


void setup() {
  // set up the LCD's number of columns and rows:
  lcd.begin(16, 2);
  lcd.clear();
  lcd.createChar(0,bo);
  lcd.createChar(1,bl);
  lcd.createChar(2,bu);
  lcd.createChar(3,bii);
  lcd.createChar(4,btsh);
  lcd.createChar(5,bz);
  lcd.createChar(6,byy);
  lcd.createChar(7,bd);

  dht.begin();
  pinMode(RELEPIN,OUTPUT);

  if (DEBUG) {Serial.begin(9600);};
  
  /* --test--*/
  if (DEBUG) {Serial.println(test);};
  lcd.setCursor(0,0);
  lcd.print(test);
  digitalWrite(RELEPIN,HIGH);
  Narcoleptic.delay(2000);
  digitalWrite(RELEPIN,LOW);
  lcd.clear();
  lcd.write(byte(5));
  lcd.write(byte(7));
  lcd.print("PABCTB");
  lcd.write(byte(2));
  lcd.write(byte(3));
  lcd.print("TE !");
  Narcoleptic.delay(10000);
  lcd.clear();

}

void loop() {
  // Reading temperature or humidity takes about 250 milliseconds!
  // Sensor readings may also be up to 2 seconds 'old' (its a very slow sensor)
  float h = dht.readHumidity();
  // Read temperature as Celsius (the default)
  float t = dht.readTemperature();
  // Read temperature as Fahrenheit (isFahrenheit = true)
 // float f = dht.readTemperature(true);
  // Check if any reads failed and exit early (to try again).
  if (isnan(h) || isnan(t) ){ // || isnan(f)) {
    if (DEBUG) {Serial.println(F("Failed to read from DHT sensor!"));};
    lcd.print("Failed to read from DHT sensor!");
    };
  
  lcd.print("T=");lcd.print(t);lcd.write(byte(0));lcd.print(" ");
  if (DEBUG) {Serial.println(t);};
  lcd.print("To=");lcd.print(t_wentilator);
  lcd.setCursor(0, 1);
  lcd.print("B=");lcd.print((int)h);lcd.print("%");   
  if (DEBUG) {Serial.println(h);};

  if (t>t_wentilator) {
    lcd.print("  BK");lcd.write(byte(1));
    digitalWrite(RELEPIN,HIGH);
  }else{
    lcd.print(" OTK");lcd.write(byte(1));
    digitalWrite(RELEPIN,LOW);
  }
  
  lcd.home();
  Narcoleptic. delay(2000);
}

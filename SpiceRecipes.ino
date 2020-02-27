  
/**
 * @SpiceRecipes.ino
 *
 * Automated Spice Recipe maker using Arduino Uno which measures weight using a load cell and HX711 load cell amplifier
 * Interfaced via Blynk using ESP8266 Node MCU WiFi module
 * With sms feedback via GSM SIM900A module 
 * For 2 recipes with 9 ingredients
 * @version 1.0
 * @date 15-01-2019
 * @authors A. Sharma  and A. Saikia
 * @copyright Copyright (c) 2019 LSTOAA
 *
 */

#include <SoftwareSerial.h>

SoftwareSerial mySerial(35, 36); 
//connect Tx of gsm to pin 9 of arduino
//connect Rx of gsm to pin 10 of arduino

#inclclude "HX711.h"
#define calibration_factor -7050 //This value is obtained using the SparkFun_HX711_Calibration sketch
#define DOUT  12
#define CLK 13

HX711 scale(DOUT, CLK);

void setup() {
  Serial.begin(9600);
  mySerial.begin(9600);//initialising arduino board
  mySerial.println("AT+CMGF=1"); // set SMS mode to text
  delay(200);
  mySerial.println("AT+CNMI=2,2,0,0"); // set module to send SMS data to serial out upon receipt

  pinMode(2, INPUT); //read pins from NodeMCU
  pinMode(3, INPUT);
  pinMode(4, INPUT);
  pinMode(5, INPUT);
  pinMode(6, INPUT);
  pinMode(7, INPUT);
  pinMode(8, INPUT);
  pinMode(9, INPUT);
  pinMode(10, INPUT);
  pinMode(11, INPUT);

  scale.set_scale(calibration_factor);
  scale.tare();

  pinMode(24, OUTPUT);
  pinMode(25, OUTPUT);
  pinMode(26, OUTPUT);
  pinMode(27, OUTPUT);
  pinMode(28, OUTPUT);
  pinMode(29, OUTPUT);
  pinMode(30, OUTPUT);
  pinMode(31, OUTPUT);
  pinMode(32, OUTPUT);
  pinMode(33, OUTPUT);


  digitalWrite(24, HIGH);
  digitalWrite(25, HIGH);
  digitalWrite(26, HIGH);
  digitalWrite(27, HIGH);
  digitalWrite(28, HIGH);
  digitalWrite(29, HIGH);
  digitalWrite(30, HIGH);
  digitalWrite(31, HIGH);
  digitalWrite(32, HIGH);
  digitalWrite(33, HIGH);
  delay(5000);
}


void loop() {
  /*1st Recipe*/
  //Replace XXX with desired quantity (in grams)
  if (digitalRead(2) == HIGH) {           
    while ((scale.get_units() * 65.5) < XXX) {     //weight for Cumin XXXgm Hopper 1st recipe
      digitalWrite(24, LOW);
    }
    digitalWrite(24, HIGH);
    delay(1500);
    float a = (scale.get_units() * 65.5);
    delay(500);
    scale.tare();
    delay(1500);
    while ((scale.get_units() * 65.5) < xxx) {    //weight for garam masala xxxgm Hopper 1st recipe
      digitalWrite(26, LOW);
    }
    digitalWrite(26, HIGH);
    delay(1500);
    float c = (scale.get_units() * 65.5);
    delay(1500);
    scale.tare();
    delay(1500);
    while ((scale.get_units() * 65.5) < xxx) {    //weight for Coriander xxxgm Hopper 1st recipe
      digitalWrite(27, LOW);
    }
    digitalWrite(27, HIGH);
    delay(1500);
    float d = (scale.get_units() * 65.5);
    delay(1500);
    scale.tare();
    delay(1500);
    while ((scale.get_units() * 65.5) < xxx) {    //weight for Degi mirch xxx gm Hopper 1st recipe
      digitalWrite(28, LOW);
    }
    digitalWrite(28, HIGH);
    delay(1500);
    float e = (scale.get_units() * 65.5);
    delay(1500);
    scale.tare();
    delay(1500);
    while ((scale.get_units() * 65.5) < xxx) {    //weight for Mix Masala xxxgm Hopper 1st recipe
      digitalWrite(29, LOW);
    }
    digitalWrite(29, HIGH);
    delay(1500);
    float f = (scale.get_units() * 65.5);
    delay(1500);
    scale.tare();
    delay(1500);
    while ((scale.get_units() * 65.5) < xxx) {    //weight for Red Chili xxxgm Hopper 1st recipe
      digitalWrite(30, LOW);
    }
    digitalWrite(30, HIGH);
    delay(1500);
    float g = (scale.get_units() * 65.5);
    delay(1500);
    scale.tare();
    delay(1500);
    while ((scale.get_units() * 65.5) < xxx) {    //weight for Ajwain xxxgm Hopper 1st recipe
      digitalWrite(33, LOW);
    }
    digitalWrite(33, HIGH);
    delay(1500);
    float j = (scale.get_units() * 65.5);
    delay(1500);
    scale.tare();
    delay(1500);
    float t = (a + c + d + e + f + g + j);
     mySerial.println("AT+CMGF=1");    //Sets the GSM Module in Text Mode
  delay(1000);  // Delay of 1000 milli seconds or 1 second
  mySerial.println("AT+CMGS=\"+91XXXXXXXXXX\"\r"); // Replace X with mobile number
  delay(1000);
  mySerial.print("Cumin=");
  mySerial.println(a);
  mySerial.print("Garam Masala=");
  mySerial.println(c);
  mySerial.print("Coriander=");
  mySerial.println(d);
  mySerial.print("Degi=");
  mySerial.println(e);
  mySerial.print("MIX=");
  mySerial.println(f);
  mySerial.print("Red Chili=");
  mySerial.println(g);
  mySerial.print("Ajwain=");
  mySerial.println(j);
  mySerial.print("Total=");
  mySerial.println(t);
  delay(100);
  mySerial.println((char)26);// ASCII code of CTRL+Z
  delay(12000);
  mySerial.println("AT+CMGF=1");    //Sets the GSM Module in Text Mode
  delay(1000);  // Delay of 1000 milli seconds or 1 second
  mySerial.println("AT+CMGS=\"+91XXXXXXXXXX\"\r"); // Replace X with mobile number
  delay(1000);
  mySerial.print("Cumin=");
  mySerial.println(a);
  mySerial.print("Garam Masala=");
  mySerial.println(c);
  mySerial.print("Coriander=");
  mySerial.println(d);
  mySerial.print("Degi=");
  mySerial.println(e);
  mySerial.print("MIX=");
  mySerial.println(f);
  mySerial.print("Red Chili=");
  mySerial.println(g);
  mySerial.print("Ajwain=");
  mySerial.println(j);
  mySerial.print("Total=");
  mySerial.println(t);
  delay(100);
  mySerial.println((char)26);// ASCII code of CTRL+Z
  delay(1000);
  }

  /*2nd Recipe*/
  else if (digitalRead(3) == HIGH) {
    while ((scale.get_units() * 65.5) < xxx) {     //weight for Cumin xxxgm Hopper 2nd recipe
      digitalWrite(24, LOW);
    }
    digitalWrite(24, HIGH);
    delay(1500);
    float a = (scale.get_units() * 65.5);
    delay(500);
    scale.tare();
    delay(1500);
    while ((scale.get_units() * 65.5) < xxx) {     //weight for salt xxxgm Hopper 2nd recipe
      digitalWrite(25, LOW);
    }
    digitalWrite(25, HIGH);
    delay(1500);
    float b = (scale.get_units() * 65.5);
    delay(1500);
    scale.tare();
    delay(1500);
    while ((scale.get_units() * 65.5) < xxx) {    //weight for garam masala xxxgm Hopper 2nd recipe
      digitalWrite(26, LOW);
    }
    digitalWrite(26, HIGH);
    delay(1500);
    float c = (scale.get_units() * 65.5);
    delay(1500);
    scale.tare();
    delay(1500);
    while ((scale.get_units() * 65.5) < xxx) {    //weight for Coriander xxxgm Hopper 2nd recipe
      digitalWrite(27, LOW);
    }
    digitalWrite(27, HIGH);
    delay(1500);
    float d = (scale.get_units() * 65.5);
    delay(1500);
    scale.tare();
    delay(1500);
    while ((scale.get_units() * 65.5) < xxx) {    //weight for Degi mirch xxxgm Hopper 2nd recipe
      digitalWrite(28, LOW);
    }
    digitalWrite(28, HIGH);
    delay(1500);
    float e = (scale.get_units() * 65.5);
    delay(1500);
    scale.tare();
    delay(1500);
    while ((scale.get_units() * 65.5) < xxx) {    //weight for Mix Masala xxxgm Hopper 2nd recipe
      digitalWrite(29, LOW);
    }
    digitalWrite(29, HIGH);
    delay(1500);
    float f = (scale.get_units() * 65.5);
    delay(1500);
    scale.tare();
    delay(1500);
    while ((scale.get_units() * 65.5) < xxx) {    //weight for Red Chili xxxgm Hopper 2nd recipe
      digitalWrite(30, LOW);
    }
    digitalWrite(30, HIGH);
    delay(1500);
    float g = (scale.get_units() * 65.5);
    delay(1500);
    scale.tare();
    delay(1500);
    while ((scale.get_units() * 65.5) < xxx) {    //weight for Turmeric xxxgm Hopper 2nd recipe
      digitalWrite(31, LOW);
    }
    digitalWrite(31, HIGH);
    delay(1500);
    float h = (scale.get_units() * 65.5);
    delay(1500);
    scale.tare();
    delay(1500);
    while ((scale.get_units() * 65.5) < xxx) {    //weight for Cashew xxxgm Hopper 2nd recipe
      digitalWrite(32, LOW);
    }
    digitalWrite(32, HIGH);
    delay(1500);
    float i = (scale.get_units() * 65.5);
    delay(1500);
    scale.tare();
    delay(1500);
    while ((scale.get_units() * 65.5) < xxx) {    //weight for Ajwain xxxgm Hopper 2nd recipe
      digitalWrite(33, LOW);
    }
    digitalWrite(33, HIGH);
    delay(1500);
    float j = (scale.get_units() * 65.5);
    delay(1500);
    scale.tare();
    delay(1500);
    float t = (a + b + c + d + e + f + g + h + i + j);
     mySerial.println("AT+CMGF=1");    //Sets the GSM Module in Text Mode
  delay(1000);  // Delay of 1000 milli seconds or 1 second
  mySerial.println("AT+CMGS=\"+91XXXXXXXXXX\"\r"); // Replace XXX with mobile number
  delay(1000);
  mySerial.print("Cumin=");
  mySerial.println(a);
  mySerial.print("Salt=");
  mySerial.println(b);
  mySerial.print("Garam Masala=");
  mySerial.println(c);
  mySerial.print("Coriander=");
  mySerial.println(d);
  mySerial.print("Degi=");
  mySerial.println(e);
  mySerial.print("MIX=");
  mySerial.println(f);
  mySerial.print("Red Chili=");
  mySerial.println(g);
  mySerial.print("Turmeric=");
  mySerial.println(h);
  mySerial.print("Cashew=");
  mySerial.println(i);
  mySerial.print("Ajwain=");
  mySerial.println(j);
  mySerial.print("Total=");
  mySerial.println(t);
  delay(100);
  mySerial.println((char)26);// ASCII code of CTRL+Z
  delay(12000);
  mySerial.println("AT+CMGF=1");    //Sets the GSM Module in Text Mode
  delay(1000);  // Delay of 1000 milli seconds or 1 second
  mySerial.println("AT+CMGS=\"+91XXXXXXXXXX\"\r"); // Replace X with mobile number
  delay(1000);
  mySerial.print("Cumin=");
  mySerial.println(a);
  mySerial.print("Salt=");
  mySerial.println(b);
  mySerial.print("Garam Masala=");
  mySerial.println(c);
  mySerial.print("Coriander=");
  mySerial.println(d);
  mySerial.print("Degi=");
  mySerial.println(e);
  mySerial.print("MIX=");
  mySerial.println(f);
  mySerial.print("Red Chili=");
  mySerial.println(g);
  mySerial.print("Turmeric=");
  mySerial.println(h);
  mySerial.print("Cashew=");
  mySerial.println(i);
  mySerial.print("Ajwain=");
  mySerial.println(j);
  mySerial.print("Total=");
  mySerial.println(t);
  delay(100);
  mySerial.println((char)26);
  delay(1000);
  }
   else {
    digitalWrite(24, HIGH);
    digitalWrite(25, HIGH);
    digitalWrite(26, HIGH);
    digitalWrite(27, HIGH);
    digitalWrite(28, HIGH);
    digitalWrite(29, HIGH);
    digitalWrite(30, HIGH);
    digitalWrite(31, HIGH);
    digitalWrite(32, HIGH);
    digitalWrite(33, HIGH);
    delay(5000);
    scale.tare();
  }
 }

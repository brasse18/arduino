/********************************************************************/
// First we include the libraries
#include <OneWire.h> 
#include <DallasTemperature.h>
/********************************************************************/
// Data wire is plugged into pin 2 on the Arduino 
#define ONE_WIRE_BUS 2
#define LED 13
#define PRODJEKTOR 10
#define SLEEPBUTTON 7
/********************************************************************/
// Setup a oneWire instance to communicate with any OneWire devices  
// (not just Maxim/Dallas temperature ICs) 
OneWire oneWire(ONE_WIRE_BUS); 
/********************************************************************/
// Pass our oneWire reference to Dallas Temperature. 
DallasTemperature sensors(&oneWire);
/********************************************************************/ 
int incomingByte = 0;
bool ledOn = false;
bool prodjektorOn = false;
bool sleepOn = false;
void setup(void) 
{ 
 // start serial port 
 Serial.begin(9600);  
 // Start up the library 
 sensors.begin(); 
 pinMode(LED, OUTPUT);
 pinMode(PRODJEKTOR, INPUT);
 pinMode(SLEEPBUTTON, INPUT);
} 
void loop(void) 
{ 
    if (Serial.available() > 0) {
    // read the incoming byte:
    incomingByte = Serial.read();

    // say what you got:
    //Serial.print("I received: ");
    //Serial.println(incomingByte, DEC);
        if (incomingByte == 49)
        {
          digitalWrite(LED, HIGH);
          ledOn = true;
        }
        if (incomingByte == 48)
        {
          digitalWrite(LED, LOW);
          ledOn = false;
        }
  }
  if (digitalRead(PRODJEKTOR) == HIGH) {
      prodjektorOn = true;
  } else {
      prodjektorOn = false;
  }
  if (digitalRead(SLEEPBUTTON) == HIGH) {
      sleepOn = true;
  } else {
      sleepOn = false;
  }
 // call sensors.requestTemperatures() to issue a global temperature 
 // request to all devices on the bus 
/********************************************************************/
 //Serial.print(" Requesting temperatures..."); 
 sensors.requestTemperatures(); // Send the command to get temperature readings 
 //Serial.println("DONE"); 
/********************************************************************/
 //Serial.print("Temperature is: "); 
 Serial.print(sensors.getTempCByIndex(0)); // Why "byIndex"?
 Serial.print(",");
 Serial.print(ledOn);
 Serial.print(",");
 Serial.print(prodjektorOn);
 Serial.print(",");
 Serial.println(sleepOn);
 
} 

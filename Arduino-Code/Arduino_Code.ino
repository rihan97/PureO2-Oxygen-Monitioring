

// these constants won't change:
const int ledPin = 13;      // LED connected to digital pin 13
const int knockSensor1 = A0; // chin 
const int knockSensor2 = A1;
const int knockSensor3 = A2;
const int threshold = 100;  // threshold value to decide when the detected sound is a knock or not

// these variables will change:
int piezoSensorC = 0;      // variable to store the value read from the sensor pin
int piezoSensorL = 0;  
int piezoSensorR = 0;  
int ledState = LOW;         // variable used to store the last LED status, to toggle the light

float lyFrontXmin = -0.2; 
float lyFrontXmax = 0.6; 
float lyFrontYmin = -8.2; 
float lyFrontYmax = -10.10; 
float lyFrontZmin = 1.4; 
float lyFrontZmax = 2.8;

float lyLeftXmin = -9.0; 
float lyLeftXmax = -10.7; 
float lyLeftYmin = -1.2; 
float lyLeftYmax = -2.2; 
float lyLeftZmin = -0.1; 
float lyLeftZmax = -1.5; 

float lyRightXmin = 8.5; 
float lyRightXmax = 10.2; 
float lyRightYmin = -0.2; 
float lyRightYmax = -1.8; 
float lyRightZmin = 1.4; 
float lyRightZmax = 2.8; 

float sitFrontXmin = 0.1;
float sitFrontXmax = 0.8;
float sitFrontYmin = 0.2;
float sitFrontYmax = 1.3;
float sitFrontZmin = 9.10;
float sitFrontZmax = 9.90;

float sitLeftXmin = 0.05;
float sitLeftXmax = 0.6;
float sitLeftYmin = 1.4;
float sitLeftYmax = 2.6;
float sitLeftZmin = 9.04;
float sitLeftZmax = 10.3;

float sitRightXmin = 1.1;
float sitRightXmax = 2.2;
float sitRightYmin = 0.2;
float sitRightYmax = 1.5;
float sitRightZmin = 9.0;
float sitRightZmax = 10.07;

#include <Wire.h>
#include <Adafruit_MMA8451.h>
#include <Adafruit_Sensor.h>

Adafruit_MMA8451 mma = Adafruit_MMA8451();

void setup() {
  
  pinMode(ledPin, OUTPUT); // declare the ledPin as as OUTPUT
  Serial.begin(9600);
  
  if (! mma.begin()) {
    Serial.println("Couldnt start");
    while (1);
  }
  Serial.println("MMA8451 found!");
  
  mma.setRange(MMA8451_RANGE_2_G);
  
  Serial.print("Range = "); Serial.print(2 << mma.getRange());  
  Serial.println("G");
}

void loop() {
  int CNY70 = analogRead(A3);

  Serial.println(CNY70);

  sensors_event_t event; 
  mma.getEvent(&event);
  
 piezoSensorC = analogRead(knockSensor1);
 piezoSensorL = analogRead(knockSensor2);
 piezoSensorR = analogRead(knockSensor3);
  // if the sensor reading is greater than the threshold:
  if (piezoSensorC >= threshold) {
    // toggle the status of the ledPin:
    ledState = !ledState;
    // update the LED pin itself:
    digitalWrite(ledPin, ledState);
    // send the string "Knock!" back to the computer, followed by newline
    Serial.println("chin");
  }
  if (piezoSensorL >= threshold) {
    // toggle the status of the ledPin:
    ledState = !ledState;
    // update the LED pin itself:
    digitalWrite(ledPin, ledState);
    // send the string "Knock!" back to the computer, followed by newline
    Serial.println("left");
  }

  if (piezoSensorR >= threshold) {
    // toggle the status of the ledPin:
    ledState = !ledState;
    // update the LED pin itself:
    digitalWrite(ledPin, ledState);
    // send the string "Knock!" back to the computer, followed by newline
    Serial.println("right");
  }
   // Nested if statement, check gyro then check piezo

  if (event.acceleration.x > lyFrontXmax && event.acceleration.x < lyFrontXmin){
  Serial.println("Alarm sounding! Front");
    if(piezoSensorC && piezoSensorL > 5){
       
    }
    if(piezoSensorC && piezoSensorR > 5){
      
    }
  }
  if (event.acceleration.x > lyLeftXmax && event.acceleration.x < lyLeftXmin){
  Serial.println("Alarm sounding! Left");
    if(piezoSensorL && piezoSensorC > 5){
       
    }
    if(piezoSensorL && piezoSensorR > 5){
    
  }
  }
  if (event.acceleration.x > lyRightXmax || event.acceleration.x < lyRightXmin){
  Serial.println("Alarm sounding! Right");
    if(piezoSensorR && piezoSensorC > 5){
       
    }
    if(piezoSensorR && piezoSensorL > 5){
      
    }
  }

  delay(50);  // delay to avoid overloading the serial port buffer

  mma.read();
  //Serial.print("X:\t"); Serial.print(mma.x); 
  //Serial.print("\tY:\t"); Serial.print(mma.y); 
  //Serial.print("\tZ:\t"); Serial.print(mma.z); 
  Serial.println();

  /* Get a new sensor event */ 
  //sensors_event_t event; 
  //mma.getEvent(&event);

  /* Display the results (acceleration is measured in m/s^2) */
  //Serial.print("X: \t"); Serial.print(event.acceleration.x); Serial.print("\t");
 // Serial.print("Y: \t"); Serial.print(event.acceleration.y); Serial.print("\t");
 // Serial.print("Z: \t"); Serial.print(event.acceleration.z); Serial.print("\t");
  //Serial.println("m/s^2 ");
  
  /* Get the orientation of the sensor */
  uint8_t o = mma.getOrientation();
  
  switch (o) {
    case MMA8451_PL_PUF: 
      Serial.println("Portrait Up Front");
      break;
    case MMA8451_PL_PUB: 
      Serial.println("Portrait Up Back");
      break;    
    case MMA8451_PL_PDF: 
      Serial.println("Portrait Down Front");
      break;
    case MMA8451_PL_PDB: 
      Serial.println("Portrait Down Back");
      break;
    case MMA8451_PL_LRF: 
      Serial.println("Landscape Right Front");
      break;
    case MMA8451_PL_LRB: 
      Serial.println("Landscape Right Back");
      break;
    case MMA8451_PL_LLF: 
      Serial.println("Landscape Left Front");
      break;
    case MMA8451_PL_LLB: 
      Serial.println("Landscape Left Back");
      break;
}
Serial.println();
  delay(250);
}  

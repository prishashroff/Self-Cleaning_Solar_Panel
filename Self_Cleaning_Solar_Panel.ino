#include <Servo.h>
// create servo object to control a servo 
Servo myservo;
// variable to store the servo position 
int pos = 0;

// Arduino pin numbers.
// Arduino digital pin 7 connect to sensor LED. 
const int sharpLEDPin = 7;
// Arduino analog pin 5 connect to sensor Vo.
const int sharpVoPin = A0;

// Set the typical output voltage in Volts when there is zero dust. 
static float Voc = 0.6;

// Use the typical sensitivity in units of V per 100ug/m3.
const float K = 0.5;

// Arduino setup function.
void setup() {
  // attaches the servo on pin 9 to the servo object 
  myservo.attach (9);
  // Set LED pin for output.
  pinMode (sharpLEDPin, OUTPUT);
  // Start the hardware serial port for the serial monitor.
  Serial.begin(9600);
  // Wait two seconds for startup.
  delay(2000);
}

// Arduino main loop.
void loop() {
  // Turn on the dust sensor LED by setting digital pin LOW.
  digitalWrite(sharpLEDPin, LOW);
  // Wait 0.28ms before taking a reading of the output voltage as per spec. 
  delayMicroseconds (280);
  // Record the output voltage. This operation takes around 100 microseconds. 
  int VoRaw = analogRead (sharpVoPin);
  // Turn the dust sensor LED off by setting digital pin HIGH. 
  digitalWrite(sharpLEDPin, HIGH);
  // Wait for remainder of the 10ms cycle = 10000 280 100 microseconds. 
  delayMicroseconds (9620);
  float Vo= VoRaw;
  
  // Compute the output voltage in Volts.
  Vo = Vo/ 1024.0 * 5.0;
  printFValue ("Vo", Vo*1000.0, "mV");
  // Convert to Dust Density in units of ug/m3.
  float dV = Vo - Voc;
  if (dv < 0) {
    dv = 0;
    Voc = Vo;
  }
  float dustDensity = dv / K * 100.0;
  printFValue ("DustDensity", dustDensity, "ug/m3", true);
  if (dust Density > 10) {
    // goes from 0 degrees to 180 degrees in steps of 1 degree
    for (pos= 0; pos <= 180; pos+= 1) { 
      // tell servo to go to position in variable 'pos'
      myservo.write(pos); 
      // waits 15ms for the servo to reach the position
      delay(5);
    }
  }
} 
// END PROGRAM

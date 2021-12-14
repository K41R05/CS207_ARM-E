//Broken down simplified code used for the testing of CS207 ARM-E (renamed NEO-ARM),
//Simplified from the understanding of CS207_emg_value_test
//Updated and altered by Mikha Aguilar for CS207 FALL 2021

#include <Servo.h>

//Threshold for servo motor control with muscle sensor. 
//You can set a threshold according to the maximum and minimum values of the muscle sensor.
//This is a defined range from  0 to 1023, due to the sensor's inconsistency I had to raise the threshold up
#define threshold 850

//Pin number where the sensor is connected. (Analog 3)
#define EMG_PIN 3

//Pin number where the servo motor is connected. (Digital PWM 3)
#define SERVO_PIN 3

//Define Servo motor
Servo MYSERVO;

void setup(){
  //Set servo motor to digital pin 3
  MYSERVO.attach(SERVO_PIN);
}

void loop(){
  //The "Value" variable reads the value from the analog pin to which the sensor is connected.
  int value = analogRead(EMG_PIN);

  //While this code is more basic, the idea would be to add continous different cases once a more accurate and stable
  //sensor has been acquired
  //Based on servo positioning we want the servo to move a certain way to tug our at our prosthesis fingers
  //writing degrees is opposite to what we want the servo to accomplish, since the positioning of the servo is
  //opposite to our ideal angle
  //If the sensor value is GREATER than the THRESHOLD, the servo motor will turn to 175 degree.
  if(value > threshold){
    MYSERVO.write(5);
  }

  //If the sensor is LESS than the THRESHOLD, the servo motor will turn to 5 degrees.
  else{
    MYSERVO.write(175);
  }
}

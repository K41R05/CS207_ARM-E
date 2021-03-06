//CS207_emg_value_test
//Initial Prototyping- practicing to understand how the servo motor works, based off the code developed by Walter Lee in
//his article: Unofficial Myoware Sensor Tutorial
//This was moreso used for displaying and keeping track of values
#include <Servo.h>    // Using the Servo library
Servo ThumbJoint;     // Naming our servo
int EMGsig;           // Store the EMG signal value
int servoPosition;    // The position (angle) value for the servo
int threshold = 150;  // Move the servo when EMG signal is above this threshold. Remember it ranges 0–1023.

void setup() {
 Serial.begin(9600); // Starting the communication with the computer
 ThumbJoint.attach(9); // Tell the servo it is plugged into pin 9
}

void loop() {
 EMGsig = analogRead(A0); // Read the analog values of the rectified+integrated EMG signal (0–1023)
 
 if (EMGsig < threshold){     // If EMG signal is below the threshold
    servoPosition = 00;       // Servo will remain at 20 degrees.
  } 
  else{            // If the EMG signal is above the threshold,
   servoPosition=map(EMGsig,threshold,1023,0,160); 
  // The servo angle will be mapped with the EMG signal, 
  // changing the range of 300(our threshold)-1023 into the range of 20-160 degrees.
  // 20 and 160 can be switched depending on which direction of rotation you want.
  } 

  ThumbJoint.write(servoPosition); 
    // Move the servo to the ‘servoPosition’ degree
   Serial.print(servoPosition);Serial.print("degrees, with EMG: ");Serial.println(EMGsig); 
    // Display the servo and EMG values.
   delay(20);
    //20ms delay to not cause it to move as frantically. But this can be adjusted as you like.
}

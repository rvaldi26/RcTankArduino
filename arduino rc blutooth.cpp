
/* Arduino Bluetooth Car
 * Created by Vasilakis Michalis // updated: 31/7/2019
 * More information at www.ardumotive.com
 */
#include <SoftwareSerial.h>
//Software serial connection for bt module
SoftwareSerial btSerial(A2,A3); // RX & TX

//L293 Connection   
const int motorA1  = 5;  // Pin  2 of L293
const int motorA2  = 3;  // Pin  7 of L293
const int motorB1  = 11; // Pin 10 of L293
const int motorB2  = 10;  // Pin 14 of L293
//Leds connected to Arduino UNO Pin 12
const int front_lights  = 8;
const int back_lights = 7;
//Buzzer / Speaker to Arduino UNO Pin 3
const int buzzer = 2 ;   

//Useful Variables
int i=0;
int j=0;
char state;

void setup() {
  // Initialize serial communication at 9600 bits per second:
  btSerial.begin(9600);
  Serial.begin(9600); // Only for debugging
  // Set pins as outputs:
  pinMode(motorA1, OUTPUT);
  pinMode(motorA2, OUTPUT);
  pinMode(motorB1, OUTPUT);
  pinMode(motorB2, OUTPUT);
  pinMode(front_lights, OUTPUT);
  pinMode(back_lights, OUTPUT);
  delay(500);
  //Stop all motors
  digitalWrite(motorA1, LOW);
  digitalWrite(motorA2, LOW);
  digitalWrite(motorB1, LOW);
  digitalWrite(motorB2, LOW);
}
 
void loop() {
  //Save income data to variable 'state'
    if(btSerial.available() > 0){     
      state = btSerial.read(); 
      Serial.println(state);  
    }	  
  /***********************Forward****************************/
  //If state is equal with letter 'F', car will go forward!
    if (state == 'F') {
    	digitalWrite(motorA1, HIGH); digitalWrite(motorA2, 0);
      digitalWrite(motorB1, 0);      digitalWrite(motorB2, 0); 
      Serial.println("Moving Forward");
    }
  /**********************Forward Left************************/
  //If state is equal with letter 'G', car will go forward left
    else if (state == 'G') {
    	digitalWrite(motorA1, HIGH); digitalWrite(motorA2, 0);  
      digitalWrite(motorB1, HIGH);    digitalWrite(motorB2, 0);
      Serial.println("Moving Forward Left"); 
    }
  /**********************Forward Right************************/
  //If state is equal with letter 'I', car will go forward right
    else if (state == 'I') {
      digitalWrite(motorA1, HIGH); digitalWrite(motorA2, 0); 
      digitalWrite(motorB1, 0);      digitalWrite(motorB2, HIGH); 
      Serial.println("Moving Forward Right");
    }
  /***********************Backward****************************/
  //If state is equal with letter 'B', car will go backward
    else if (state == 'B') {
    	digitalWrite(motorA1, 0);   digitalWrite(motorA2, HIGH); 
      digitalWrite(motorB1, 0);   digitalWrite(motorB2, 0); 
      Serial.println("Moving Backward");
    }
  /**********************Backward Left************************/
  //If state is equal with letter 'H', car will go backward left
    else if (state == 'H') {
    	digitalWrite(motorA1, 0);   digitalWrite(motorA2, HIGH); 
      digitalWrite(motorB1, HIGH); digitalWrite(motorB2, 0);
      Serial.println("Moving Backward Left"); 
    }
  /**********************Backward Right************************/
  //If state is equal with letter 'J', car will go backward right
    else if (state == 'J') {
    	digitalWrite(motorA1, 0);   digitalWrite(motorA2, HIGH); 
      digitalWrite(motorB1, 0);   digitalWrite(motorB2, HIGH); 
      Serial.println("Moving Backward Right");
    }
  /***************************Left*****************************/
  //If state is equal with letter 'L', wheels will turn left
    else if (state == 'L') {
    	digitalWrite(motorA1, 0);   digitalWrite(motorA2, 0); 
      digitalWrite(motorB1, HIGH); digitalWrite(motorB2, 0); 
      Serial.println("Turn Left");
    }
  /***************************Right*****************************/
  //If state is equal with letter 'R', wheels will turn right
    else if (state == 'R') {
    	digitalWrite(motorA1, 0);   digitalWrite(motorA2, 0); 
      digitalWrite(motorB1, 0);   digitalWrite(motorB2, HIGH); 
      Serial.println("Turn Right");		
    }
  /************************Lights*****************************/
  //If state is equal with letter 'W/w', turn front leds on or of off
    else if (state == 'W') {
      digitalWrite(front_lights, HIGH); 
      Serial.println("Turning front lights ON");
    }
    else if (state == 'w') {
      digitalWrite(front_lights, LOW); 
      Serial.println("Turning front lights OFF");
    }
  /************************Lights*****************************/
  //If state is equal with letter 'U/u', turn back leds on or of off
    else if (state == 'U') {
      digitalWrite(back_lights, HIGH); 
      Serial.println("Turning rear lights ON");
    }
    else if (state == 'u') {
      digitalWrite(back_lights, LOW); 
      Serial.println("Turning rear lights OFF");
    }  
  /**********************Horn sound***************************/
  //If state is equal with letter 'V', play (or stop) horn sound
    else if (state == 'V'){
      tone(buzzer,500);
      Serial.println("Playing horn sound");
    }
    else if (state == 'v'){
      noTone(buzzer);
      Serial.println("Stop playing horn sound");
    }
  /************************Stop*****************************/
  //If state is equal with letter 'S', stop the car
    else if (state == 'S'){
        digitalWrite(motorA1, 0);  digitalWrite(motorA2, 0); 
        digitalWrite(motorB1, 0);  digitalWrite(motorB2, 0);
        Serial.println("STOP");
    }  
}
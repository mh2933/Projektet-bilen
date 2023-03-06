/*
 Controlling a servo position using a potentiometer (variable resistor)
 by Michal Rinott <http://people.interaction-ivrea.it/m.rinott>

 modified on 8 Nov 2013
 by Scott Fitzgerald
 http://www.arduino.cc/en/Tutorial/Knob
*/
//This code is to control the speed of a DC motor by a potentiometer using l298n driver
//We read the value from the analog input, calibrate it then inject to the module
//Refer to Surtrtech youtube channel for more information
int in1 = 10; //Declaring where our module is wired
int in2 = 6;
int ConA = 11;// Don't forget this is a PWM DI/DO
int speed1;


#include <Servo.h>

Servo myservo;  // create servo object to control a servo

int potpin = 1;  // analog pin used to connect the potentiometer
int val;         // variable to read the value from the analog pin


void setup() {
  Serial.begin(9600);  

  pinMode(6, OUTPUT);
  pinMode(10, OUTPUT);  
  pinMode(11, OUTPUT);

  myservo.attach(9);  // attaches the servo on pin 9 to the servo object
}

void TurnMotorA(){ //We create a function which control the direction and speed
  digitalWrite(in1, LOW); //Switch between this HIGH and LOW to change direction
  digitalWrite(in2, HIGH);
  speed1 = analogRead(A0);
  speed1 = speed1*0.2492668622; //We read thea analog value from the potentiometer calibrate it
  analogWrite(ConA,speed1);// Then inject it to our motor
}

void servo()
{
  val = analogRead(potpin);         // reads the value of the potentiometer (value between 0 and 1023)
  val = map(val, 0, 1023, 0, 180);  // scale it to use it with the servo (value between 0 and 180)
  myservo.write(val);               // sets the servo position according to the scaled value
  delay(1);

  Serial.println(val);
  delay(1);  // waits for the servo to get there
}

void loop() {
TurnMotorA(); //one function that keeps looping you can add another one with different direction or stop
servo();
}
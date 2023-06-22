#include<Servo.h>

Servo myservo;

long t; // declaring variable for calculating time

long cm; //declaring variable for calculating distance
long duration;
int u = 1;
int pos = 0;
int r1=2,r2=3,r4=5,r5=11,r6=10;
const int trigPin = 13; // Trigger Pin of Ultrasonic Sensor
const int echoPin = 12; // Echo Pin of Ultrasonic Sensor
int IRSensor = 6; // connect ir sensor to arduino pin 2
void setup() {

  myservo.attach(r4);
  pinMode (IRSensor, INPUT); // sensor pin INPUT
  pinMode (r1, OUTPUT); //ir green
  pinMode (r2, OUTPUT); //ir red
  pinMode (r4, OUTPUT); //servo
  pinMode (r5, OUTPUT); // u-sonic green 
  pinMode (r6, OUTPUT); // u-sonic red
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  Serial.begin(9600);
  Serial.println("Welcome to Project");
}
void loop() {

  Serial.print("IR Sensor value=  ");
  Serial.println(digitalRead(IRSensor));

  int statusSensor = digitalRead (IRSensor);

  if(statusSensor == 1){
    digitalWrite(r1, HIGH);
    digitalWrite(r2, LOW);
    if (u==1){
      for (pos = 0;pos<=180;pos+=1){
          myservo.write(pos);
      }
      u = 0;
    }
    delay(50);
    
  }
  else{
    digitalWrite(r2, HIGH);
    digitalWrite(r1, LOW);
    if (u==0){
      for (pos = 180;pos>=0;pos-=1){
        myservo.write(pos);
      }
      u=1;
    }
        
      delay(50);
  }

  digitalWrite(trigPin, LOW);
  delayMicroseconds(10);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  duration = pulseIn(echoPin, HIGH);
  cm = duration*340/20000;
  Serial.println(cm);
  delay(500);
  if (cm > 20){
      digitalWrite(r5,HIGH);
      digitalWrite(r6,LOW);
      delay(10);
  }
  else{
        digitalWrite(r6,HIGH);
        digitalWrite(r5,LOW);
        delay(10);
  }

  
}

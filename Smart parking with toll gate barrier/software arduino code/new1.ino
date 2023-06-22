#include <Servo.h>

Servo myservo;
int pos = 0;
int r1=2,r2=3,r3=4,r4=5,r5=11,r6=10,r7=9;
const int trigPin = 13; // Trigger Pin of Ultrasonic Sensor
const int echoPin = 12; // Echo Pin of Ultrasonic Sensor
int IRSensor = 6; // connect ir sensor to arduino pin 2
int pc = 0;
void setup()
{
  myservo.attach(r4);
  pinMode (IRSensor, INPUT); // sensor pin INPUT
  pinMode (r1, OUTPUT);
  pinMode (r2, OUTPUT);
  pinMode (r3, OUTPUT);
  pinMode (r4, OUTPUT);
  pinMode (r5, OUTPUT);
  pinMode (r6, OUTPUT);
  pinMode (r7, OUTPUT);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  Serial.begin(9600);
  delay(500);
  Serial.println("Welcome to Project");
}

void loop()
{
//  pc = 0;
  long duration,cm;
  /*dis = time*speed/2
    speed of sound = 340 m/s
                     340*100/1000000 cm/microseconds
              dis = time * 340*100/1000000/2
              dis = time * 340/20000
    */

  delay(500);
  Serial.print("IR Sensor value=  ");
  Serial.println(digitalRead(IRSensor));

  digitalWrite(r3, HIGH);
  
  int statusSensor = digitalRead (IRSensor);

  if(statusSensor == 1){
    digitalWrite(r3, LOW);
    digitalWrite(r2, LOW);
    digitalWrite(r5,LOW);
    digitalWrite(r6,LOW);
    digitalWrite(r7,LOW); 
    digitalWrite(r1, HIGH); // LED LOW
    if (pc==0){
        for (pos = 0;pos<=180;pos+=1){
          myservo.write(pos);
      }
      pc = 1;
      delay(200); 
    }
  }
  else
  {
    if (pc==1){
      digitalWrite(r2, HIGH);
      digitalWrite(r1, LOW); // LED LOW
       for (pos = 180;pos>=0;pos-=1){
        myservo.write(pos);
      }
      pinMode(trigPin, OUTPUT);
      digitalWrite(trigPin, LOW);
      delayMicroseconds(2);
      digitalWrite(trigPin, HIGH);
      delayMicroseconds(10);
      digitalWrite(trigPin, LOW);
      pinMode(echoPin, INPUT);
      duration = pulseIn(echoPin, HIGH);
      cm = duration*340/20000;
      if (cm > 300){
        digitalWrite(r5,HIGH);
        digitalWrite(r6,LOW);
        digitalWrite(r7, HIGH);
      }
      else{
        digitalWrite(r6,HIGH);
        digitalWrite(r5,LOW);
        digitalWrite(r7, LOW);
      }
      delay(600); 
    }
    else{
     pc = 0;
     digitalWrite(r2, HIGH); // LED LOW
     digitalWrite(r1, LOW);
     digitalWrite(r5,LOW);
     digitalWrite(r6,LOW);
     delay(10);  
    }
  }
}

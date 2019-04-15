//Burak akgumus gomulu sitemler

#include <Servo.h>

const int trigPin = 7;
const int echoPin = 8;

long zaman;
int mesafe;
Servo myServo; 

void setup() {
  
  pinMode(trigPin, OUTPUT); 
  pinMode(echoPin, INPUT); 
  Serial.begin(9600);
  myServo.attach(9); 
}

void loop() {
  
  for(int i=15;i<=165;i++){  
  myServo.write(i);
  delay(30);
  mesafe = hesaplamesafe();
  
  Serial.print(i); 
  Serial.print(","); 
  Serial.print(mesafe); 
  Serial.print("."); 
  }
  
  for(int i=165;i>15;i--){  
  myServo.write(i);
  delay(30);
  
  mesafe = hesaplamesafe();
  
  Serial.print(i);
  Serial.print(",");
  Serial.print(mesafe);
  Serial.print(".");
  }
}

int hesaplamesafe() { 
  
  digitalWrite(trigPin, LOW); 
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH); 
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  zaman = pulseIn(echoPin, HIGH); 
  mesafe= zaman*0.034/2;
  return mesafe;
}
//enjoy!

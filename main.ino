#include <SoftwareSerial.h>
#include <Servo.h>
Servo servo;
int angle=120;
SoftwareSerial BT(2,3);
char data = 0;
void setup() {
  BT.begin(9600);
  Serial.begin(9600);
  servo.attach(8);
  servo.write(angle);
  //DC 모터 1
    pinMode(7,OUTPUT);
    pinMode(6,OUTPUT);
    //DC 모터 2
    pinMode(5,OUTPUT);
    pinMode(4,OUTPUT);
    //부저
    pinMode(9,OUTPUT);
//LED
    pinMode(10,OUTPUT);
    pinMode(11,OUTPUT);
}

void loop() {
  if(BT.available() > 0) {
    data = BT.read();
  }
  if(data == 'F'){
    Serial.println("전진");
        digitalWrite(6,HIGH);
        digitalWrite(7,LOW);
        digitalWrite(5,HIGH);
        digitalWrite(4,LOW);
  }
  if (data == 'R'){
    if (angle==160){
      angle=160;
      servo.write(angle);
    }
    else{
    angle=angle+10;
    Serial.println(angle);
    servo.write(angle);
    Serial.println("RIGHT");
    }
  }
  if (data=='L'){
    if (angle==80){
      angle=80;
      servo.write(angle);
    }
    else{
    angle=angle-10;
    Serial.println(angle);
    servo.write(angle);
    Serial.println("LEFT");
    }
  }
  if (data=='B'){
        digitalWrite(6,LOW);
        digitalWrite(7,HIGH);
        digitalWrite(5,LOW);
        digitalWrite(4,HIGH);
        tone(9,150,300);
  }
  if (data=='Q'){
      digitalWrite(7,LOW);
      digitalWrite(6,LOW);
      digitalWrite(5,LOW);
      digitalWrite(4,LOW);
  }
  if (data=='C'){
     tone(9,440);
     Serial.print("경적");
  }
  if (data=='Z'){
    noTone(9);
  }
  if (data=='Y'){
    digitalWrite(10,HIGH);
    digitalWrite(11,HIGH);
    Serial.print("전조등 ON");
  }
  if (data=='H'){
    digitalWrite(10,LOW);
    digitalWrite(11,LOW);
    Serial.print("전조등 OFF");
  }
  if (data=='I'){
    angle=120;
    servo.write(angle);
  }
  data = 0;
}

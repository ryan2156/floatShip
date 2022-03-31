#include <Servo.h>

Servo myservo;

void setup() {
  Serial.begin(9600);
  myservo.attach(5);

}

void loop() {
  // put your main code here, to run repeatedly:
  static int v = 92; //一定要92
  if(Serial.available()) {
    char ch = Serial.read();
    if(ch=='a') {
      v += 2;
      Serial.println("UP");
      Serial.println(v);
    }
    else if(ch=='v') {
      v -= 2;
      Serial.println("DOWN");
      Serial.println(v);
    }
  }
  myservo.write(v);
}

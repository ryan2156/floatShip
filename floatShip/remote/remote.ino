#include <Servo.h>

#define VrxPin 2
    
long RC_PWM[5];
Servo vertical;

void setup()
{
  
  pinMode(VrxPin, INPUT);
  vertical.attach(5);
  Serial.begin(9600);
  
}

void loop()
{
  static int v = 92;
  RC_PWM[5]=pulseIn(2,HIGH); 
  
  if(RC_PWM[5] > 1800){
    v = 92;
    Serial.println(v);
  }
  else if(RC_PWM[5] < 1000){
    v = 98;
    Serial.println(v);
  }
  else{
    v = 96;
    Serial.println(v);
  }
  vertical.write(v);
}

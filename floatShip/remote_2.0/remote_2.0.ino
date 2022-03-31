#include <Servo.h>

#define ch5 2 //頻道5接收垂直動力
#define ch3 3 //頻道3接收水平動力
    
long RC_PWM[6];  //總共6個頻道

Servo vertical;  //垂直無刷馬達(ch5控制)
Servo level; //水平無刷馬達(ch3控制)

void setup()
{
  
  pinMode(ch3, INPUT);
  pinMode(ch5, INPUT);
  
  vertical.attach(5); //垂直馬達輸出 D5
  level.attach(6);  //什麼水平馬達輸出 D6
  
  Serial.begin(9600);
  
}

void loop()
{
  static int v = 92; //牙刷馬達不轉的值
  RC_PWM[5] = pulseIn(ch5,HIGH);
  RC_PWM[3] = pulseIn(ch3,HIGH);
  
  v = Simulate_5(RC_PWM[5]); //模擬輸出PWM的值(ch5)
  int l = map(RC_PWM[3], 1056, 2054, 94, 102);
  
  Serial.println("水平動力：");
  Serial.println(RC_PWM[3]);
  Serial.println(map(RC_PWM[3], 1056, 2054, 92, 102));
  
  vertical.write(v);
  level.write(l);
}

int Simulate_5(int x){
  int z;
  switch(x/100){
    case 19: //停
      z = 92;
      break;
    case 14: //中
      z = 96;
      break;
    case 9: //快
      z = 98;
      break;
    default:
      z = 92;
      break;
  }
  return z;
}

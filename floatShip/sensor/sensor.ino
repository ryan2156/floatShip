#define rxPin 2

long RC_PWM[3];

void setup()
{
  // define pin modes for Software Serial
  pinMode(rxPin, INPUT);
  
  // Setup the data rate for Serial ports
  Serial.begin(9600);
  
}

void loop()
{

  RC_PWM[3]=pulseIn(2,HIGH); // read pulse width from pin 4
  
  Serial.println(RC_PWM[3]);
  
  delay(10);
}

#include <Stepper.h>
#include <Servo.h>

int pinoSensor = A0;
int valorSensor = 0;
 
const int stepsPerRevolution = 200; 

#define SERVO 7
 
Servo s; 

Stepper myStepper(stepsPerRevolution, 8, 10, 9, 11);

int stepCount = 0;  // number of steps the motor has taken

void setup() 
{
  s.attach(SERVO);
  Serial.begin(9600);
  s.write(120);
}

void loop() 
{
   myStepper.setSpeed(100);

  myStepper.step(-620);
  delay(1000); 

  valorSensor = analogRead(pinoSensor);
  valorSensor = map(valorSensor, 0, 1024, 0, 10);
  delay(100);

  Serial.println(valorSensor);
  delay(1000);

  if(valorSensor > 0 && valorSensor <= 5)
  {
    s.write(100);
    delay(200);
    myStepper.step(-180);
    delay(100);
  }
  else 
  {
   s.write(170);
   delay(200);
   myStepper.step(-180); 
   delay(100);
  }
   
  myStepper.step(800);
  delay(1000); 
}

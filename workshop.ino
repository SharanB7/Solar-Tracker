

#include <Servo.h>

Servo myservo1;
Servo myservo2;   
int ldr1 = A0; 
int ldr2 = A1;
int ldr3 = A2; 
int ldr4 = A3;
int val1;
int val2;
int val3;
int val4;  
int pos1=90;
int pos2=90;
int sen = 20;
int del = 100;

void setup() 
{
  myservo1.attach(11); 
  Serial.begin(9600);
  myservo1.write(pos1);
  myservo2.attach(10); 
  Serial.begin(9600);
  myservo2.write(pos2);   
}

 
    
void loop() 
{
  val1 = analogRead(ldr1);            
  val2 = analogRead(ldr2);
  val3 = analogRead(ldr3);
  val4 = analogRead(ldr4);
  val1 = map(val1, 0, 1023, 0, 180);
  val2 = map(val2, 0, 1023, 0, 180);     
  val3 = map(val3, 0, 1023, 0, 180);
  val4 = map(val4, 0, 1023, 0, 180);  
  Serial.println(val1);
  Serial.println(val2);
  Serial.println(val3);
  Serial.println(val4);   
  if(val1 < (val2+sen))
  { 
    if((val2+sen-val1) > 10)
      {
      if(pos1<120)
        pos1=pos1+1;
      myservo1.write(pos1);
      Serial.println("backward");         
      delay(del);
      }         
  }
  else if(val2 < (val1+sen))
  {
    if((val1+sen-val2) > 10)
      {
      if(pos1>60)
        pos1=pos1-1;
      myservo1.write(pos1);
      Serial.println("forward");         
      delay(del); 
      }
  }
  if(val3 > (val4+sen))
  { 
  
      if(pos2<150)
        pos2=pos2+1;
      myservo2.write(pos2);
      Serial.println("right");         
      delay(del);         
      
  }
  else if(val4 > (val3+sen))
  {
    
      if(pos2>30)
        pos2=pos2-1;
      myservo2.write(pos2);
      Serial.println("left");         
      delay(del); 
     
  }
                     
}

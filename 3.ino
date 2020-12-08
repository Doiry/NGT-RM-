#include <AFMotor.h>
#include <Servo.h>
#define Sensor5 A4
#define Sensor3 A0
#define Sensor1 A1
#define Sensor2 A2
#define Sensor4 A3
#define juli A5
#define Speed1 140
#define Speed2 100
#define Speed3 50
#define Speed4 0
int sensor1=0,sensor2=0,sensor3=0,sensor4=0,sensor5=0,juliValue=0;
int adj_1=0,adj_2=0,adj_3=0,adj_4=0,adj_5=0;
int s1_min=600,s1_max=900;
int s2_min=600,s2_max=900;
int s3_min=600,s3_max=900;
int s4_min=0,s4_max=1000;
int s5_min=0,s5_max=1000;
int b=180;//定义黑色值
int m=170;//定义中间值
int w=210;//定义白色值
Servo Servo1;
Servo Servo2;
AF_DCMotor Motor1(1,MOTOR12_1KHZ);
AF_DCMotor Motor2(2,MOTOR12_1KHZ);
AF_DCMotor Motor3(3,MOTOR12_1KHZ);
AF_DCMotor Motor4(4,MOTOR12_1KHZ);
void GO()
{
    Motor1.setSpeed(Speed2-20);
    Motor2.setSpeed(Speed2-20);
    Motor3.setSpeed(Speed2-20);
    Motor4.setSpeed(Speed2-20);
      Motor1.run(FORWARD);
      Motor2.run(FORWARD);
      Motor3.run(FORWARD);
      Motor4.run(FORWARD);
      delay(100);
  }
void setup() 
{
  Serial.begin(9600);
  Servo1.attach(9);
  Servo2.attach(10);
  Motor1.setSpeed(Speed2-30);
  Motor2.setSpeed(Speed2-30);
  Motor3.setSpeed(Speed2-30);
  Motor4.setSpeed(Speed2-30);
  Motor1.run(RELEASE);
  Motor2.run(RELEASE);
  Motor3.run(RELEASE);
  Motor4.run(RELEASE);
  
}

void update_sensors()
{
  sensor1=analogRead(Sensor1);
  adj_1=map(sensor1,s1_min,s1_max,0,255);
  adj_1=constrain(adj_1,0,255);
  sensor2=analogRead(Sensor2);
  adj_2=map(sensor2,s2_min,s2_max,0,255);
  adj_2=constrain(adj_2,0,255);
  sensor3=analogRead(Sensor3);
  adj_3=map(sensor3,s3_min,s3_max,0,255);
  adj_3=constrain(adj_3,0,255);
  sensor4=analogRead(Sensor4);
  adj_4=map(sensor4,s4_min,s4_max,0,255);
  adj_4=constrain(adj_4,0,255);
  sensor5=analogRead(Sensor5);
  adj_5=map(sensor5,s5_min,s5_max,0,255);
  adj_5=constrain(adj_5,0,255);
  juliValue=analogRead(juli);
  Serial.print(adj_4);
  Serial.print("\t");
  Serial.print(adj_3);
  Serial.print("\t");
  Serial.print(adj_1);
  Serial.print("\t");
  Serial.print(adj_2);
  Serial.print("\t");
  Serial.print(adj_5);
  Serial.print("\t");
  Serial.println(juliValue);
delay(50);
}
  void BACK()
  {
    Motor1.setSpeed(Speed2);
    Motor2.setSpeed(Speed2);
    Motor3.setSpeed(Speed2);
    Motor4.setSpeed(Speed2);
      Motor1.run(BACKWARD);
      Motor2.run(BACKWARD);
      Motor3.run(BACKWARD);
      Motor4.run(BACKWARD);
       delay(1000);
    }
  void LEFT()
  {
    Motor1.setSpeed(Speed2);
    Motor2.setSpeed(Speed2);
    Motor3.setSpeed(Speed2+20);
    Motor4.setSpeed(Speed2+20);
    Motor1.run(FORWARD);
    Motor2.run(FORWARD);
    Motor3.run(FORWARD);
    Motor4.run(FORWARD);
   delay(100);
    }
  void RIGHT()
  {
    Motor1.setSpeed(Speed2+20);
    Motor2.setSpeed(Speed2+20);
    Motor3.setSpeed(Speed2);
    Motor4.setSpeed(Speed2);
    Motor1.run(FORWARD);
    Motor2.run(FORWARD);
    Motor3.run(FORWARD);
    Motor4.run(FORWARD);
      delay(100);
      }
   void BIGLEFT()
  {
    
    Motor1.setSpeed(Speed2);
    Motor2.setSpeed(Speed2);
    Motor3.setSpeed(Speed2);
    Motor4.setSpeed(Speed2);
    Motor1.run(BACKWARD);
    Motor2.run(BACKWARD);
    Motor3.run(FORWARD);
    Motor4.run(FORWARD);
  
    }
     void BIGRIGHT()
  {
   
    Motor1.setSpeed(Speed2);
    Motor2.setSpeed(Speed2);
    Motor3.setSpeed(Speed2);
    Motor4.setSpeed(Speed2);
    Motor1.run(FORWARD);
    Motor2.run(FORWARD);
    Motor3.run(BACKWARD);
    Motor4.run(BACKWARD);
  }
    void TING()
    {
    Motor1.setSpeed(RELEASE);
    Motor2.setSpeed(RELEASE);
    Motor3.setSpeed(RELEASE);
    Motor4.setSpeed(RELEASE);
    delay(300);
      }

     
void loop()
{
  update_sensors();

  //前进
   if(adj_1 < b&&adj_2 >w&&adj_3>w)
   {
    GO();
    }


    //向左调整
    if(adj_3<m&&adj_1>w&&adj_2>w)
{
  LEFT();
  }

   //向右调整
    if(adj_3>w&&adj_1>w&&adj_2<b)
{
  RIGHT();
  }

//big left

if(adj_4> 200)
{
  BIGRIGHT();
   if(adj_1 < b&&adj_2 >w&&adj_3>w)
   {
    GO();
    }
  }
  
if(adj_5> 200)
{
  BIGLEFT();
   if(adj_1 < b&&adj_2 >w&&adj_3>w)
   {
    GO();
    }
  }

if (juliValue < 50)
{
  BACK();
  delay(200);
  BIGLEFT();
  if(adj_1 < b&&adj_2 >w&&adj_3>w)
   {
    GO();
    }
  }
    
  }

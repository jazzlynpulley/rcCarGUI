/* 
   -- crawlerGui -- 
    
   This source code of graphical user interface  
   has been generated automatically by RemoteXY editor. 
   To compile this code using RemoteXY library 2.3.1 or later version  
   download by link http://remotexy.com/en/library/ 
   To connect using RemoteXY mobile app by link http://remotexy.com/en/download/                    
     - for ANDROID 4.0.1 or later version; 
     - for iOS 1.1.0 or later version; 
     
   This source code is free software; you can redistribute it and/or 
   modify it under the terms of the GNU Lesser General Public 
   License as published by the Free Software Foundation; either 
   version 2.1 of the License, or (at your option) any later version.     
*/ 

////////////////////////////////////////////// 
//        RemoteXY include library          // 
////////////////////////////////////////////// 

// RemoteXY select connection mode and include library  
#define REMOTEXY_MODE__SOFTSERIAL
#include <SoftwareSerial.h> 

#include <RemoteXY.h> 
#include <Servo.h>

// RemoteXY connection settings  
#define REMOTEXY_SERIAL_RX 4 
#define REMOTEXY_SERIAL_TX 3 
#define REMOTEXY_SERIAL_SPEED 9600 
Servo myServo ;
Servo myServo2 ;

/* defined the right motor control pins */ 
#define PIN_MOTOR_FORWARD 9
#define PIN_MOTOR_FORWARD_SPEED 9

/* defined the left motor control pins */ 
#define PIN_MOTOR_REVERSE 10
#define PIN_MOTOR_REVERSE_SPEED 10



// RemoteXY configurate   
#pragma pack(push, 1) 
uint8_t RemoteXY_CONF[] = 
 { 255,3,0,0,0,63,0,8,13,0,
  4,32,8,3,9,47,4,26,4,160,
  36,8,54,9,4,26,4,160,37,31,
  55,9,4,26,129,0,1,55,43,7,
  17,65,99,99,101,108,101,114,97,116,
  105,111,110,0,129,0,48,18,32,8,
  17,83,116,101,101,114,105,110,103,0 };  
   
// this structure defines all the variables of your control interface  
struct { 

    // input variable
  iint8_t slider_1; // =-100..100 slider position 
  int8_t slider_2; // =-100..100 slider position 
  int8_t slider_7; // =-100..100 slider position

    // other variable
  uint8_t connect_flag;  // =1 if wire connected, else =0 

} RemoteXY; 
#pragma pack(pop) 

///////////////////////////////////////////// 
//           END RemoteXY include          // 
///////////////////////////////////////////// 



void setup()  
{ 
  RemoteXY_Init ();   

  pinMode (PIN_MOTOR_FORWARD, OUTPUT); 
  pinMode (PIN_MOTOR_REVERSE, OUTPUT);
 // Serial.begin(9600);//low Serial communication via USB cable to computer (if required)
 // pinMode(REMOTEXY_SERIAL_RX, INPUT); // Setup the Arduino to receive INPUT from the bluetooth shield on Digital Pin 6
 // pinMode(REMOTEXY_SERIAL_TX, OUTPUT);
  
  RemoteXY.slider_2 = 50;
  RemoteXY.slider_7 = 50;  
  
   
} 

void loop()  
{  
  RemoteXY_Handler (); 
   
   
  int acc = RemoteXY.slider_1; 
  if (acc>50) { //forward
    digitalWrite(PIN_MOTOR_FORWARD, HIGH);  
    analogWrite(PIN_MOTOR_FORWARD_SPEED, (acc-50) * 5.11);  
  }  
  else if (acc<50) { //reverse
    digitalWrite(PIN_MOTOR_REVERSE, LOW);  
    analogWrite(PIN_MOTOR_REVERSE_SPEED, (50-acc) * 5.11);  
  }  
  else { // stop 
    digitalWrite(PIN_MOTOR_FORWARD, LOW);  
    analogWrite(PIN_MOTOR_FORWARD_SPEED, 0);  
  }  

  //myServo.attach(8);  
  //myServo2.attach(7);
  
  myServo.analogWrite(9, RemoteXY.slider_1 * 2.55);
  //delay(1000);
  
  //myServo2.writeMicroseconds(RemoteXY.slider_7*20+500);
  


}

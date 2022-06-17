/*
 By:Farkad Adnan
 E-mail: farkad.hpfa95@gmail.com
 inst : farkadadnan
 #farkadadnan , #farkad_adnan , فرقد عدنان#
 FaceBook: كتاب عالم الاردوينو
 inst : arduinobook
 #كتاب_عالم_الاردوينو  #كتاب_عالم_الآردوينو 
 */
#include "AFMotor.h"

const int MOTOR_1 = 1; 
const int MOTOR_2 = 2; 
const int MOTOR_3 = 3; 
const int MOTOR_4 = 4; 

AF_DCMotor motor1(MOTOR_1, MOTOR12_64KHZ); 
AF_DCMotor motor2(MOTOR_2, MOTOR12_64KHZ); 
AF_DCMotor motor3(MOTOR_3, MOTOR12_64KHZ); 
AF_DCMotor motor4(MOTOR_4, MOTOR12_64KHZ); 

int state;
int Speed = 130; 

void setup() {
motor1.setSpeed(Speed);   
motor2.setSpeed(Speed);
motor3.setSpeed(Speed);
motor4.setSpeed(Speed);  
Serial.begin(9600);
delay(500); 
}

void loop(){   
if(Serial.available() > 0){ 
state = Serial.read();      
if(state > 10){Speed = state;}      
}
           
motor1.setSpeed(Speed);         
motor2.setSpeed(Speed);
motor3.setSpeed(Speed);
motor4.setSpeed(Speed);

     if(state == 1){forword(); } 
else if(state == 2){backword();}  
else if(state == 3){turnLeft();}  
else if(state == 4){turnRight();} 
else if(state == 5){Stop(); }    

delay(80);    
}
void forword(){
motor1.run(FORWARD); 
motor2.run(FORWARD); 
motor3.run(FORWARD); 
motor4.run(FORWARD);
}

void backword(){
motor1.run(BACKWARD); 
motor2.run(BACKWARD);
motor3.run(BACKWARD); 
motor4.run(BACKWARD); 
}

void turnRight(){
motor1.run(FORWARD); 
motor2.run(FORWARD); 
motor3.run(BACKWARD); 
motor4.run(BACKWARD);
}

void turnLeft(){
motor1.run(BACKWARD); 
motor2.run(BACKWARD);
motor3.run(FORWARD); 
motor4.run(FORWARD); 
}

void Stop(){
 motor1.run(RELEASE); 
 motor2.run(RELEASE);
 motor3.run(RELEASE);
 motor4.run(RELEASE);
}

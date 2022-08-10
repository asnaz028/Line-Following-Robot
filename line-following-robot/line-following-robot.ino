//including the libraries
#include <AFMotor.h>
//defining pins and variables
#define left A0
#define center A1
#define right A2
#define llrft A3
#define rright A4
//defining motors
AF_DCMotor motor1(1, MOTOR12_1KHZ); 
AF_DCMotor motor2(2, MOTOR12_1KHZ);
AF_DCMotor motor3(3, MOTOR34_1KHZ);
AF_DCMotor motor4(4, MOTOR34_1KHZ);
void setup() {
//declaring pin types
 pinMode(left,INPUT);
 pinMode(right,INPUT);
 pinMode(center,INPUT);
 //begin serial communication
 Serial.begin(9600);
 
}
void loop(){
 //printing values of the sensors to the serial monitor
 int leftS = digitalRead(left);
 int rightS = digitalRead(right);
 int centerS = digitalRead(center);
 //line detected by both
 if(leftS==0 && centerS==1 && rightS==0 ){
 //Forward
 motor1.run(FORWARD);
 motor1.setSpeed(80);
 motor2.run(FORWARD);
 motor2.setSpeed(80);
 motor3.run(FORWARD);
 motor3.setSpeed(80);
 motor4.run(FORWARD);
 motor4.setSpeed(80);
 Serial.println("forward");
 }
 
 //line detected by left sensor
 else if(leftS==1 && centerS==0 && rightS==0 ){
 //turn left
 motor1.run(BACKWARD);
 motor1.setSpeed(100);
 motor2.run(BACKWARD);
 motor2.setSpeed(100);
 motor3.run(FORWARD);
 motor3.setSpeed(100);
 motor4.run(FORWARD);
 motor4.setSpeed(100);
 Serial.println("left");
 }
 
//line detected by right sensor
 else if(leftS==0 && centerS==0 && rightS==1){
 //turn right
 motor1.run(FORWARD);
 motor1.setSpeed(130);
 motor2.run(FORWARD);
 motor2.setSpeed(130);
 motor3.run(BACKWARD);
 motor3.setSpeed(130) ;
 motor4.run(BACKWARD);
 motor4.setSpeed(130);
 Serial.println("right");
 
 }
 else if(leftS==0 && centerS==1 && rightS==1){
 //turn right
 motor1.run(FORWARD);
 motor1.setSpeed(130);
 motor2.run(FORWARD);
 motor2.setSpeed(130);
 motor3.run(BRAKE);
 motor3.setSpeed(0) ;
 motor4.run(BRAKE);
 motor4.setSpeed(0);
 Serial.println("right");
 
 }
 else if(leftS==1 && centerS==1 && rightS==1 ){
 //turn left
 motor1.run(BRAKE);
 motor1.setSpeed(0);
 motor2.run(BRAKE);
 motor2.setSpeed(0);
 motor3.run(BRAKE);
 motor3.setSpeed(0);
 motor4.run(BRAKE);
 motor4.setSpeed(0);
 Serial.println("Brake");
 }

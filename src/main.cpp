#include <Arduino.h>
#include <AFMotor.h> 

#include <Servo.h>
#include <GSMSimSMS.h>

// You can use any Serial interface. I recommended HardwareSerial. Please use the library with highiest baudrate.
// In examples, i used HardwareSerial. You can change it anymore.

  Servo myservo1,myservo;  // create servo object to control a servo
  int Commond = 0 , y = 90 , x = 90;
  AF_DCMotor motor1(1);
  AF_DCMotor motor2(2);
  AF_DCMotor motor3(3);
  AF_DCMotor motor4(4);

  void moveF(){
    motor1.run(FORWARD);
    motor2.run(FORWARD);
    motor3.run(FORWARD);
    motor4.run(FORWARD);
  }
  void moveB(){
    motor1.run(BACKWARD);
    motor2.run(BACKWARD);
    motor3.run(BACKWARD);
    motor4.run(BACKWARD);
  }
  void moveL(){
    motor1.run(BACKWARD);
    motor2.run(BACKWARD);
    motor3.run(FORWARD);
    motor4.run(FORWARD);
  }
  void moveR(){
    motor1.run(FORWARD);
    motor2.run(FORWARD);
    motor3.run(BACKWARD);
    motor4.run(BACKWARD);
  }
  boolean stop(){
    motor1.run(RELEASE);
    motor2.run(RELEASE);
    motor3.run(RELEASE);
    motor4.run(RELEASE);
    return true;
  }

  void setup() {
    // Begin the Serial
    Serial.begin(9600);
    Serial1.begin(115200);

    motor1.setSpeed(200);
    motor2.setSpeed(200);
    motor3.setSpeed(200);
    motor4.setSpeed(200);
    stop();
    delay(10);
    myservo.attach(9);
    delay(10);
    myservo1.attach(10);
    delay(700);
    myservo1.write(20);
    delay(700);
    myservo.write(90);
    delay(10);


  }

  
  void loop() {
     if (Serial1.available()>0)
    {
    
      Commond = Serial1.read();
      Serial.println(Commond);
      if (Commond == 5)
      {
        while(!stop()){

        }
      }
      if (Commond == 8)
      {
        moveF();
      }
      if (Commond == 2 )
      {
        moveB();

      }
      
      if (Commond == 4)
      {
        moveL();
      }
      if (Commond == 6)
      {
        moveR();        
      }
      if ((Commond == 9 )&&(x >= 0)){

        while((Commond != 1)&&(x >= 0)){
          x=x-5;
          myservo.write(x);
          if (Serial1.available()>0){
            Commond = Serial1.read();
          }
          delay(15);

        }      
      }
      if ((Commond == 10 )&&(x <= 180)){

        while((Commond != 1)&&(x <= 180)){
          x=x+5;
          myservo.write(x);
          if (Serial1.available()>0){
            Commond = Serial1.read();
          }
          delay(15);

        }      
      }
      if (Commond == 11 ){
        delay(700);
        myservo1.write(90);
        delay(700);
        myservo.write(90);
      }
      if (Commond == 12 ){
        delay(700);
        myservo1.write(20);
        delay(700);
        myservo.write(90);
      }
      if ((Commond == 3 )&&(y <= 130)){

        while((Commond != 1)&&(y <= 130)){
          y=y+5;
          myservo1.write(y);
          if (Serial1.available()>0){
            Commond = Serial1.read();
          }
          delay(15);

        }      
      }
      if ((Commond == 7 )&&(y >= 0)){

        while((Commond != 1)&&(y >= 0)){
          y=y-5;
          myservo1.write(y);
          if (Serial1.available()>0){
            Commond = Serial1.read();
          }
          delay(15);

        }      
      }
      
   }
    
}
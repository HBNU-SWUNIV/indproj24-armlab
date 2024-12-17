#include <PS2X_lib.h>
#include <Servo.h>
//#include <AccelStepper.h>
//#include <MultiStepper.h>
#include <Stepper.h>
#include <Steppino.h>
#include <FlexiTimer2.h> // 반드시 포함되어야 함

#define PS2_DAT        12
#define PS2_CMD        11
#define PS2_SEL        10
#define PS2_CLK        13
#define STEPS 200

//int stepspeed = 500;
//float stepangle = 1.8;
//int microcontrol = 1;
//int pulse;
//int speed = 0;

/*Stepper stepper1(STEPS, 22, 21, 20, 0);
  Stepper stepper2(STEPS, 39, 38, 37, 0);
  Stepper stepper3(STEPS, 52, 51, 50, 0);
  Stepper stepper4(STEPS, 48, 47, 46, 0);*/

//MultiStepper steppers;
int speed = 10000;
const int mit = 1;

int msMultiplier = 1;
int spr = 20 * msMultiplier;

/*int PUL1 = 19;
  int DIR1 = 18;
  int ENA1 = 17;
  int PUL2 = 16;
  int DIR2 = 15;
  int ENA2 = 14;
  int PUL3 = 35;
  int DIR3 = 34;
  int ENA3 = 33;
  int PUL4 = 30;
  int DIR4 = 29;
  int ENA4 = 28;*/
/*int PUL5 = 22;
  int DIR5 = 21;
  int ENA5 = 20;
  int PUL6 = 39;
  int DIR6 = 38;
  int ENA6 = 37;
  int PUL7 = 52;
  int DIR7 = 51;
  int ENA7 = 50;
  int PUL8 = 48;
  int DIR8 = 47;
  int ENA8 = 46;*/


/*AccelStepper stepper1 = AccelStepper (1, 22, 21, 20);*/
/*AccelStepper stepper1 = AccelStepper (1, 22, 21, 20);
  AccelStepper stepper2 = AccelStepper (1, 39, 38, 37, 0);
  AccelStepper stepper3 = AccelStepper (1, 52, 51, 50, 0);
  AccelStepper stepper4 = AccelStepper (1, 48, 47, 46, 0);*/

#define servo1 24 //앞 왼쪽, 세모버튼
#define servo2 25//앞 오른쪽, 동그라미버튼
#define servo3 26//뒤 왼쪽, 위버튼
#define servo4 27// 뒤 오른쪽, 왼쪽버튼
#define VAR A0

PS2X ps2x;
int LY = 0;
int LX = 0;
int RY = 0;
int RX = 0;
byte degree1 = 11;
byte degree2 = 87;
byte degree3 = 90;
byte degree4 = 0;
int error = 0;
byte type = 0;
byte vibrate = 0;

const int CLK1 = 19;
const int DIR1 = 18;
const int ENA1 = 17;

const int CLK2 = 16;
const int DIR2 = 15;
const int ENA2 = 14;

const int CLK3 = 35;
const int DIR3 = 34;
const int ENA3 = 33;

const int CLK4 = 30;
const int DIR4 = 29;
const int ENA4 = 28;

const int CLK5 = 22;
const int DIR5 = 21;
const int ENA5 = 20;

const int CLK6 = 39;
const int DIR6 = 38;
const int ENA6 = 37;

const int CLK7 = 52;
const int DIR7 = 51;
const int ENA7 = 50;

const int CLK8 = 48;
const int DIR8 = 47;
const int ENA8 = 46;

// 드라이버 타입에 따라 다음중 하나를 선택하세요
Steppino MyMotor1(md_1CK, 19, 18, 17, 0 ); // 1Clock 드라이버인 경우 CLK, DIR, ENA
Steppino MyMotor2(md_1CK, 16, 15, 14, 0 ); // 1Clock 드라이버인 경우 CLK, DIR, ENA
Steppino MyMotor3(md_1CK, 35, 34, 33, 0 ); // 1Clock 드라이버인 경우 CLK, DIR, ENA
Steppino MyMotor4(md_1CK, 30, 29, 28, 0 ); // 1Clock 드라이버인 경우 CLK, DIR, ENA
Steppino MyMotor5(md_1CK, 22, 21, 20, 0 ); // 1Clock 드라이버인 경우 CLK, DIR, ENA
Steppino MyMotor6(md_1CK, 39, 38, 37, 0 ); // 1Clock 드라이버인 경우 CLK, DIR, ENA
Steppino MyMotor7(md_1CK, 52, 51, 50, 0 ); // 1Clock 드라이버인 경우 CLK, DIR, ENA
Steppino MyMotor8(md_1CK, 48, 47, 46, 0 ); // 1Clock 드라이버인 경우 CLK, DIR, ENA
// Steppino MyMotor(md_2CK, 6,7,8,0 ); // 2Clock 드라이버인 경우 CLK, DIR, ENA
//Steppino MyMotor(md_Unipola, 6,7,8,9 ); // 유니폴라 드라이버인 경우 A, A', B, B'
// Steppino MyMotor(md_Bipola, 6,7,8,9 ); // 바이폴라 드라이버인 경우 A, A', B, B'

// Steppino MyMotor2(md_1CK, 2,3,4,0 ); // 복수개의 모터를 설정할 수 있습니다.


//int mystep1 = 1000;
//int mystep2 = 1000;
//int mystep3 = 1000;
//int mystep4 = 1000;


Servo myservo1;
Servo myservo2;
Servo myservo3;
Servo myservo4;

// 딜레이 시간 (속도)
/*int delay_time = 0.0001;
  // 시작 시간
  unsigned long start_time = millis();*/

void onTimer()
{
  MyMotor1.motor_Timer(); // Steppino 의 motor_Timer.호출
  MyMotor2.motor_Timer(); // 복수 모터시 모두 넣어 주어야 합니다.
  MyMotor3.motor_Timer(); // 복수 모터시 모두 넣어 주어야 합니다.
  MyMotor4.motor_Timer(); // 복수 모터시 모두 넣어 주어야 합니다.
  MyMotor5.motor_Timer(); // 복수 모터시 모두 넣어 주어야 합니다.
  MyMotor6.motor_Timer(); // 복수 모터시 모두 넣어 주어야 합니다.
  MyMotor7.motor_Timer(); // 복수 모터시 모두 넣어 주어야 합니다.
  MyMotor8.motor_Timer(); // 복수 모터시 모두 넣어 주어야 합니다.
}

void setup() {

  Serial.begin(9600);
  /*myservo1.attach(servo1);
    myservo2.attach(servo2);
    myservo3.attach(servo3);
    myservo4.attach(servo4);
    myservo1.write(11);
    myservo2.write(87);
    myservo3.write(90);
    myservo4.write(0);*/

  /*stepper1.runToPosition();
    stepper2.runToPosition();
    stepper3.runToPosition();
    stepper4.runToPosition();*/

  /*pinMode(PUL1, OUTPUT);
    pinMode(DIR1, OUTPUT);
    pinMode(ENA1, OUTPUT);
    pinMode(PUL2, OUTPUT);
    pinMode(DIR2, OUTPUT);
    pinMode(ENA2, OUTPUT);
    pinMode(PUL3, OUTPUT);
    pinMode(DIR3, OUTPUT);
    pinMode(ENA3, OUTPUT);
    pinMode(PUL4, OUTPUT);
    pinMode(DIR4, OUTPUT);
    pinMode(ENA4, OUTPUT);*/
  /*pinMode(PUL5, OUTPUT);
    pinMode(DIR5, OUTPUT);
    pinMode(ENA5, OUTPUT);
    pinMode(PUL6, OUTPUT);
    pinMode(DIR6, OUTPUT);
    pinMode(ENA6, OUTPUT);
    pinMode(PUL7, OUTPUT);
    pinMode(DIR7, OUTPUT);
    pinMode(ENA7, OUTPUT);
    pinMode(PUL8, OUTPUT);
    pinMode(DIR8, OUTPUT);
    pinMode(ENA8, OUTPUT);*/
  /*stepper1.setSpeed(500);
    stepper2.setSpeed(500);
    stepper3.setSpeed(500);
    stepper4.setSpeed(500);*/

  /* stepper1.setMaxSpeed(1500);
    //stepper1.setSpeed(400);
    stepper2.setMaxSpeed(1500);
    //stepper2.setSpeed(400);
    stepper3.setMaxSpeed(1500);
    //stepper3.setSpeed(400);
    stepper4.setMaxSpeed(1500);
    //stepper4.setSpeed(400);*/

  /*stepper1.setMaxSpeed(1000);
    stepper2.setMaxSpeed(1000);
    stepper3.setMaxSpeed(1000);
    stepper4.setMaxSpeed(1000);//초당 몇스탭이냐? 1000/s(초당5회전)*/
  /*stepper2.setMaxSpeed(80000000000);
    stepper3.setMaxSpeed(80000000000);
    stepper4.setMaxSpeed(80000000000);*/

  /*stepper1.setMaxSpeed(5000);
    stepper2.setMaxSpeed(5000);
    stepper3.setMaxSpeed(5000);
    stepper4.setMaxSpeed(5000);
    stepper1.setSpeed(300);
    stepper2.setSpeed(300);
    stepper3.setSpeed(-300);
    stepper4.setSpeed(-300);*/

  pinMode(CLK1, OUTPUT);
  pinMode(DIR1, OUTPUT);
  pinMode(ENA1, OUTPUT);

  pinMode(CLK2, OUTPUT);
  pinMode(DIR2, OUTPUT);
  pinMode(ENA2, OUTPUT);

  pinMode(CLK3, OUTPUT);
  pinMode(DIR3, OUTPUT);
  pinMode(ENA3, OUTPUT);

  pinMode(CLK4, OUTPUT);
  pinMode(DIR4, OUTPUT);
  pinMode(ENA4, OUTPUT);

  pinMode(CLK5, OUTPUT);
  pinMode(DIR5, OUTPUT);
  pinMode(ENA5, OUTPUT);

  pinMode(CLK6, OUTPUT);
  pinMode(DIR6, OUTPUT);
  pinMode(ENA6, OUTPUT);

  pinMode(CLK7, OUTPUT);
  pinMode(DIR7, OUTPUT);
  pinMode(ENA7, OUTPUT);

  pinMode(CLK8, OUTPUT);
  pinMode(DIR8, OUTPUT);
  pinMode(ENA8, OUTPUT);



  // Steppino 의 설정을 변경할 수 있습니다.
  MyMotor1.setDelay( 80, 24, 40 ); // Unipola, Bipola 이면 24 정도 1CK, 2CK 는 6정도
  MyMotor2.setDelay( 80, 24, 40 ); // 1CK, 2CK 의 경우는 6 정도도 가능
  MyMotor3.setDelay( 80, 24, 40 ); // 1CK, 2CK 의 경우는 6 정도도 가능
  MyMotor4.setDelay( 80, 24, 40 ); // Unipola, Bipola 이면 24 정도 1CK, 2CK 는 6정도
  MyMotor5.setDelay( 80, 24, 40 ); // 1CK, 2CK 의 경우는 6 정도도 가능
  MyMotor6.setDelay( 80, 24, 40 ); // 1CK, 2CK 의 경우는 6 정도도 가능
  MyMotor7.setDelay( 80, 24, 40 ); // 1CK, 2CK 의 경우는 6 정도도 가능
  MyMotor8.setDelay( 80, 24, 40 ); // 1CK, 2CK 의 경우는 6 정도도 가능


  /*stepper1.setAcceleration(500);
    stepper2.setAcceleration(500);
    stepper3.setAcceleration(500);
    stepper4.setAcceleration(500);*/
  /*stepper2.setAcceleration(400);
    stepper3.setAcceleration(400);
    stepper4.setAcceleration(400);*/

  /*stepper1.moveTo(1000); //목표스탭량을 설정함
    stepper2.moveTo(1000); //목표스탭량을 설정함
    stepper3.moveTo(1000); //목표스탭량을 설정함
    stepper4.moveTo(1000); //목표스탭량을 설정함*/

  /*stepper1.setMinPulseWidth(10);
    stepper2.setMinPulseWidth(10);
    stepper3.setMinPulseWidth(10);
    stepper4.setMinPulseWidth(10);*/


  /*stepper1.setCurrentPosition(0);//현재 스탭을 설정
    stepper2.setCurrentPosition(0);
    stepper3.setCurrentPosition(0);
    stepper4.setCurrentPosition(0);*/

  /*36steppers.addStepper(stepper1);
    steppers.addStepper(stepper2);
    steppers.addStepper(stepper3);
    steppers.addStepper(stepper4);*/



  error = ps2x.config_gamepad(13, 11, 10, 12, true, true); //setup pins and settings:  GamePad(clock, command, attention, data, Pressures?, Rumble?) check for error

  if (error == 0) {
    Serial.println("Found Controller, configured successful");
    Serial.println("Try out all the buttons, X will vibrate the controller, faster as you press harder;");
    Serial.println("holding L1 or R1 will print out the analog stick values.");
    Serial.println("Go to www.billporter.info for updates and to report bugs.");
  }

  else if (error == 1)
    Serial.println("No controller found, check wiring, see readme.txt to enable debug. visit www.billporter.info for troubleshooting tips");

  else if (error == 2)
    Serial.println("Controller found but not accepting commands. see readme.txt to enable debug. Visit www.billporter.info for troubleshooting tips");

  else if (error == 3)
    Serial.println("Controller refusing to enter Pressures mode, may not support it. ");

  //Serial.print(ps2x.Analog(1), HEX);

  type = ps2x.readType();
  switch (type) {
    case 0:
      Serial.println("Unknown Controller type");
      break;
    case 1:
      Serial.println("DualShock Controller Found");
      break;
    case 2:
      Serial.println("GuitarHero Controller Found");
      break;
    case 3:
      Serial.print("Wireless Sony DualShock Controller found ");
      break;
  }
  /*digitalWrite(ENA5, LOW);*/
}

void loop() {
  //long positions[4];



  if (error == 1) //skip loop if no controller found
    return;

  ps2x.read_gamepad(false, vibrate);          //read controller and set large motor to spin at 'vibrate' speed

  if (ps2x.Button(PSB_START))                  //will be TRUE as long as button is pressed
    Serial.println("Start is being held");
  if (ps2x.Button(PSB_SELECT))
    Serial.println("Select is being held");

  if (ps2x.Button(PSB_PAD_UP)) {
    Serial.print("PSB_PAD_UP");
    //Serial.println(ps2x.Analog(PSAB_PAD_RIGHT), DEC);

    /*FlexiTimer2::set( 1, 0.09 / 1000, onTimer ); // 16 micro seconds.
    FlexiTimer2::start();
    MyMotor1.Stop(); // 역방향 두바퀴
    MyMotor2.Stop(); // 역방향 두바퀴
    MyMotor3.Stop(); // 역방향 두바퀴
    MyMotor4.Stop(); // 역방향 두바퀴 리니어모터 정지 .*/ 

    FlexiTimer2::set( 1, 0.05 / 1000, onTimer ); // 16 micro seconds.
    FlexiTimer2::start();
    MyMotor5.Start(1, 2000 ); // 정방향 두바퀴
    MyMotor6.Start(1, 2000 ); // 정방향 두바퀴
    MyMotor7.Start(1, 2000 ); // 정방향 두바퀴
    MyMotor8.Start(1, 2000 ); // 정방향 두바퀴

    
    /*digitalWrite(DIR5, HIGH);
      digitalWrite(ENA5, HIGH);
      digitalWrite(PUL5, HIGH);
      delayMicroseconds(0.00001);
      digitalWrite(PUL5, LOW);
      delayMicroseconds(0.00001);*/

    /*stepper1.runSpeed();
      stepper2.runSpeed();
      stepper3.runSpeed();
      stepper4.runSpeed();*/
  }
  if (ps2x.Button(PSB_PAD_RIGHT)) {
    Serial.print("Right held this hard: ");
    //Serial.println(ps2x.Analog(PSAB_PAD_RIGHT), DEC);
    /*digitalWrite(ENA5, HIGH);*/
    /*stepper1.step(-mystep1);
      stepper2.step(-mystep2);
      stepper3.step(-mystep3);
      stepper4.step(-mystep4);*/
    /*stepper1.moveTo(8000);
      stepper2.moveTo(8000);
      stepper3.moveTo(8000);
      stepper4.moveTo(8000);
      stepper1.runToPosition();
      stepper2.runToPosition();
      stepper3.runToPosition();
      stepper4.runToPosition();*/

    /*positions[0] = 2000;
      positions[1] = 2000;
      positions[2] = 2000;
      positions[3] = 2000;

      stepper1.moveTo(positions);
      stepper2.moveTo(positions);
      stepper3.moveTo(positions);
      stepper4.moveTo(positions);
      steppers.runSpeedToPosition(); // Bltocks until all are in position
      delay(1000);*/
    /*stepper1.runSpeed();
      stepper2.runSpeed();
      stepper3.runSpeed();
      stepper4.runSpeed();
      delay(50);*/
    // FlexiTimer 의 주기를 16 microseconds 정도가 적당합니다.
    // 더 작게하면 loop 에서의 작업들이 원할하지 않을 수 있습니다.

    FlexiTimer2::set( 1, 0.05 / 1000, onTimer ); // 16 micro seconds.
    FlexiTimer2::start();

    MyMotor5.Start(1, 2000 ); // 정방향 두바퀴
    MyMotor6.Start(-1, 2000 ); // 정방향 두바퀴
    MyMotor7.Start(1, 2000 ); // 정방향 두바퀴
    MyMotor8.Start(-1, 2000 ); // 정방향 두바퀴

    /*yservo1.write(75);
      myservo2.write(22);
      myservo3.write(30);
      myservo4.write(63);*/




    /*stepper1.moveTo(stepper1.currentPosition() + 10); // Adjust the number of steps as needed
      stepper1.runToPosition();*/


    /*stepper1.moveTo(4000);
      while (stepper1.currentPosition() != +4000) // Full speed up to 300
      stepper1.run();
      stepper1.runToNewPosition(0); // Cause an overshoot then back to 0*/
    /*stepper1.setSpeed(+20000);
      stepper2.setSpeed(-20000);
      stepper3.setSpeed(+20000);
      stepper4.setSpeed(-20000);*/
    /*stepper1.runSpeedToPosition();
      stepper2.runSpeedToPosition();
      stepper3.runSpeedToPosition();
      stepper4.runSpeedToPosition();*/
    /*stepper1.moveTo(stepper1.currentPosition() + 10);
      stepper2.moveTo(stepper2.currentPosition() + 10);
      stepper3.moveTo(stepper3.currentPosition() + 10);
      stepper4.moveTo(stepper4.currentPosition() + 10);*/
    /*stepper1.setMinPulseWidth(0.001);
      stepper2.setMinPulseWidth(0.001);
      stepper3.setMinPulseWidth(0.001);
      stepper4.setMinPulseWidth(0.001);*/
    /*stepper1.move(1);
      stepper2.move(1);
      stepper3.move(1);
      stepper4.move(1);

      stepper1.setSpeed(stepspeed);
      stepper2.setSpeed(stepspeed);
      stepper3.setSpeed(stepspeed);
      stepper4.setSpeed(stepspeed);

      stepper1.runSpeedToPosition();
      stepper2.runSpeedToPosition();
      stepper3.runSpeedToPosition();
      stepper4.runSpeedToPosition();
      delay(10);*/


  }
  if (ps2x.Button(PSB_PAD_LEFT)) {
    Serial.print("LEFT held this hard: ");
    //Serial.println(ps2x.Analog(PSAB_PAD_LEFT), DEC);
    /*digitalWrite(ENA5, LOW);*/
    /*stepper1.step(+mystep1);
      stepper2.step(+mystep2);
      stepper3.step(+mystep3);
      stepper4.step(+mystep4);*/
    FlexiTimer2::set( 1, 0.05 / 1000, onTimer ); // 16 micro seconds.
    FlexiTimer2::start();

    MyMotor5.Start(-1, 2000 ); // 정방향 두바퀴
    MyMotor6.Start(1, 2000 ); // 정방향 두바퀴
    MyMotor7.Start(-1, 2000 ); // 정방향 두바퀴
    MyMotor8.Start(1, 2000 ); // 정방향 두바퀴

    myservo1.detach();
    myservo2.detach();
    myservo3.detach();
    myservo4.detach();


    /*positions[0] = 0;
      positions[1] = 0;
      positions[2] = 0;
      positions[3] = 0;

      steppers.moveTo(positions);
      steppers.runSpeedToPosition(); // Blocks until all are in position
      delay(1000);*/
    /*positions[0] = 100;
      positions[1] = 100;
      positions[2] = 100;
      positions[3] = 100;
      stepper1.moveTo(positions);
      stepper2.moveTo(positions);
      stepper3.moveTo(positions);
      stepper4.moveTo(positions);
      steppers.runSpeedToPosition(); // Blocks until all are in position
      delay(1000);*/

    /*stepper1.setSpeed(-100);
      stepper2.setSpeed(-100);
      stepper3.setSpeed(-100);
      stepper4.setSpeed(-100);*/
    /* stepper1.runSpeedToPosition();
       stepper2.runSpeedToPosition();
       stepper3.runSpeedToPosition();
       stepper4.runSpeedToPosition();*/
    /*stepper1.moveTo(stepper1.currentPosition() - 10);
      stepper2.moveTo(stepper2.currentPosition() - 10);
      stepper3.moveTo(stepper3.currentPosition() - 10);
      stepper4.moveTo(stepper4.currentPosition() - 10);*/
    /*stepper1.moveTo(+spr);
      stepper1.runToPosition();
      stepper2.moveTo(+spr);
      stepper2.runToPosition();
      stepper3.moveTo(+spr);
      stepper3.runToPosition();
      stepper4.moveTo(+spr);
      stepper4.runToPosition();*/



  }

  if (ps2x.Button(PSB_PAD_DOWN)) {
    Serial.print("PSB_PAD_DOWN");
    //Serial.println(ps2x.Analog(PSAB_PAD_LEFT), DEC);
    /*digitalWrite(DIR5, LOW);
      digitalWrite(ENA5, HIGH);
      digitalWrite(PUL5, HIGH);
      delayMicroseconds(100);
      digitalWrite(PUL5, LOW);
      delayMicroseconds(100);*/

    /*stepper1.setSpeed(0);
      stepper2.setSpeed(0);
      stepper3.setSpeed(0);
      stepper4.setSpeed(0);*/
    /*FlexiTimer2::set( 1, 0.05 / 1000, onTimer ); // 16 micro seconds.
    FlexiTimer2::start();

    MyMotor1.Stop(); // 역방향 두바퀴
    MyMotor2.Stop(); // 역방향 두바퀴
    MyMotor3.Stop(); // 역방향 두바퀴
    MyMotor4.Stop(); // 역방향 두바퀴 바퀴 정지

    myservo1.detach();
    myservo2.detach();
    myservo3.detach();
    myservo4.detach();*/
    
     FlexiTimer2::set( 1, 0.05 / 1000, onTimer ); // 16 micro seconds.
    FlexiTimer2::start();
    MyMotor5.Start(-1, 2000 ); // 정방향 두바퀴
    MyMotor6.Start(-1, 2000 ); // 정방향 두바퀴
    MyMotor7.Start(-1, 2000 ); // 정방향 두바퀴
    MyMotor8.Start(-1, 2000 ); // 정방향 두바퀴


  }
  //vibrate = ps2x.Analog(PSAB_BLUE);        //this will set the large motor vibrate speed based on
  //how hard you press the blue (X) button

  if (ps2x.NewButtonState())               //will be TRUE if any button changes state (on to off, or off to on)
  {
  }
  if (ps2x.Button(PSB_L1 )) // print stick values if either is TRUE
  { int varValue = map(analogRead(VAR), 0, 1023, 0, 179);

    FlexiTimer2::set( 1, 0.09 / 1000, onTimer ); // 16 micro seconds.
    FlexiTimer2::start();
    MyMotor1.Stop(); // 정방향 두바퀴
    MyMotor2.Stop(); // 정방향 두바퀴
    MyMotor3.Stop(); // 정방향 두바퀴
    MyMotor4.Stop(); // 정방향 두바퀴
    MyMotor5.Start(1, 1000 ); // 정방향 두바퀴
    MyMotor6.Start(-1, 1000 ); // 정방향 두바퀴
    MyMotor7.Start(-1, 1000 ); // 정방향 두바퀴
    MyMotor8.Start(1, 1000 ); // 정방향 두바퀴
    
    myservo1.attach(servo1);
    myservo2.attach(servo2);
    myservo3.attach(servo3);
    myservo4.attach(servo4);
    myservo1.write(105);
    myservo2.write(22);
    myservo3.write(0);
    myservo4.write(95);
    delay(500);
    myservo1.detach();
    myservo2.detach();
    myservo3.detach();
    myservo4.detach();


    //degree1 -= 5;
    // Serial.println("L1 pressed");

  }
  if (ps2x.Button(PSB_L2)) {
    int varValue = map(analogRead(VAR), 0, 1023, 0, 179);



    FlexiTimer2::set( 1, 0.09 / 1000, onTimer ); // 16 micro seconds.
    FlexiTimer2::start();
    MyMotor1.Stop(); // 정방향 두바퀴
    MyMotor2.Stop(); // 정방향 두바퀴
    MyMotor3.Stop(); // 정방향 두바퀴
    MyMotor4.Stop(); // 정방향 두바퀴
    MyMotor5.Start(-1, 1000 ); // 정방향 두바퀴
    MyMotor6.Start(1, 1000 ); // 정방향 두바퀴
    MyMotor7.Start(1, 1000 ); // 정방향 두바퀴
    MyMotor8.Start(-1, 1000 ); // 정방향 두바퀴
    
    myservo1.attach(servo1);
    myservo2.attach(servo2);
    myservo3.attach(servo3);
    myservo4.attach(servo4);
    myservo1.write(40);
    myservo2.write(86);
    myservo3.write(60);
    myservo4.write(30);
    delay(500);
    myservo1.detach();
    myservo2.detach();
    myservo3.detach();
    myservo4.detach();

    //degree2 -= 5;
    /// Serial.println("L2 pressed");

  }
  if (ps2x.Button(PSB_R1)) {


    /*FlexiTimer2::set( 1, 0.09 / 1000, onTimer ); // 16 micro seconds.
    FlexiTimer2::start();
    MyMotor1.Start(-1, 1000 ); // 역방향 두바퀴
    MyMotor2.Start(-1, 1000 ); // 역방향 두바퀴
    MyMotor3.Start(-1, 1000 ); // 역방향 두바퀴
    MyMotor4.Start(-1, 1000 ); // 역방향 두바퀴.*/

     FlexiTimer2::set( 1, 0.05 / 1000, onTimer ); // 16 micro seconds.
    FlexiTimer2::start();
    MyMotor1.Stop(); // 정방향 두바퀴
    MyMotor2.Stop(); // 정방향 두바퀴
    MyMotor3.Stop(); // 정방향 두바퀴
    MyMotor4.Stop(); // 정방향 두바퀴
    MyMotor5.Start(1, 1000 ); // 정방향 두바퀴
    MyMotor6.Start(-1, 1000 ); // 정방향 두바퀴
    MyMotor7.Start(-1, 1000 ); // 정방향 두바퀴
    MyMotor8.Start(1, 1000 ); // 정방향 두바퀴
    
    myservo1.attach(servo1);
    myservo2.attach(servo2);
    myservo3.attach(servo3);
    myservo4.attach(servo4);
    myservo1.write(76);
    myservo2.write(47);
    myservo3.write(30);
    myservo4.write(60);
    delay(500);
    myservo1.detach();
    myservo2.detach();
    myservo3.detach();
    myservo4.detach();
    //degree3 -= 5;
    // Serial.println("R1 pressed");

    //step4
  }
  if (ps2x.Button(PSB_R2)) {

    /*FlexiTimer2::set( 1, 0.09 / 1000, onTimer ); // 16 micro seconds.
    FlexiTimer2::start();
    MyMotor1.Start(1, 1000 ); // 역방향 두바퀴
    MyMotor2.Start(1, 1000 ); // 역방향 두바퀴
    MyMotor3.Start(1, 1000 ); // 역방향 두바퀴
    MyMotor4.Start(1, 1000 ); // 역방향 두바퀴.*/

     FlexiTimer2::set( 1, 0.05 / 1000, onTimer ); // 16 micro seconds.
    FlexiTimer2::start();
    MyMotor1.Stop(); // 정방향 두바퀴
    MyMotor2.Stop(); // 정방향 두바퀴
    MyMotor3.Stop(); // 정방향 두바퀴
    MyMotor4.Stop(); // 정방향 두바퀴
    MyMotor5.Start(-1, 10000 ); // 정방향 두바퀴
    MyMotor6.Start(1, 10000 ); // 정방향 두바퀴
    MyMotor7.Start(1, 10000 ); // 정방향 두바퀴
    MyMotor8.Start(-1, 10000 ); // 정방향 두바퀴
    
    myservo1.attach(servo1);
    myservo2.attach(servo2);
    myservo3.attach(servo3);
    myservo4.attach(servo4);
    myservo1.write(41);
    myservo2.write(52);
    myservo3.write(60);
    myservo4.write(30);
    delay(500);
    myservo1.detach();
    myservo2.detach();
    myservo3.detach();
    myservo4.detach();
    
    //degree4 -= 5;
    // Serial.println("R2 pressed");

  }
  if (ps2x.Button(PSB_GREEN)) {
    FlexiTimer2::set( 1, 0.09 / 1000, onTimer ); // 16 micro seconds.
    FlexiTimer2::start();
    MyMotor1.Start(1, 1000 ); // 역방향 두바퀴
    //degree1 += 5;
    Serial.println("Triangle pressed");
  }
  if (ps2x.Button(PSB_RED)) {           //will be TRUE if button was JUST pressed
    FlexiTimer2::set( 1, 0.09 / 1000, onTimer ); // 16 micro seconds.
    FlexiTimer2::start();
    MyMotor4.Start(1, 1000 ); // 역방향 두바퀴
    //degree2 += 5;
    Serial.println("Circle just pressed");

  }
  if (ps2x.Button(PSB_PINK)) {           //will be TRUE if button was JUST released
    FlexiTimer2::set( 1, 0.09 / 1000, onTimer ); // 16 micro seconds.
    FlexiTimer2::start();
    MyMotor2.Start(1, 1000 ); // 역방향 두바퀴
    //degree3 += 5;
    Serial.println("Square just released");
  }
  if (ps2x.Button(PSB_BLUE)) {          //will be TRUE if button was JUST pressed OR release
    FlexiTimer2::set( 1, 0.09 / 1000, onTimer ); // 16 micro seconds.
    FlexiTimer2::start();
    MyMotor3.Start(1, 1000 ); // 역방향 두바퀴
    //degree4 += 5;
    Serial.println("X just changed");
  }

  LY = ps2x.Analog(PSS_LY);                     //receive values from p22 joystick
  LX = ps2x.Analog(PSS_LX);
  RY = ps2x.Analog(PSS_RY);
  RX = ps2x.Analog(PSS_RX);

  Serial.print("Stick Values:");
  Serial.print(ps2x.Analog(PSS_LY), DEC); //Left stick, Y axis. Other options: LX, RY, RX
  Serial.print(",");
  Serial.print(ps2x.Analog(PSS_LX), DEC);
  Serial.print(",");
  Serial.print(ps2x.Analog(PSS_RY), DEC);
  Serial.print(",");
  Serial.print(ps2x.Analog(PSS_RX), DEC);
  Serial.print(",");
  if (LY < 30) {

  }

  if (LX > 125 || LX < 130 ) {

  }

  if (LX > 10) {


  }

  if (LX < 80) {
    FlexiTimer2::set( 1, 0.05 / 1000, onTimer ); // 16 micro seconds.
    FlexiTimer2::start();

    MyMotor5.Start(-1, 2000 ); // 정방향 두바퀴
    MyMotor6.Start(-1, 2000 ); // 정방향 두바퀴
    MyMotor7.Start(1, 2000 ); // 정방향 두바퀴
    MyMotor8.Start(1, 2000 ); // 정방향 두바퀴

  }

  if (LY > 230) {
    FlexiTimer2::set( 1, 0.05 / 1000, onTimer ); // 16 micro seconds.
    FlexiTimer2::start();

    MyMotor5.Start(1, 2000 ); // 정방향 두바퀴
    MyMotor6.Start(1, 2000 ); // 정방향 두바퀴
    MyMotor7.Start(-1, 2000 ); // 정방향 두바퀴
    MyMotor8.Start(-1, 2000 ); // 정방향 두바퀴



  }
  if (RX > 230) {
    FlexiTimer2::set( 1, 0.09 / 1000, onTimer ); // 16 micro seconds.
    FlexiTimer2::start();
    MyMotor4.Start(-1, 1000 ); // 역방향 두바퀴


  }
  if (RX < 30) {
    FlexiTimer2::set( 1, 0.09 / 1000, onTimer ); // 16 micro seconds.
    FlexiTimer2::start();
    MyMotor2.Start(-1, 1000 ); // 역방향 두바퀴

  }
  if (RY < 30) {
    FlexiTimer2::set( 1, 0.09 / 1000, onTimer ); // 16 micro seconds.
    FlexiTimer2::start();
    MyMotor1.Start(-1, 1000 ); // 역방향 두바퀴

  }
  if (RY > 230) {
    FlexiTimer2::set( 1, 0.09 / 1000, onTimer ); // 16 micro seconds.
    FlexiTimer2::start();
    MyMotor3.Start(-1, 1000 ); // 역방향 두바퀴

  }
  Serial.print("Stick Values:");
  Serial.print(ps2x.Analog(PSS_LY), DEC); //Left stick, Y axis. Other options: LX, RY, RX
  Serial.print(",");
  Serial.print(ps2x.Analog(PSS_LX), DEC);
  Serial.print(",");
  Serial.print(ps2x.Analog(PSS_RY), DEC);
  Serial.print(",");
  Serial.println(ps2x.Analog(PSS_RX), DEC);
  LY = LX = 128;
  RY = RX = 128;
  degree1 = constrain(degree1, 0, 180);
  degree2 = constrain(degree2, 0, 180);
  degree3 = constrain(degree3, 0, 180);
  degree4 = constrain(degree4, 0, 180);


  myservo1.write(degree1);
  myservo2.write(degree2);
  myservo3.write(degree3);
  myservo4.write(degree4);

  /*if (start_time < millis() - delay_time ) {
    stepper1.step(+mystep1);
    stepper2.step(+mystep2);
    stepper3.step(+mystep3);
    stepper4.step(+mystep4);
    }*/
  /*stepper1.runSpeed();
    stepper2.runSpeed();
    stepper3.runSpeed();
    stepper4.runSpeed();
    delay(50);*/
}

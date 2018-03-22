#include <Stepper.h>

#define MOTOR_BREAK 7
#define PUMP 6

#define LEFT_MOTOR_STEP 13
#define LEFT_MOTOR_DIR 12
#define LEFT_MOTOR_ENABLE 11
#define LEFT_HOME_SWITCH 
#define LEFT_AWAY_SWITCH 
#define LEFT_IR_RELAY_ 22
#define LEFT_DIR_UP 1
#define LEFT_DIR_DOWN -1

#define RIGHT_MOTOR_STEP 10
#define RIGHT_MOTOR_DIR 9
#define RIGHT_MOTOR_ENABLE 8
#define RIGHT_HOME_SWITCH
#define RIGHT_AWAY_SWITCH 
#define RIGHT_IR_RELAY_ 24
#define RIGHT_DIR_UP -1
#define RIGHT_DIR_DOWN 1

#define STEP_PER_REVOLUTION 400
#define DRIVER_MICROSTEPS 0.25
#define BELT_PRESENT_PITCH 4 //mm 
#define PULLEY_TOOTH 20 

float stepPerMM = 0; 
bool cal = true;
int stepSpeed = 450;
int travelledDistance; 
int firstShelf = 0; 
int secondFloor = 0; 
int thirdFloor = 0; 

typedef struct Pos{
  int left;
  int right;
 }Pos;
 
Pos currentPos;
Pos maxPos;
Pos newPos;

Stepper motor_left(STEP_PER_REVOLUTION, LEFT_MOTOR_STEP, LEFT_MOTOR_DIR); 
Stepper motor_right(STEP_PER_REVOLUTION, RIGHT_MOTOR_STEP, RIGHT_MOTOR_DIR);

void setup() {
  Serial.begin(9600);
  pinMode(LEFT_HOME_SWITCH, INPUT_PULLUP);
  pinMode(RIGHT_HOME_SWITCH, INPUT_PULLUP);
  pinMode(LEFT_AWAY_SWITCH, INPUT_PULLUP);
  pinMode(RIGHT_AWAY_SWITCH, INPUT_PULLUP); 
  pinMode(LEFT_MOTOR_ENABLE, HIGH);
  pinMode(RIGHT_MOTOR_ENABLE, HIGH);

  firstShelf = analogRead( 
  secondFloor
  thirdFloor

  stepPerMM = stepsToMMCalculation(STEP_PER_REVOLUTION, DRIVER_MICROSTEPS, BELT_PRESENT_PITCH, PULLEY_TOOTH);

/*
  currentPos.left = 0;
  currentPos.right = 0;
  maxPos.left = 5000;
  maxPos.right = 3000;
  
  newPos.left = 0;
  newPos.right = 0;
  */
}

void loop()
{
  if (!cal)
  { 
    calibration();
    cal = true;
  }
  
  newPos.left = 50;
  newPos.right = 75;
  

  
  while(moveStep(newPos.left ,newPos.right))
  {
      Serial.println("Trying move");
    //Serial.println("Current x pos " + currentPos.x);
    Serial.println(currentPos.left);
    Serial.println(currentPos.right);
    //Serial.println("Current y pos " + currentPos.y);
    delay(100);
  }

//  Serial.print("travelled distance x direction: ");
//  Serial.print(maxPosXinMM); //xCoordinate
//  Serial.println("travelled distance y direction:  ");
//  Serial.print(maxPosYinMM); //yCoordinate
}







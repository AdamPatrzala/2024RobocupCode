#include "UltraSonicSensor.h"
#include "TwoControllerBase.h"
/*******************************************************
 * These comands all need to go into the loop function
 * Values you can use in setting the motor values:
 * 
 *   myBase->MAX_SPEED = 255; 
 *   myBase->THREE_QUARTER_SPEED = 138; 
 *   myBase->HALF_SPEED = 92; 
 *   myBase->QUARTER_SPEED = 46;  
 *   myBase->MIN_SPEED = 15; 
 *   eg. myBase->driveForward(myBase->MAX_SPEED, myBase->MAX_SPEED);
 * 
 * Functions you can call to make the Robot drive: 
 * 
 *   driveForward(rightWheelValue, leftWheelValue);
 *   driveBackward(rightWheelValue, leftWheelValue);
 *   rotateRight(turnSpeed);
 *   rotateLeft(turnSpeed);
 *   eg. myBase->rotateRight(myBase->HALF_SPEED);
 ******************************************************/

//#include "RobotPixyV2.h"

/*******************************************************
 * These comands all need to go into the loop function
 * Functions you can call to get data from the PixyCam:
 * 
 *    isInFront(ball);  
 *      this function is a boolean so returns true or false
 *      and can be used like: 
 *    if(myPixy->isInFront(ball){
 *      some code
 *    }else{
 *      some other code
 *    }
 *    
 *    getX(goal);
 *      this function returns a number relating to the x 
 *      position of the object and can be used like: 
 *    
 *    if(myPixy->getX(goal) < 120){
 *      rotateLeft(myBase->HALF_SPEED);
 *    }
 *    or
 *    if(myPixy->getX(goal) < 120 && !isInFront(goal)){
 *      rotateLeft(myBase->HALF_SPEED);
 *    }else {
 *      rotateRight(myBase->HALF_SPEED);
 *    }
 *    
 *    getArea(ownGoal);
 *      this function returns the area of the object chosen  
 *      and can be used like this:
 *      
 *     if(myPixy->getArea(ownGoal)> 2000){
 *        some code to save the ball because you are close to your own goal
 *     }
 *     
 *      // put your main code here, to run repeatedly:
      pixy->lightsOn();
      Serial.print("this is the x value:  ");Serial.println(pixy->getX());
      delay(500);
      Serial.print("this is the y value:  ");Serial.println(pixy->getY());
      delay(500);
      Serial.print("this will display if in front:  ");Serial.println(pixy->isInFront());
      delay(500);
      Serial.print("this is the area value:  ");Serial.println(pixy->getArea());
      delay(250);
  pixy->lightsOff();
  delay(1000);
 *    
 * *****************************************************/
//  RobotPixyV2 *pixy;
 UltraSonicSensor *frontUltraSensor,*backUltraSensor,*leftUltraSensor,*rightUltraSensor;
         unsigned long previousMillis = 0UL;
         unsigned long interval = 1000UL;

  TwoControllerBase *myBase;
  //RobotPixy *myPixy;
      int ball, goal, ownGoal;

void setup(){
//     pixy = new RobotPixyV2();
      Serial.begin(9600);
	    // the code you write in here runs once at the very start of the program
      myBase = new TwoControllerBase();
     	//myPixy = new RobotPixy();
	    ball = 1;
    	goal = 2;
    	ownGoal = 3;
      frontUltraSensor = new UltraSonicSensor(A0, A1);
      backUltraSensor = new UltraSonicSensor(A2, A3);
      leftUltraSensor = new UltraSonicSensor(A4, A5);
      rightUltraSensor = new UltraSonicSensor(A6, A7);
      Serial.begin(9600);
  }

  void loop(){
    unsigned long currentMillis = millis();
    if(currentMillis - previousMillis > interval){
    //update the previousMillis value
    previousMillis = currentMillis;
    //Serial.println(frontUltraSensor->getDistance());





 // all the code you write in here will run over and over 50 times per second

    if(leftUltraSensor->getDistance() > rightUltraSensor->getDistance()){
        myBase->driveLeft(myBase->HALF_SPEED,myBase->HALF_SPEED);
      }else if(leftUltraSensor->getDistance() < rightUltraSensor->getDistance()){
        myBase->driveRight(myBase->HALF_SPEED,myBase->HALF_SPEED);
      }else{
        myBase->driveRight(0,0);
      }

    
    
  }
  }














  

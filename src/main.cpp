#include <FEHUtility.h>
#include <FEHServo.h>
#include <FEHLCD.h>
#include <FEHIO.h>  
#include <FEHMotor.h>  

FEHServo servo1(FEHServo::Servo0); // declare servo arm

void ERCMain()
{    
servo1.TouchCalibrate(); // calibrate servo
}
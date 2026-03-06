#include <FEH.h>
#include <FEHLCD.h> 
#include <FEHIO.h> 
#include <FEHUtility.h> 
#include <FEHMotor.h> 
#include <Arduino.h>

//Declarations for encoders & motors 

DigitalEncoder right_encoder(FEHIO::Pin10); 

DigitalEncoder left_encoder(FEHIO::Pin8); 

FEHMotor right_motor(FEHMotor::Motor0,9.0); 

FEHMotor left_motor(FEHMotor::Motor3,9.0); 

//Using encoders
void milestone1_test1(int percent, float counts) { 
    //Reset encoder counts 
    right_encoder.ResetCounts(); 
    left_encoder.ResetCounts(); 

    //Set both motors to desired percent 
    right_motor.SetPercent(percent); 
    left_motor.SetPercent(percent); 

    //While the average of the left and right encoder is less than counts, 
    //keep running motors 
    while((left_encoder.Counts() + right_encoder.Counts()) / 2. < counts); 

    //Turn off motors 
    right_motor.Stop(); 
    left_motor.Stop(); 
} 


void ERCMain()
{
    // Your code here!

    // Or just use the TestGUI function
    TestGUI();

}
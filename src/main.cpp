#include <FEH.h>
#include <FEHLCD.h> 
#include <FEHIO.h> 
#include <FEHUtility.h> 
#include <FEHMotor.h> 
#include <Arduino.h>

//Declarations for encoders & motors & CdS cell

AnalogInputPin CdS(FEHIO::Pin1);

/*DigitalEncoder right_encoder(FEHIO::Pin10); 

DigitalEncoder left_encoder(FEHIO::Pin8); 

FEHMotor right_motor(FEHMotor::Motor0,9.0); 

FEHMotor left_motor(FEHMotor::Motor3,9.0); */

//Start light read by CdS cell and final button activated
void start() { 
    //float variable x for CdS cell value and float variable base for comparison w/ x
    float x = CdS.Value();
    float base = 0.0;

    LCD.Write(base);
    while (x > 0.5) {
        x = CdS.Value();
        LCD.Write(x);
        Sleep(0.1);
        LCD.Clear();
    }

    //code to drive back and press final button, then turn to face straight toward ramp

} 

void humidifier() { 
    //float variable x for CdS cell value and float variable base for comparison w/ x
    float x = CdS.Value();
    float base = 0.0;

    //while loop to read CdS cell value and print to LCD until value is less than base (indicating light is on)
    LCD.Write(x);
    while (x > base) {
        x = CdS.Value();
        LCD.Write(x);
        Sleep(0.1);
        LCD.Clear();
    }

    //if statements for different light colors/buttons so that robot moves to the right button

} 

void ERCMain()
{
    start();
    humidifier();
}
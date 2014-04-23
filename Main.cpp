
#include <stdlib.h>
#include <stdio.h>
#include <string>
#include <iostream>

#include "Sensor.h"
#include "Motor.h"
#include "Door_latch.h"

using namespace std;

int main()
{
	string doorCond = "";
	int data[] = {100, 101, 105, 110, 210, 100, 102, 110, 150, 100};
	
	Sensor sensor;
	Motor motor;
	Door_latch door_latch;

	printf("Please indicate whether the door is closed or open\nby typing 'closed' or 'open' below:\n");
	cin >> doorCond;
	printf("\n");

	if(door_latch.DoorClosed(doorCond)){	//if door is closed
		sensor.ReadData(data);				//reads the data
		if(sensor.Calibrate()){				//once the calibration is successful, operate the motor
			printf("calibration successful!\n");
			motor.MoveMotor(sensor.motor_position());
		}else
			printf("calibration unsuccessful, please provide another set of data\n");
	}else									//if the door is open, reset the motor
	{
		motor.ResetMotor();
		printf("Door is open\n");
	}
	system("PAUSE");
}



#include "Sensor.h"
#include <math.h>
#include <iostream>


int sensor_data[10];			//Assume the data is always size 10
int data_size = 10;
float motor_position = 0;

float average(int data[], int data_size)
{

	int i;
	float result = 0;
	for( i = 0; i < data_size; i++)
		result = result + data[i];
	//printf("%f\n",result / data_size);
	return result / data_size;
}

float standard_deviation(int data[], int data_size)
{
	//printf("%d\n",sizeof(data));
	int i;
	float result = 0;
	float mean = average(data, data_size);
	for( i=0; i < data_size; i++)
		result += (data[i] - mean)*(data[i] - mean);
	//printf("%f\n",sqrt(result / data_size));
	return sqrt(result / data_size);
}

//Copy the data to the local variable
void Sensor::ReadData(int data[])
{
	int i;	
	for(i = 0; i < data_size; i++)
		sensor_data[i] = data[i];

		
}

/*Analize the data received from the sensor so that further calculations
 *can be more accurate. Here I use 95% confidence interval to test the  
 *stability of the data.If the standard deviation is greater than half 
 *of the mean, the set of data is considered invalid and return false.
 */
bool Sensor::Calibrate()
{
	int i, j;
	int original_data_size = data_size;
	int removed_count = 0;
	float mean, sd, upper_bound, lower_bound;
	mean = average(sensor_data,data_size);
	sd = standard_deviation(sensor_data, data_size);
	if(sd > mean / 2)
		return false;
	return true;
	
}

//move the motor to a position that is the average of the data received
int Sensor::motor_position()
{
	return (int)average(sensor_data,data_size);
}




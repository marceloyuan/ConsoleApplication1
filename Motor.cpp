
#include "Motor.h"
#include <stdlib.h>
#include <stdio.h>
//#include <string.h>

int motor_position = 0;

/*set the motor_position variable to 0, assuming that the motor will
 *rotate back to its initial position
 */
void Motor::ResetMotor()
{
	motor_position = 0;
	printf("motor reset complete\n");
}
/*set the motor_position variable to the distance obtained from the 
 *sensor, assuming that the motor will rotate to the required position
 */
void Motor::MoveMotor(int distance)
{
	motor_position = distance;
	printf("motor moved a distance of %d\n", distance);
}

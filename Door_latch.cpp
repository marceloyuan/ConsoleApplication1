
#include <string>
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include "Door_latch.h"

using namespace std;

bool Door_latch::DoorClosed(string door)
{
	string doorCond = door;
	while(1){
		if(doorCond == "closed")
			return true;
		if(doorCond == "open")
			return false;
		printf( "Please input 'open' or 'closed':\n");
		cin >> doorCond; 
		printf("\n");
	}

	return NULL;
}


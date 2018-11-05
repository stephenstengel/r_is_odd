/*
 * r_is_odd.c
 * 
 * Copyright 2018 Stephen Stengel <stephen.stengel@cwu.edu>
 * License: GPLv3
 * git: https://notabug.org/Ondapufo/r_is_odd
 * 
 */

/**
 * DESCRIPTION: A function that returns whether or not an int is odd or even.
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int r_is_odd(int number_to_check);

//******************************************************************************

int r_is_odd(int number_to_check)
{
	if (rand() % 100 < 1)
	{
		return rand() % 2;
	}
	
	return number_to_check % 2;
}

//******************************************************************************

int main(int argc, char **argv)
{
	time_t t;
	srand(time(&t));
	int TEST_NUMBER_EVEN = 6;
	int TEST_NUMBER_ODD = 7;
	printf("%d %d\n", r_is_odd(TEST_NUMBER_EVEN), r_is_odd(TEST_NUMBER_ODD));
	
	return 0;
}













/*
 * r_is_odd.c
 * 
 * Copyright 2018 Stephen Stengel <stephen.stengel@cwu.edu>
 * License: GPLv3
 * git: --------------------------------
 * 
 */


/**
 * Returns whether or not an input is odd or even.
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int r_is_odd(int number_to_check);

int r_is_odd(int number_to_check)
{
	//If rand is seeded here, the output will always be the same random number.
	//i.e. the second time this function is called, rand will still be the same
	//number. Why?
	//~ time_t t;
	//~ srand(time(&t));
	if (rand() % 100 < 49)
	{
		return rand() % 2;
	}
	
	return number_to_check % 2;
}

int main(int argc, char **argv)
{
	time_t t;
	srand(time(&t));
	int count_even = 0;
	int count_odd = 0;
	//~ int TEST_NUMBER_EVEN = 6;
	//~ int TEST_NUMBER_ODD = 7;
	//~ printf("%d %d\n", r_is_odd(TEST_NUMBER_EVEN), r_is_odd(TEST_NUMBER_ODD));
	for (int i = 0; i < 10000; i++)
	{
		if (r_is_odd(i))
		{
			count_odd++;
		}
		else
		{
			count_even++;
		}
	}
	printf("odd: %d even: %d\n", count_odd, count_even);
	
	return 0;
}













/*
 * r_is_odd.c
 * 
 * Copyright 2018 Stephen Stengel <stephen.stengel@cwu.edu>
 * License: GPLv3
 * github: https://github.com/stephenstengel/r_is_odd/
 * 
 */

/**
 * DESCRIPTION: A joke function that returns whether or not an int is odd or
 * even. Also; some notes.
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>

int r_is_odd(int number_to_check);

//******************************************************************************

/**
 * r_is_odd() returns 0 if even and 1 if odd. Usually.
 */
int r_is_odd(int number_to_check)
{
	if (rand() % 100 < 1)
	{
		return rand() % 2;
	}
	
	return number_to_check % 2;
}

//******************************************************************************


/**
 * This just calls the r_is_odd function to test it with a printf. Change the
 * chance to %100 < 100 to make sure it works right.
 * 
 * I'm currently investigating the differences between srand() and srandom(),
 * and rand() and random(). Apparently random() is a unix thing. I haven't
 * looked into it. random() might not work on windows.
 * 
 * I checked in the time man page and it says:
 * "The tloc argument is obsolescent and should always be NULL in new code. 
 * When tloc is NULL, the call cannot fail."
 * tloc is the given name of the input parameter for time(). So I should just
 * use NULL. This is related to the 2038 epoch problem. The only use of tloc
 * would be saving the exact time that was used for the seed. But just before
 * and just after will be close enough for most anything I think.
 * 
 * TODO: 	What is the difference between time(NULL) and time(&t) ?
 *              2019 Oct 17:
 *              &t is the address of the variable t that was created by the
 *              declaration: time_t t; It is whatever was in memory at the
 *              place where t was assigned to.
 * 
 * 			Difference between rand() random() ?
 *              2019 oct 17:
 *              Aparrently, rand() and srand() are ANSI.
 *              random() and srandom are unix.
 *https://stackoverflow.com/questions/18726102/what-difference-between-rand-and-random-functions
 * 
 * 			Why do I get a compiler warning for using sleep() ?
 *              2019 oct 17:
 *              Because the prototype for sleep() is in unistd.h and I did not
 *              include it. It still worked though!
 */
int main(int argc, char **argv)
{
	//time_t t;
	//srand(time(&t));
	//srandom(time(&t));
	
	srand(time(NULL)); //the good version

	//srandom(time(NULL));
	
	int TEST_NUMBER_EVEN = 6;
	int TEST_NUMBER_ODD = 7;
	
	for (int i = 0; i < 1000; i++)
    {
        printf("%d %d\n", r_is_odd(TEST_NUMBER_EVEN), r_is_odd(TEST_NUMBER_ODD));
    }
    
	
	//sleep(3);
	
	printf("Current UNIX time in seconds: %lu\n", time(NULL));
	
	return 0;
}













/*
 * Main.c
 *
 *
 *
 */


#include <stdio.h>
#include <stdlib.h>
#include "InsertionSort.h"
#include "MergeSort.h"

int main( int argc, char **argv ) {


	puts("Welcome");

	int test[11] = {1,4,8,3,4,456,1,4,88,434,10};

	//insertion sort result
	puts("Insertion sort results: ");
	performInsertionSort(argc, argv);



	puts("\nMerge sort results: ");

	performMergeSort(argc, argv);


	return 1;



}

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

int main( int argc, const char* argv[] ) {


	puts("Welcome");

	int test[11] = {1,4,8,3,4,456,1,4,88,434,10};

	//insertion sort result
	int *iSResult = insertionSort(test, 11);
	puts("Insertion sort results: ");

	for(int i = 0; i<11; i++){

		printf("%d, ",iSResult[i]);
	}

	puts("\nMerge sort results: ");

	int * mSResult = performMergeSort(test, 11);

	for(int i = 0; i<11;i++){
		printf("%d, ",mSResult[i]);
	}

	return 1;



}

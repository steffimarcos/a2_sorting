/*
 * MergeSort.c
 *
 *  Created on: Oct 11, 2018
 *  Edited on: Oct 15, 2018
 *      Author: Louai
 */


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "MergeSort.h"

//Function Prototypes
//void merge(int originalArr[], int arr1Start, int arr1End, int arr2End);
//void mergeSort(int arr[], int startIndex, int endIndex);
//int performMergeSort(int argc, char **argv);



//Main
void performMergeSort(int argc, char **argv) {

	if (argc != 3) {

		puts("USAGE: sorting [# of Numbers to Read] [File to Read From]");


	} else {

		int numOfTrials = 300;
		int timeElapsedResultSet[numOfTrials];
		int sum = 0;
		double average = 0;

		for (int trialCounter=0; trialCounter < numOfTrials; trialCounter++) {

			FILE * inputFile = fopen(argv[2], "r");
			FILE * outputFile = fopen("sortedOutput.txt", "w");
			clock_t start;
			double timeElapsed;


			long numToRead = strtol(argv[1], NULL, 10);
			if (inputFile == NULL) {
				puts("ERROR: No input file provided or file does not exist.");
				exit(1);
			} else if (numToRead < 2 || numToRead > 800000) {
				puts("The quantity of numbers to be read from the file must be between 2 and 800,000, inclusive.");
				exit(2);
			} else {
				int inputArray[numToRead];
				int numReadCounter = 0;
				while (numReadCounter < numToRead) {

					fscanf(inputFile, "%d", &inputArray[numReadCounter]);
					numReadCounter++;
				}

				start = clock();
				mergeSort(inputArray, 0, numToRead - 1);
				timeElapsed = ((double)clock() - start);
				timeElapsedResultSet[trialCounter] = timeElapsed;



				for (int i=0; i<numToRead; i++) {
					fprintf(outputFile,"%d\n", inputArray[i]);
				}

				puts("Input Sorted! See sortedOutput.txt in current directory.");

			}

			fclose(inputFile);
			fclose(outputFile);

		}

		for (int i = 0; i < numOfTrials; i++) {
			printf("%d ", timeElapsedResultSet[i]);
			sum = sum + timeElapsedResultSet[i];
		}
		average = sum / numOfTrials;
		puts("");
		printf("%s%f\n", "Average: ", average);

	}


}

//Merge: A function that merges two sorted subarrays into a single sorted array.
//The orignal user-provded array is given as well 3 parameters that define how a segment of
//the full array is divided into two sorted subarrays. These sorted subarrays are merged into
//one sorted subarray by the merge algorithm.
void merge(int originalArr[], int arr1Start, int arr1End, int arr2End) {

	//Computing the sizes of the subarrays to be merged in sorted order
	int arr1Size = arr1End - arr1Start + 1;
	int arr2Size = arr2End - arr1End;

	//Creating two temporary arrays
	int arr1[arr1Size];
	int arr2[arr2Size];

	//Loading data into temporary arrays from original array
	for (int i = 0; i < arr1Size; i++) {
		arr1[i] = originalArr[i + arr1Start];
	}

	for (int j = 0; j < arr2Size ; j++) {
		arr2[j] = originalArr[j + arr1End + 1];
	}

	//Declaring and Initializing Retrieval Position Keepers and Insertion Position Keepers
	int arr1Position = 0;
	int arr2Position = 0;
	int mergArrInsertPosition = arr1Start;


	//The following overwrites the two sorted subarrays with a combined sorted version of the two.
	//The first two elements that have yet to be inserted back into the original array are compared.
	//Always, the smaller element is inserted, the relevant retrieval position keeper is incremented
	//by 1 and the original arrays position insertion keeper is also incrmeented by 1. if there is a
	//TIE (two elements are equal), then both elements are inserted and the retrival position keeper
	//for both temporary arrays is incremented by 1 and the insertion position keeper in the original
	//array is incremented by 2.
	//Note: loops terminate once the retrival position counter equals the size of the array.
	while ((arr1Position < arr1Size) && (arr2Position < arr2Size)) {

		if (arr1[arr1Position] < arr2[arr2Position]) {

			originalArr[mergArrInsertPosition] = arr1[arr1Position];
			arr1Position++;


		} else {

			originalArr[mergArrInsertPosition] = arr2[arr2Position];
			arr2Position++;


		}
		mergArrInsertPosition++;
	}

	//The following two while loops are required in case there remains any uninserted elements in
	//temporary subarrays. This occurs if one array "empties" before the other.
	while (arr1Position < arr1Size) {

		originalArr[mergArrInsertPosition] = arr1[arr1Position];
		arr1Position++;
		mergArrInsertPosition++;


	}

	while (arr2Position < arr2Size) {

		originalArr[mergArrInsertPosition] = arr2[arr2Position];
		arr2Position++;
		mergArrInsertPosition++;


	}

}


//MergeSort: an algorithm that sorts an array in non-decreasing
//order using the divide and conquer method
void mergeSort(int arr[], int startIndex, int endIndex) {

	if (endIndex > startIndex) {

		//int arr1End = startIndex + (endIndex - startIndex)/2;
		int arr1End = (startIndex + endIndex)/2;
		mergeSort(arr, startIndex, arr1End);
		mergeSort(arr, arr1End+1, endIndex);
		merge(arr, startIndex, arr1End, endIndex);
	}

}

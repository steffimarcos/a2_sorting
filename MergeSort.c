/*
 * MergeSort.c
 *
 *  Created on: Oct 11, 2018
 *  Edited on: Oct 15, 2018
 *      Author: Louai
 */


#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>

//Function Prototypes
void merge(int originalArr[], int arr1Start, int arr1End, int arr2End);
void mergeSort(int arr[], int startIndex, int endIndex);



//Main
int main(void) {

	int sample[12] = {1, 5, 2, 4, 3, 1232, 23, 77,8, 2, 5, 25678};
	puts("Unsorted Sample: ");
	for (int j=0; j<12; j++) {
		printf("%d ", sample[j]);
	}

	puts("");

	mergeSort(sample, 0, 11);

	puts("\nSorted Sample: ");
	for (int i=0; i<12; i++) {
		printf("%d ", sample[i]);
	}
	puts("");
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
	int arr1[1000000];
	int arr2[1000000];

	//Loading data into temporary arrays from original array
	for (int i = 0; i < arr1Size; i++) {
		arr1[i] = originalArr[i + arr1Start];
	}

	puts("Calling Merge:");

	for (int m = 0; m < arr1Size; m++) {
		printf("%d ", arr1[m]);
	}

	puts("");

	for (int j = 0; j < arr2Size ; j++) {
		arr2[j] = originalArr[j + arr1End + 1];
	}

	for (int n = 0; n < arr2Size; n++) {
		printf("%d ", arr2[n]);
	}

	puts("");

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

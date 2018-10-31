/*
 * InsertionSort.c
 *
 *  Created on: Oct 11, 2018
 *      Author: Keifer
 *
 *
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "InsertionSort.h"

	void performInsertionSort(int argc, char **argv){

		if (argc != 3) {

				puts("USAGE: sorting [# of Numbers to Read] [File to Read From]");


			} else {

				int numOfTrials = 300;
				int timeElapsedResultSet[numOfTrials];
				int sum = 0;
				double average = 0;

				for (int trialCounter=0; trialCounter < numOfTrials; trialCounter++) {

					FILE * inputFile = fopen(argv[2], "r");
					FILE * outputFile = fopen("sortedOutput2.txt", "w");
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
						insertionSort(inputArray, numToRead);
						timeElapsed = ((double)clock() - start);
						timeElapsedResultSet[trialCounter] = timeElapsed;



						for (int i=0; i<numToRead; i++) {
							fprintf(outputFile,"%d\n", inputArray[i]);
						}

						puts("Input Sorted with Insertion Sort! See sortedOutput.txt in current directory.");

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

	int * insertionSort(int * arr, int n){
		int temp=0;
		int index;
		//puts("unsorted array");

		if(arr == NULL || n == 1){
			return arr;
		}
		else{

			//loop through the array
			for(int i = 1; i<n;i++){
				//printf("selector is at %d\n", i);
				index = i-1;
				temp=arr[i];

				//at each index, find the place where it should be inserted
				//test to see if the "to be inserted" value is greater
				//than every other value in the "sorted portion"
				while(index>=0 && arr[index]>temp){

					arr[index+1]=arr[index];
					//printf("shifting %d at index %d to index %d\n",arr[index],index,(index+1));
					//printf("inserting %d at index %d\n",temp,index );
						//insert the new value
					index--;
					}
				//when you find a value of arr[index] is less than arr[i] insert
				//it after that value
				arr[index+1]=temp;


			}
		}
		return arr;
	}








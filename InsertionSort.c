/*
 * InsertionSort.c
 *
 *  Created on: Oct 11, 2018
 *      Author: Keifer
 *
 *
 */
#include <stdio.h>
#include "InsertionSort.h"


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








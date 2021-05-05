#include <stdio.h>
#include <stdlib.h>

int ops,cops = 0;									// operações, cópias
int size = 10;

void findMultiples(int* array, int* n){
	for(int i = 0; i < *n; i++){
		for(int j = i + 1 ; j < *n; j++){
			ops++;
			
			if(array[i] % array[j] == 0 || array[j] % array[i] == 0){	//if multiple
				for(int k = j; k < (*n) -1 ; k++){         		//push element
					array[k] = array[k+1];
					cops++;
				}
			j--;								//decrement so new j position is tested
			(*n)--;								//decrease n elements
			}
		}	
	}
}

void printArray(int* array, int n){							//print array
	for(int i = 0;i < n -1;i++){
		printf("%d,  ", array[i]);
	}
	
	printf("%d", array[n - 1]);
}

void arrayTest(int* array){								//testing algorithm				
	ops = 0;
	cops = 0;
	int n = size;
	
	printf("\nFirst Array: ");
	printArray(array, n);
	printf("\nFinal Array: ");
	findMultiples(array, &n);
	printArray(array,n);
	printf("\nComparisons: %d \nCopies: %d \nSize of final array: %d", ops, cops, n);
	printf("\n---------------------------------------------------------\n");
}

int main(void){										//main
	int array1[10] = {2,2,2,3,3,4,5,8,8,9};						//{2,3,5}
	int array2[10] = {7,8,2,2,3,3,3,8,8,9};						//{7,8,3}
	int array3[10] = {2,5,6,2,8,7,4,2,13,10};					//{2,5,7,13}
	int array4[10] = {2,3,5,7,11,13,17,19,23,29};					//{2,3,5,7,11,13,17,19,23,29}
	int array5[10] = {2,2,2,2,2,2,2,2,2,2};						//{2}
	arrayTest(array1);
	arrayTest(array2);
	arrayTest(array3);
	arrayTest(array4);
	arrayTest(array5);
	exit (EXIT_SUCCESS);
	
}

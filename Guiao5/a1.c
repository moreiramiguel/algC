#include <stdio.h>

int n, ops = 0;										//elementos n, operações


int propertiesTest(int array[], int n){							
	if(n == 1)									//if only 1 element return 1
		return 1;

	int r = array[1]/array[0];							//ratio(razão)

	for(int i =1; i < n; i++){							
		ops++;
			if(array[i]/array[i-1] != r){					//checks if its arithmetic progression by checking n and n+1 ratio with the previous ratio established
				return 0;
				
			}
			
			
	}
	return 1;
}


void arrayTest(int array[],int n){							//test the array and print
	ops = 0;
	int res = propertiesTest(array, n);
	printf("Result: %d Comparisons: %d \n",res, ops);
}

int main(void){										//main program

	int array[10] = {1,2,4,8,16,32,64,128,256,512};	 /*
	int array[10] = {1,2,3,4,5,6,7,8,9,10};	
	int array[10] = {1,2,4,4,5,6,7,8,9,10};
	int array[10] = {1,2,4,8,5,6,7,8,9,10};
	int array[10] = {1,2,4,8,16,6,7,8,9,10};
	int array[10] = {1,2,4,8,16,32,7,8,9,10};
	int array[10] = {1,2,4,8,16,32,64,8,9,10};
	int array[10] = {1,2,4,8,16,32,64,128,9,10}
	int array[10] = {1,2,4,8,16,32,64,128,256,10}; 
	int array[10] = {1,2,4,8,16,32,64,128,256,512}; 
	*/

	arrayTest(array,10);

	return 0;

}

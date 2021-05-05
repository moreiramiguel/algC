#include <stdio.h>

int size = 10;
int ops = 0;


int propertiesTest(int* array, int size){
	int cnt = 0;
	for(int i =0; i < size; i++){
		int k = i+1;
		ops++;
		for(int j = i; j > 0; j--){
			if(array[k] == array[i]+array[j] ){
				cnt++;
			}
		
	}
}

	return cnt;


}


void arrayTest(int* array){
	ops = 0;
	int res = propertiesTest(array, size);
	printf("Result: %d Comparisons: %d \n", res, ops);
}

int main(void){

	int array[10] = {0,0,0,0,0,0,0,0,0,0};/*
	int array[10] = {1,2,3,4,5,6,7,8,9,10};	
	int array[10] = {1,2,1,4,5,6,7,8,9,10};
	int array[10] = {1,2,1,3,2,6,7,8,9,10};
	int array[10] = {0,2,2,0,3,3,0,4,4,0};
	int array[10] = {0,0,0,0,0,0,0,0,0,0}; */

	arrayTest(array);

	return 0;

}

#include <stdio.h>
#include <stdlib.h>
//recursive version
/*
       |1 if n = 0,1,2
	   |
F(n) = |
	   |
       |F(n-1) + F(n-2) + Sum[F(k) * F(n-3-k)] , if n > 2, so k starts at 0 with n = 3
*/

int mult;

int recFunction(int n){																			/*Recursive Function with a for to act as the sum, returns the function value and the multiplications*/
	if(n <= 2){																						
		return 1;
	}

	else{
		for(int k = 0;k <= n;k++){																	
			mult++;
			return recFunction(n-1) + recFunction(n-2) + recFunction(k)*recFunction(n-3-k);
		}
	}
	return mult;
}

int main(void){																					/*main program with simple printf for values 0 to 25 */
	mult = 0;
	for(int i = 0; i <= 25;i++){
		printf("F(%d): %d	Multiplications: %d \n", i, recFunction(i),mult);
	}
}
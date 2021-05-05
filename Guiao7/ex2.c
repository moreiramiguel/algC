#include <stdio.h>
#include <stdlib.h>
//dynamic programming version
/*
       |1 if n = 0,1,2
	   |
F(n) = |
	   |
       |F(n-1) + F(n-2) + Sum[F(k) * F(n-3-k)] , if n > 2, so k starts at 0 with n = 3
*/

int mult;																				//multiplications == f[n]*f[n-3-k]

int dynfunction(int n){																	/*with dynamic programming we memorize the numbers in a array instead of calling the fuction itself*/

	int f[n];																			/*nested loop for numbers with n > 2 and for the sum, so the i which is the n starts at 3 but the k for the sum starts at 0*/
	int i,k;																			// i = n , n<2

	f[0] = 1;
	f[1] = 1;
	f[2] = 1;

	for(i = 3; i <=n; i++){
		for(k = 0; k <= i-3;k++){
			f[i] = f[i-1] + f[i-2] + f[k]*f[i-3-k];
			mult++;
		}
	}	

	return f[n];

}



int main(void){																			/*main program with simple printf for values 0 to 25 */																
	mult = 0;
	for(int i = 0; i <= 25;i++){
		printf("F(%d): %d	Multiplications: %d \n", i, dynfunction(i),mult);
	}
}
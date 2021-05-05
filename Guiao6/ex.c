#include <stdio.h>
#include <stdlib.h>

int size = 28;																				//tamanho da pequisa
int calls1,calls2,calls3;																	//chamadas

unsigned int algoritmoT1(unsigned int n){													//Algoritmo T1(n): 0 se n = 0
	calls1++;																				//			   T1(n/4) + n se n > 0
	if(n == 0){	
		return 0;
	}
	return algoritmoT1(n/4) + n;
}

unsigned int algoritmoT2(unsigned int n){													//Algoritmo T2(n): n se n = 0,1,2,3
	calls2++;																				//				T2(n/4) + T2((n+3) / 4) + n se n > 3
	if(n <= 3){
		return n;
	}
	return algoritmoT2(n/4) + algoritmoT2((n+3)/4) + n;
}

unsigned int algoritmoT3(unsigned int n){													//Algoritmo T3(n): n se n = 0,1,2,3
	calls3++;																				//				2*T3(n/4) + n se n multiplo de 4
	if(n <= 3){																				//				T3(n/4) + T3((n+3) /4) + n para o resto
		return n;
	}
	if((n%4)==0){
		return 2 * algoritmoT3(n/4) + n;
	}
	return n + algoritmoT3(n/4) + algoritmoT3((n+3)/4);
}

int main(void){																				//main program
	for(int n = 0; n <= size;n++){
		printf("FormulaT1 (%d) : %d 	calls: %d 	FormulaT2 (%d) : %d 	calls: %d 	FormulaT3 (%d) : %d 	calls: %d \n",n,algoritmoT1(n),calls1,n,algoritmoT2(n),calls2,n,algoritmoT3(n),calls3);
	}
	exit(EXIT_SUCCESS);

}
/*
EXERCÍCIO EM MONITORIA - 30/08/2016

Multiplicação de Matrizes

PSEUDOCÓDIGO:

MULT_MATRIZES(A, la, ca, B, lb,cb, C )
para lc <- 0 até la faça
      para cc <- 0 até cb faça
           para k <- 0 até lb faça
                  C[lc][cc] <- C[lc][cc] + A[lc][k]*B[k][cc]


Exercício:
PARTE I: Implemente o algoritmo de multiplicação de matrizes e analise o tempo para matrizes de tamanho diferentes.
PARTE II: Analise o algoritmo e dê a ordem de grandeza pra operação de mutiplicação de matrizes.
*/

#include <iostream>
#include <ctime>
using namespace std;
#define la 2
#define ca 2
#define lb 2
#define cb 2

void multiplicar_matriz(int A[la][ca], int B[lb][cb], int C[la][cb]){
	for(int lc = 0; lc < la; lc++){
		for(int cc = 0; cc < cb; cc++){
			for(int k = 0; k < lb; k++){
				C[lc][cc] = C[lc][cc] + (A[lc][k]*B[k][cc]);
			}
		}
	}
}

void inicializa_matriz(int A[la][ca], int valor){
	for(int i = 0; i < la; i++)
		for(int j = 0; j < ca; j++)
			A[i][j] = valor;
}

void imprimi_matriz(int C[la][cb]){
	for(int i = 0; i < la; i++){
		for(int j = 0; j < cb; j++){
			cout << C[i][j] << " ";
		}
		cout << endl;
	}
}

int main(){

	int A1[la][ca] = {{2,3}, {4,5}};
	int B1[lb][cb] = {{6,7}, {8,9}};
	int C1[la][cb];
	
	//inicializa_matriz(A1, 1);
	//inicializa_matriz(B1, 1);
	inicializa_matriz(C1, 0);
	
	clock_t begin1 = clock();
	multiplicar_matriz(A1, B1, C1);
	clock_t end1 = clock();

	cout << "Tempo Matriz A1[" << la << "][" << ca << " * B1[" << lb << "][" << cb << "] = " << (end1 - begin1) << endl;
	imprimi_matriz(C1);
	
	/*
	int A2[la][ca]; int B2[lb][cb];
	int C2[la][cb];

	inicializa_matriz(A2, 1);
	inicializa_matriz(B2, 1);
	inicializa_matriz(C2, 0);

	clock_t begin2 = clock();
	multiplicar_matriz(A2, B2, C2);
	clock_t end2 = clock();

	imprimi_matriz(C1);

	cout << "Tempo Matriz A2[" << la << "][" << ca << " * B2[" << lb << "][" << cb << "] = " << (end2 - begin2) << endl;	
	*/
	return 0;
}
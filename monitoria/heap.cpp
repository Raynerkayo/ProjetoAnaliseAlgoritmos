#include <iostream>
#include <stdlib.h>
#include <ctime>
using namespace std;
#define N 200000

void make_max_heap(int A[], int n);
void max_heapify(int A[], int n, int i);
void heapsort(int A[], int n);
void swap(int A[], int a, int b);

void make_max_heap(int A[], int n){
	for(int i = n/2; i >= 1; i--){
		max_heapify(A, n, i);
	}
}

void max_heapify(int A[], int n, int i){
	int esq = 2*i, dir = 2*i + 1, maior = i;
	if(esq <= n && A[esq] > A[maior])
		maior = esq;
	if(dir <= n && A[dir] > A[maior])
		maior = dir;
	if(maior != i){
		swap(A, i, maior);
		max_heapify(A, n, maior);
	}
}

void heapsort(int A[], int n){
	make_max_heap(A, n);
	for(int tam_heap = n; tam_heap >= 2; tam_heap --){
		swap(A, 1, tam_heap);
		max_heapify(A, tam_heap-1, 1);
	}
}

void swap(int A[], int a, int b){
	int aux = A[a];
	A[a] = A[b];
	A[b] = aux;
}

void insercao(int A[], int n){
	int chave, i, j;
	for(j = 2; j <= n; j++){
		chave = A[j];
		for(i = j-1; (i >= 1) && (A[i] > chave); i--){
			A[i+1] = A[i];
		}

		A[i+1] = chave;
	}
}

void inicializar(int A[]){
	A[0] = 0;	
	for (int i = 1; i < N; i++) A[i] = rand();
}


int main(){
	//int A[] = {0, 46, 12, 13, 14, 10, 21, 43, 36, 25, 42, 26, 39};
	int A[N];
	int B[N];
	inicializar(A);
	inicializar(B);
	
	clock_t begin_insertion = clock();		
	insercao(A, N-1);
	clock_t end_insertion = clock();	


	clock_t begin_heap = clock();
	heapsort(B, N-1);
	clock_t end_heap = clock();	
	
	cout << "Tempo insertion sort: " << (1.0*(end_insertion - begin_insertion))/CLOCKS_PER_SEC << endl;
	cout << "Tempo Heap Sort: " << (1.0*(end_heap - begin_heap))/CLOCKS_PER_SEC << endl;
	//for(int i = 0; i < N; i++){
	//	cout << A[i] << " ";
	//}
	return 0;
}
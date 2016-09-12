/*Exercicio de Grafos para calcular o tempo da matriz e lista transposta de um grafo direcionado*/


#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include <list>
#include <ctime>
using namespace std;

#define DENSIDADE 0.1
#define N 100

void gerar_complemento_grafo(char A[N][N], char C[N][N]){
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            C[i][j] = !(A[i][j]);
        }
    }
}

void gerar_grafo_direcionado_matriz(char A[N][N]){
    srand(123456789);
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            A[i][j] = ((double) rand()  / RAND_MAX) < DENSIDADE;
        }
    }
}

/*
// Copia o grafo na matriz de adjacencias p/ a lista de adj.
// Assume matriz inicializada com zeros.
void copia_grafo_mat_lista(char A[N][N], list<int> *Adj) {
   for (int i = 0; i < N; i++)
      for (int j = 0; j < N; j++)
         if (A[i][j]) Adj[i].push_back(j);
}

/*
void fazer_transposta_matriz(char A[N][N], char At[N][N]){
    for(int i = 0; i < N; i++){
        for(int j = i; j < N; j++){
            if(A[i][j]){
                At[j][i] = 1;
            }
        }
    }
}

/*
void fazer_transposta_lista(list<int> *Adj, list<int> *AdjT){
    list<int>::iterator it;
    for(int i = 0; i < N; i++){
        for(it = Adj[i].begin(); it != Adj[i].end(); it++){
            AdjT[*it].push_back(i);
        }
    }
}
*/


int main(){

char A[N][N];
char C[N][N];

gerar_grafo_direcionado_matriz(A);

clock_t begin = clock();
gerar_complemento_grafo(A,C);
clock_t end = clock();

cout << "Tempo total: " << end - begin << endl;
return 0;

/*
enum Vertices {a,b,c,d,e};

list<int> Adj[N];

gerar_grafo_direcionado_matriz(A);
copia_grafo_mat_lista(A, Adj);

char At[N][N] = {0};
list<int> AdjT[N];

clock_t begin_m = clock();

fazer_transposta_matriz(A, At);

clock_t end_m = clock();

clock_t begin_l = clock();

fazer_transposta_lista(Adj, AdjT);

clock_t end_l = clock();

int resultado = (end_m - begin_m);
cout << "matriz " << resultado << endl;

resultado = (end_l - begin_l);
cout << "lista " << (resultado) << endl;

return 0;
*/

}

#include <iostream>
#include <list>
#include <ctime>
using namespace std;

#define N 9


/*Enumeracoes*/
enum Cores{branco, cinza, preto};
enum Pecas{cueca,calca,cinto,camisa,gravata,paleto,meias,sapatos,relogio};

list<int> Adj[N];
Cores cor[N];
int d[N]; //tempo inicial em que o vertice foi acessado
int f[N]; //tempo em que o vertice foi finalizado
int pi[N];
int tempo = 0;
char conjunto[N];

/*Assinatura funçoes*/
bool DFS_VISIT_BIPARTIDO(int u);
bool DFS_BIPARTIDO();
void inicializa_grafo();
void imprime_ciclo_impar(int u, int v);

/*Implementacao funcoes*/
bool DFS_VISIT_BIPARTIDO(int u){
	list<int>::iterator it;
	cor[u] = cinza;
	d[u] = tempo++;
	
	for(it=Adj[u].begin(); it != Adj[u].end(); it++){
		if(cor[*it] == branco){
			pi[*it] = u;
			conjunto[*it] = (conjunto[u] == 'A') ? 'B' : 'A';
			if(!DFS_VISIT_BIPARTIDO(*it)){
				return false;
			}
		}else if(conjunto[*it] == conjunto[u]){
			imprime_ciclo_impar(u, *it);
			return false; //Contem ciclo impar
		}		
	}
	
	cor[u] = preto;
	f[u] = tempo++;

	return true;
}

bool DFS_BIPARTIDO(){
	list<int>::iterator it;
	
	for(int u = 0; u < N; u++){
		cor[u] = branco;
		pi[u] = -1;		
	}

	conjunto[0] = 'A'; //primeiro vertice em A
	
	for(int u = 0; u < N; u++){
		if(cor[u] == branco){
			if(!DFS_VISIT_BIPARTIDO(u)){
				return false;
			}
		}
	}

	return true;
}

void imprime_ciclo_impar(int u, int v){
	if(u == v){
		cout << "u";
	}

	int w = v;
	while(w!=u){
		cout << w;
		w = pi[w];
	}

	cout << w;
}

void inicializa_grafo()
{
   Adj[cueca].push_back(calca);
   Adj[cueca].push_back(sapatos);
   Adj[calca].push_back(sapatos);
   Adj[calca].push_back(cinto);
   Adj[cinto].push_back(paleto);
   Adj[camisa].push_back(cinto);
   Adj[camisa].push_back(gravata);
   Adj[gravata].push_back(paleto);
   Adj[meias].push_back(sapatos);

}

int main(){
	inicializa_grafo();
	if(DFS_BIPARTIDO())
		cout << "true" << endl;
	else
		cout << "false" << endl;

	return 0;
}
#include <iostream>
#include <list>
#include <ctime>
using namespace std;

#define N 8


/*Enumeracoes*/
enum Cores{branco, cinza, preto};
enum V{s,w,r,t,x,v,u,y};

list<int> Adj[N];
Cores cor[N];
int d[N]; //tempo inicial em que o vertice foi acessado
int f[N]; //tempo em que o vertice foi finalizado
int pi[N];
int tempo = 0;

/*Assinatura funçoes*/
void DFS_VISIT(int u);
void DFS();
void inicializa_grafo();

/*Implementacao funcoes*/
void DFS_VISIT(int u){
	list<int>::iterator it;
	cor[u] = cinza;
	d[u] = tempo++;
	
	for(it=Adj[u].begin(); it != Adj[u].end(); it++){
		if(cor[*it] == branco){
			pi[*it] = u;
			DFS_VISIT(*it);
		}	
	}

	cor[u] = preto;
	f[u] = tempo++;
}

void DFS(){
	list<int>::iterator it;
	for(int u = 0; u < N; u++){
		for(it=Adj[u].begin(); it != Adj[u].end(); it++){
			cor[*it] = branco;
			pi[*it] = -1;	
		}		
	}

	tempo = 0;

	for(int u = 0; u < N; u++){
		for(it=Adj[u].begin(); it != Adj[u].end(); it++){
			if(cor[*it] == branco){
				DFS_VISIT(*it);
			}	
		}		
	}

}

void inicializa_grafo()
{
   Adj[s].push_back(w);
   Adj[s].push_back(r);
   Adj[r].push_back(s);
   Adj[r].push_back(v);
   Adj[v].push_back(r);
   Adj[w].push_back(s);
   Adj[w].push_back(t);
   Adj[w].push_back(x);
   Adj[t].push_back(w);
   Adj[t].push_back(x);
   Adj[t].push_back(u);
   Adj[x].push_back(w);
   Adj[x].push_back(t);
   Adj[x].push_back(u);
   Adj[x].push_back(y);
   Adj[u].push_back(t);
   Adj[u].push_back(x);
   Adj[u].push_back(y);
   Adj[y].push_back(x);
   Adj[y].push_back(u);
}

int main(){
	inicializa_grafo();

	clock_t begin = clock();
	DFS();
	clock_t end = clock();

	cout << "tempo: " << (end - begin) << endl;
	cout << "d: ";
	for(int i = 0; i < N; i++){
		cout << d[i] << " ";
	}
	cout << endl;
	cout << "f: ";
	for(int i = 0; i < N; i++){
		cout << f[i] << " ";
	}
	cout << endl;

	return 0;
}

#include <iostream>
#include <list>
#include <vector>
#include <algorithm>
using namespace std;

struct Node {
   struct Node *pai;
   int rank;
   char c; // identificador
};

struct Aresta {
   int u;
   int v;
   int peso;
};

#define N 7
void UNION(int x, int y);
int FIND_SET(int x);
void MAKE_SET(int x);
void LINK(int x, int y);
void inicializa_arestas();
void inicializa_grafo();
bool comp_aresta(Aresta i, Aresta j);

list<Aresta> Adj[N];
vector<Aresta> arestas;
int pai[N];
int rank[N];




bool comp_aresta(Aresta i, Aresta j)
{
   return i.peso < j.peso;
}

void inicializa_arestas()
{
   for (int u = 0; u < N; u++)
      for (list<Aresta>::iterator e = Adj[u].begin(); e != Adj[u].end(); e++)
         if (u < e->v) arestas.push_back(*e);
}

void inicializa_grafo(){
   enum Vertices {a,b,c,d,e,f,g,h,i};
                //0 1 2 3 4 5 6 7 8
   Adj[a].push_back((Aresta){a,b,4});
   Adj[a].push_back((Aresta){a,h,8});
   Adj[b].push_back((Aresta){b,a,4});
   Adj[b].push_back((Aresta){b,c,8});
   Adj[b].push_back((Aresta){b,h,11});
   Adj[c].push_back((Aresta){c,b,8});
   Adj[c].push_back((Aresta){c,d,7});
   Adj[c].push_back((Aresta){c,f,4});
   Adj[c].push_back((Aresta){c,i,2});
   Adj[d].push_back((Aresta){d,c,7});
   Adj[d].push_back((Aresta){d,e,9});
   Adj[d].push_back((Aresta){d,f,14});
   Adj[e].push_back((Aresta){e,d,9});
   Adj[e].push_back((Aresta){e,f,10});
   Adj[f].push_back((Aresta){f,c,4});
   Adj[f].push_back((Aresta){f,d,14});
   Adj[f].push_back((Aresta){f,e,10});
   Adj[f].push_back((Aresta){f,g,2});
   Adj[g].push_back((Aresta){g,f,2});
   Adj[g].push_back((Aresta){g,h,1});
   Adj[g].push_back((Aresta){g,i,6});
   Adj[h].push_back((Aresta){h,a,8});
   Adj[h].push_back((Aresta){h,b,11});
   Adj[h].push_back((Aresta){h,g,1});
   Adj[h].push_back((Aresta){h,i,7});
   Adj[i].push_back((Aresta){i,c,2});
   Adj[i].push_back((Aresta){i,g,6});
   Adj[i].push_back((Aresta){i,h,7});
   inicializa_arestas();
}

void inicializa_grafo_novo(){
   enum Vertices {a,b,c,d,e,f,g};
                //0 1 2 3 4 5 6
   Adj[a].push_back((Aresta){a,b,5});
   Adj[a].push_back((Aresta){a,f,8});
   
   Adj[b].push_back((Aresta){b,a,5});
   Adj[b].push_back((Aresta){b,f,10});
   Adj[b].push_back((Aresta){b,g,3});
   Adj[b].push_back((Aresta){b,c,16});


   Adj[c].push_back((Aresta){c,b,16});
   Adj[c].push_back((Aresta){c,g,30});
   Adj[c].push_back((Aresta){c,d,26});

   Adj[d].push_back((Aresta){d,c,26});
   Adj[d].push_back((Aresta){d,g,14});
   Adj[d].push_back((Aresta){d,e,4});

   Adj[e].push_back((Aresta){e,d,4});
   Adj[e].push_back((Aresta){e,g,12});
   Adj[e].push_back((Aresta){e,f,18});

   Adj[f].push_back((Aresta){f,e,18});
   Adj[f].push_back((Aresta){f,g,2});
   Adj[f].push_back((Aresta){f,a,8});
   Adj[f].push_back((Aresta){f,b,10});

   Adj[g].push_back((Aresta){g,b,3});
   Adj[g].push_back((Aresta){g,f,2});
   Adj[g].push_back((Aresta){g,c,30});
   Adj[g].push_back((Aresta){g,d,14});
   Adj[g].push_back((Aresta){g,e,12});

   inicializa_arestas();
}


void MAKE_SET(int x){
	pai[x] = x;
	rank[x] = 0;
}

void UNION(int x, int y){
	LINK(FIND_SET(x), FIND_SET(y));
}

void LINK(int x, int y){
	if(rank[x] > rank[y]) pai[y] = x;
	else pai[x] = y;
	if(rank[x] == rank[y]) rank[y] = rank[y] + 1;
}

int FIND_SET(int x){
	if(pai[x] != x) pai[x] = FIND_SET(pai[x]);
	return pai[x];
}

void KRUSKAL(){
	for(int i = 0; i < N; i++) MAKE_SET(i);
	sort(arestas.begin(), arestas.end(), comp_aresta);
	for(int i = 0; i < arestas.size(); i++){
		if(FIND_SET(arestas.at(i).u) != FIND_SET(arestas.at(i).v)){
			cout << "(" << arestas.at(i).u << "," << arestas.at(i).v << ")" << endl;
			UNION(arestas.at(i).u,arestas.at(i).v);
		}
	}
}

int main(){
	//inicializa_grafo();
	inicializa_grafo_novo();
	KRUSKAL();
	return 0;
}
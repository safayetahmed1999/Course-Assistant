#include<bits/stdc++.h>
using namespace std;

typedef pair<int,int>edgeWightpair;

class Graph{
    int V;
    list<edgeWightpair> *adj;
public: 
    Graph(int V){
        this->V = V;
        adj = new list<edgeWightpair>[V];
    }
public:
    void addEdge(int u,int v,int w){
        adj[u].push_back(make_pair(v,w));
        adj[v].push_back(make_pair(u,w));
    }
    void primMST(){
       priority_queue<edgeWightpair,vector<edgeWightpair>,greater<edgeWightpair>> pq;
       int src = 0;
       vector<int> key(V,INT_MAX);
       vector<int> parent(V,-1);
       vector<bool>inMST(V,false);
       pq.push(make_pair(0,src));
       key[src] = 0;
       while(!pq.empty()){
            int u = pq.top().second;
            pq.pop();
            if(inMST[u]==true){
                continue;
            }
            inMST[u] = true;
            list<pair<int,int>>::iterator i;
            for(i= adj[u].begin();i!=adj[u].end();i++){
                int v = (*i).first;
                int weight = (*i).second;
                if(inMST[v] == false && key[v]>weight){
                    key[v] = weight;
                    pq.push(make_pair(key[v],v));
                    parent[v] = u;
                }
            }
       }
       for(int i=1;i<V;i++){
         cout<<parent[i]<<" "<<i<<endl;
       }
    }
};

int main(){
    int V = 9;
    Graph g(V);
    g.addEdge(0, 1, 4);
    g.addEdge(0, 7, 8);
    g.addEdge(1, 2, 8);
    g.addEdge(1, 7, 11);
    g.addEdge(2, 3, 7);
    g.addEdge(2, 8, 2);
    g.addEdge(2, 5, 4);
    g.addEdge(3, 4, 9);
    g.addEdge(3, 5, 14);
    g.addEdge(4, 5, 10);
    g.addEdge(5, 6, 2);
    g.addEdge(6, 7, 1);
    g.addEdge(6, 8, 6);
    g.addEdge(7, 8, 7);
    g.primMST();

}
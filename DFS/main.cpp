#include "iostream"
using namespace std;

bool Visited[100]={0};

//Edge define
typedef struct ENode{
    int V1,V2;
    int Weight;
}*Edge;

//AdjVNode define
typedef struct AdjVNode{
    int V;
    int Weight;
    struct AdjVNode *Next;
}*ANode;

//List head Vertex define
typedef struct VNode{
    ANode head;
    char Data;
}AdjList[100];

//Graph Vertex define
typedef struct GNode{
    int Nv;
    int Ne;
    AdjList G;
}*LGraph;

//Create a Graph
LGraph CreateGraph(int n){
    LGraph Graph=new GNode;
    Graph->Nv=n;
    Graph->Ne=0;
    for(int i=0;i<n;i++){
        Graph->G[i].head=NULL;
    }
    
    return Graph;
}
//Insert an Edge(connect E->V1,E->V2)
void InsertEdge(LGraph Graph,Edge E){
    ANode t=new AdjVNode,p=Graph->G[E->V1].head;
    printf("head = %x\n",Graph->G[E->V1].head);
    t->V=E->V2;
    t->Weight=E->Weight;
    
    t->Next=p->Next;
    p->Next=t;
}

//Build a Graph(apply InsertEdge)
LGraph BuildGraph(){
    LGraph Graph=new GNode;
    
    int Nv;
    
    cin>>Nv;
    CreateGraph(Nv);
    cin>>Graph->Ne;
    if(Graph->Ne){
        for(int i=0;i<Graph->Ne;i++){
            Edge E=new ENode;
            cin>>E->V1>>E->V2>>E->Weight;
            InsertEdge(Graph, E);
        }
    }
    
    for(int i=0;i<Graph->Nv;i++){
        cin>>Graph->G[i].Data;
    }
    
    return Graph;
}

//DFS
void visit(int V){
    cout<<"Is visiting Vertex "<<V<<endl;
}

void DFS(LGraph Graph,int V){
    ANode t=Graph->G[V].head;
    visit(V);
    Visited[V]=true;
    cout<<Visited[V]<<endl;
    while(t){
        if(!Visited[V]){
            DFS(Graph, V);
        }
        
        t=t->Next;
    }
}

int main(){
    LGraph Graph=BuildGraph();
    DFS(Graph, 0);
}

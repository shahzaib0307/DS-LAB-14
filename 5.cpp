#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector<vector<int>> adj(6);
vector<int> visited(6);

void bfs(int start){
    queue<int> q;
    visited.assign(6,0);
    q.push(start);
    visited[start]=1;
    while(!q.empty()){
        int u=q.front(); q.pop();
        cout<<u<<" ";
        for(int v:adj[u])
            if(!visited[v]){
                visited[v]=1;
                q.push(v);
            }
    }
}

void dfsUtil(int u){
    visited[u]=1;
    cout<<u<<" ";
    for(int v:adj[u])
        if(!visited[v]) dfsUtil(v);
}

void dfs(int start){
    visited.assign(6,0);
    dfsUtil(start);
}

int main(){
    adj[1]={2,4};
    adj[2]={1,4,5,3};
    adj[3]={2,5};
    adj[4]={1,2,5};
    adj[5]={2,3,4};

    cout<<"BFS: ";
    bfs(1);
    cout<<"\nDFS: ";
    dfs(1);
}

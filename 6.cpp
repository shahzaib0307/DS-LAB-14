#include <iostream>
#include <vector>
#include <queue>
#include <limits>
using namespace std;

int main() {
    vector<vector<pair<int,int>>> adj(6);
    
    adj[1].push_back({2,4});
    adj[2].push_back({1,4});

    adj[1].push_back({3,9});
    adj[3].push_back({1,9});

    adj[2].push_back({4,8});
    adj[4].push_back({2,8});

    adj[3].push_back({4,6});
    adj[4].push_back({3,6});

    adj[4].push_back({5,4});
    adj[5].push_back({4,4});

    adj[3].push_back({5,14});
    adj[5].push_back({3,14});

    adj[5].push_back({4,3});
    adj[4].push_back({5,3});

    vector<int> dist(6, INT_MAX), parent(6, -1);
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;

    int start = 1;
    dist[start] = 0;
    pq.push({0,start});

    while(!pq.empty()) {
        int u = pq.top().second;
        pq.pop();

        for(auto e : adj[u]) {
            int v = e.first;
            int w = e.second;
            if(dist[u] + w < dist[v]) {
                dist[v] = dist[u] + w;
                parent[v] = u;
                pq.push({dist[v], v});
            }
        }
    }

    int target = 5;
    vector<int> path;
    for(int v = target; v != -1; v = parent[v]) path.push_back(v);

    for(int i = path.size() - 1; i >= 0; i--) cout << path[i] << " ";
    cout << "\nDistance: " << dist[target];
}

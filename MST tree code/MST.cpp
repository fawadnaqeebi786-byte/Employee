#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Edge {
    int u, v, weight;
    bool operator<(const Edge& other) const {
        return weight < other.weight;
    }
};

class DSU {
private:
    vector<int> parent, rankk;
public:
    DSU(int n) {
        parent.resize(n);
        rankk.resize(n, 0);
        for(int i = 0; i < n; i++) {
            parent[i] = i;
        }
    }
    
    int find(int x) {
        if(parent[x] != x) {
            parent[x] = find(parent[x]);
        }
        return parent[x];
    }
    
    bool unionSets(int x, int y) {
        int px = find(x);
        int py = find(y);
        
        if(px == py) return false;
        
        if(rankk[px] < rankk[py]) {
            parent[px] = py;
        } else if(rankk[px] > rankk[py]) {
            parent[py] = px;
        } else {
            parent[py] = px;
            rankk[px]++;
        }
        return true;
    }
};

int main() {
    int V, E;
    cout << "Enter number of vertices and edges: ";
    cin >> V >> E;
    
    vector<Edge> edges;
    cout << "Enter edges (u v weight):" << endl;
    
    for(int i = 0; i < E; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        edges.push_back({u, v, w});
    }
    
    // Kruskal's Algorithm
    sort(edges.begin(), edges.end());
    
    DSU dsu(V);
    vector<Edge> mst;
    int totalWeight = 0;
    
    for(Edge& e : edges) {
        if(dsu.unionSets(e.u, e.v)) {
            mst.push_back(e);
            totalWeight += e.weight;
            if((int)mst.size() == V - 1) break;
        }
    }
    
    cout << "\nMinimum Spanning Tree edges:\n";
    for(Edge& e : mst) {
        cout << e.u << " - " << e.v << " : " << e.weight << endl;
    }
    cout << "Total MST weight: " << totalWeight << endl;
    
    return 0;
}
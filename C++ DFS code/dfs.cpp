#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <queue>
using namespace std;

void dfs(const unordered_map<char, vector<char>>& graph, char node, 
         unordered_set<char>& visited, vector<char>& traversal) {
    visited.insert(node);
    traversal.push_back(node);
    
    for (char neighbor : graph.at(node)) {
        if (visited.find(neighbor) == visited.end()) {
            dfs(graph, neighbor, visited, traversal);
        }
    }
}

int main() {
    unordered_map<char, vector<char>> graph = {
        {'A', {'B', 'C'}},
        {'B', {'A', 'D', 'E'}},
        {'C', {'A', 'F'}},
        {'D', {'B'}},
        {'E', {'B', 'F'}},
        {'F', {'C', 'E'}}
    };
    
    unordered_set<char> visited;
    vector<char> traversal;
    
    dfs(graph, 'A', visited, traversal);
    
    cout << "DFS Traversal: ";
    for (char c : traversal) cout << c << " ";
    cout << endl;
    
    return 0;
}
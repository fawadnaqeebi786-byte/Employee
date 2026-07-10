#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <queue>
using namespace std;

vector<char> dls(const unordered_map<char, vector<char>>& graph, char node, 
                 char goal, int depth, unordered_set<char>& visited) {
    if (depth == 0) {
        if (node == goal) return {node};
        return {};
    }
    
    visited.insert(node);
    if (node == goal) return {node};
    
    for (char neighbor : graph.at(node)) {
        if (visited.find(neighbor) == visited.end()) {
            auto result = dls(graph, neighbor, goal, depth - 1, visited);
            if (!result.empty()) {
                result.insert(result.begin(), node);
                return result;
            }
        }
    }
    return {};
}

vector<char> ids(const unordered_map<char, vector<char>>& graph, char start, char goal) {
    int depth = 0;
    while (true) {
        unordered_set<char> visited;
        auto result = dls(graph, start, goal, depth, visited);
        if (!result.empty()) {
            return result;
        }
        depth++;
        if (depth > 20) break; // safety
    }
    return {};
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
    
    auto path = ids(graph, 'A', 'F');
    cout << "IDS Path from A to F: ";
    for (char c : path) cout << c << " ";
    cout << endl;
    
    return 0;
}
#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <queue>

using namespace std;

vector<char> bfs(const unordered_map<char, vector<char>> &graph, char start)
{
    unordered_set<char> visited;
    queue<char> q;
    vector<char> traversal;

    q.push(start);
    visited.insert(start);

    while (!q.empty())
    {
        char node = q.front();
        q.pop();
        traversal.push_back(node);

        for (char neighbor : graph.at(node))
        {
            if (visited.find(neighbor) == visited.end())
            {
                visited.insert(neighbor);
                q.push(neighbor);
            }
        }
    }
    return traversal;
}

int main()
{
    unordered_map<char, vector<char>> graph = {
        {'A', {'B', 'C'}},
        {'B', {'A', 'D', 'E'}},
        {'C', {'A', 'F'}},
        {'D', {'B'}},
        {'E', {'B', 'F'}},
        {'F', {'C', 'E'}}};

    vector<char> result = bfs(graph, 'A');
    cout << "BFS Traversal: ";
    for (char c : result)
        cout << c << " ";
    cout << endl;

    return 0;
}
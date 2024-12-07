#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <unordered_set>

using namespace std;

class UndirectedGraph {
private:
    vector<vector<int>> adjList; // Adjacency list
    int numVertices;

    void dfsHelper(int node, vector<bool>& visited) {
        cout << node << " "; // Process the current node
        visited[node] = true;

        for (int neighbor : adjList[node]) {
            if (!visited[neighbor]) {
                dfsHelper(neighbor, visited);
            }
        }
    }

public:
    UndirectedGraph(int vertices) : numVertices(vertices), adjList(vertices) {}

    void addEdge(int u, int v) {
        adjList[u].push_back(v); // Add edge from u to v
        adjList[v].push_back(u); // Add edge from v to u (undirected graph)
    }

    void bfs(int start) {
        vector<bool> visited(numVertices, false);
        queue<int> q;

        q.push(start);
        visited[start] = true;

        while (!q.empty()) {
            int node = q.front();
            q.pop();
            cout << node << " "; // Process the current node

            for (int neighbor : adjList[node]) {
                if (!visited[neighbor]) {
                    q.push(neighbor);
                    visited[neighbor] = true;
                }
            }
        }

        cout << endl;
    }

    void dfsRecursive(int start) {
        vector<bool> visited(numVertices, false);
        dfsHelper(start, visited);
        cout << endl;
    }

    void dfsIterative(int start) {
        vector<bool> visited(numVertices, false);
        stack<int> s;

        s.push(start);

        while (!s.empty()) {
            int node = s.top();
            s.pop();

            if (!visited[node]) {
                cout << node << " "; // Process the current node
                visited[node] = true;
            }

            for (auto it = adjList[node].rbegin(); it != adjList[node].rend(); ++it) {
                if (!visited[*it]) {
                    s.push(*it);
                }
            }
        }

        cout << endl;
    }
};

int main() {
    UndirectedGraph g(6); // Create a graph with 6 vertices (0 to 5)

    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 3);
    g.addEdge(1, 4);
    g.addEdge(2, 5);

    cout << "BFS (starting from 0): ";
    g.bfs(0);

    cout << "DFS Recursive (starting from 0): ";
    g.dfsRecursive(0);

    cout << "DFS Iterative (starting from 0): ";
    g.dfsIterative(0);

    return 0;
}


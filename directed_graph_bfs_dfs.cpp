#include <iostream>
#include <vector>
#include <queue>
#include <stack>

using namespace std;

class DirectedGraph {
private:
    vector<vector<int>> adjList;      // Adjacency list representation
    vector<vector<int>> adjMatrix;    // Adjacency matrix representation
    int numVertices;

    void dfsHelper(int node, vector<bool>& visited) {
        cout << node << " ";
        visited[node] = true;

        for (int neighbor : adjList[node]) {
            if (!visited[neighbor]) {
                dfsHelper(neighbor, visited);
            }
        }
    }

public:
    DirectedGraph(int vertices) 
        : numVertices(vertices), 
          adjList(vertices), 
          adjMatrix(vertices, vector<int>(vertices, 0)) {}

    // Add edge to both adjList and adjMatrix
    void addEdge(int u, int v) {
        // Update adjacency list
        adjList[u].push_back(v);

        // Update adjacency matrix
        adjMatrix[u][v] = 1;
    }

    // BFS traversal
    void bfs(int start) {
        vector<bool> visited(numVertices, false);
        queue<int> q;

        q.push(start);
        visited[start] = true;

        while (!q.empty()) {
            int node = q.front();
            q.pop();
            cout << node << " ";

            for (int neighbor : adjList[node]) {
                if (!visited[neighbor]) {
                    q.push(neighbor);
                    visited[neighbor] = true;
                }
            }
        }

        cout << endl;
    }

    // Recursive DFS traversal
    void dfsRecursive(int start) {
        vector<bool> visited(numVertices, false);
        dfsHelper(start, visited);
        cout << endl;
    }

    // Iterative DFS traversal
    void dfsIterative(int start) {
        vector<bool> visited(numVertices, false);
        stack<int> s;

        s.push(start);

        while (!s.empty()) {
            int node = s.top();
            s.pop();

            if (!visited[node]) {
                cout << node << " ";
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

    // Visualize adjacency list
    void visualizeGraph() {
        cout << "Adjacency List Representation:" << endl;
        for (int u = 0; u < numVertices; ++u) {
            cout << u << " -> ";
            for (int v : adjList[u]) {
                cout << v << " ";
            }
            cout << endl;
        }

        cout << endl;

        cout << "Adjacency Matrix Representation:" << endl;
        for (int u = 0; u < numVertices; ++u) {
            for (int v = 0; v < numVertices; ++v) {
                cout << adjMatrix[u][v] << " ";
            }
            cout << endl;
        }
    }
};

int main() {
    DirectedGraph g(7);

    // Add edges to the graph
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(0, 3);
    g.addEdge(2, 4);
    g.addEdge(2, 5);
    g.addEdge(5, 6);

    cout << "BFS (starting from 0): ";
    g.bfs(0);

    cout << "DFS Recursive (starting from 0): ";
    g.dfsRecursive(0);

    cout << "DFS Iterative (starting from 0): ";
    g.dfsIterative(0);

    cout << endl;

    g.visualizeGraph();

    return 0;
}

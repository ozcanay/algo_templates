// https://stackoverflow.com/questions/14315621/are-trees-directed-or-undirected-graphs:
// The Wikipedia page describes trees in the context of graph theory, where a tree is indeed an special case of an undirected graph. In the context of programming however, what we call trees are most of the time rooted trees with an implied direction from root to leaves. Many algorithms don't need the reverse direction from the leaves to the root, so storing the lighter directed rooted tree is often sufficient.
// Unless qualified otherwise, trees in Mathematics or Graph Theory are usually assumed to be undirected, but in Computer Science or Programming or Data Structure, trees are usually assumed to be directed and rooted.


// Implementing DFS & BFS for trees instead of graphs, what changes do we have to do?

// If the given implementation is for a tree instead of a graph, several simplifications and assumptions can be made because trees have unique structural properties that make them simpler to handle compared to general graphs.

/*

Key Properties of a Tree
    Acyclic: Trees do not have cycles, so there's no need to handle visited nodes for cycle prevention. -> this is a very important simplification.
    Connected: Every node in the tree is connected by exactly one path.
    Rooted Structure: Trees typically have a designated root node from which traversal starts.
    Edges: A tree with NN nodes always has N−1N−1 edges.

*/

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class Tree {
private:
    vector<vector<int>> adjList; // Adjacency list
    int numNodes;

    void dfsPreorderHelper(int node) {
        cout << node << " "; // Process the node (preorder)
        for (int child : adjList[node]) {
            dfsPreorderHelper(child); // Visit children
        }
    }

public:
    Tree(int nodes) : numNodes(nodes), adjList(nodes) {}

    void addEdge(int parent, int child) {
        adjList[parent].push_back(child); // Add child to parent
    }

    void bfs(int start) {
        queue<int> q;
        q.push(start);

        while (!q.empty()) {
            int node = q.front();
            q.pop();
            cout << node << " "; // Process the node

            for (int child : adjList[node]) {
                q.push(child);
            }
        }

        cout << endl;
    }

    void dfsPreorder(int start) {
        dfsPreorderHelper(start);
        cout << endl;
    }
};

int main() {
    Tree t(7); // A tree with 7 nodes (0 to 6)

    t.addEdge(0, 1);
    t.addEdge(0, 2);
    t.addEdge(1, 3);
    t.addEdge(1, 4);
    t.addEdge(2, 5);
    t.addEdge(2, 6);

    cout << "BFS (starting from root 0): ";
    t.bfs(0);

    cout << "DFS Preorder (starting from root 0): ";
    t.dfsPreorder(0);

    return 0;
}

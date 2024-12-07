#include <iostream>
#include <queue>
#include <stack>
using namespace std;

// Definition for a binary tree node
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
};

class BinaryTree {
public:
    void visualizeTree(TreeNode* root, int depth = 0, string prefix = "") {
        if (root == nullptr) {
            cout << prefix << "    " << "nullptr" << endl;
            return;
        }

        // Display current node
        cout << prefix;
        if (depth > 0) {
            cout << "|-- ";
        }
        cout << root->val << endl;

        // Traverse left and right children
        visualizeTree(root->left, depth + 1, prefix + (depth > 0 ? "|   " : "    "));
        visualizeTree(root->right, depth + 1, prefix + (depth > 0 ? "|   " : "    "));
    }

    // Preorder Traversal (DFS - Root, Left, Right)
    void dfsPreorder(TreeNode* root) {
        if (root == nullptr) return;
        cout << root->val << " ";     // Process root
        dfsPreorder(root->left);      // Traverse left subtree
        dfsPreorder(root->right);     // Traverse right subtree
    }

    // Inorder Traversal (DFS - Left, Root, Right)
    void dfsInorder(TreeNode* root) {
        if (root == nullptr) return;
        dfsInorder(root->left);       // Traverse left subtree
        cout << root->val << " ";     // Process root
        dfsInorder(root->right);      // Traverse right subtree
    }

    // Postorder Traversal (DFS - Left, Right, Root)
    void dfsPostorder(TreeNode* root) {
        if (root == nullptr) return;
        dfsPostorder(root->left);     // Traverse left subtree
        dfsPostorder(root->right);    // Traverse right subtree
        cout << root->val << " ";     // Process root
    }

    // BFS (Level-Order Traversal)
    void bfs(TreeNode* root) {
        if (root == nullptr) return;

        queue<TreeNode*> q;
        q.push(root);

        while (!q.empty()) {
            TreeNode* node = q.front();
            q.pop();
            cout << node->val << " "; // Process node

            if (node->left) q.push(node->left);  // Add left child
            if (node->right) q.push(node->right); // Add right child
        }
        cout << endl;
    }
};


int main() {
    // Create a binary tree
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->right->left = new TreeNode(6);
    root->right->right = new TreeNode(7);

    BinaryTree tree;

    cout << "Preorder (DFS): ";
    tree.dfsPreorder(root);
    cout << endl;

    cout << "Inorder (DFS): ";
    tree.dfsInorder(root);
    cout << endl;

    cout << "Postorder (DFS): ";
    tree.dfsPostorder(root);
    cout << endl;

    cout << "BFS (Level Order): ";
    tree.bfs(root);

    cout << "Tree Visualization:" << endl;
    tree.visualizeTree(root);

    return 0;
}


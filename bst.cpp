#include <iostream>
#include <vector>
#include <stack>
#include <string>
using namespace std;

// Node definition for BST
struct BSTNode {
    int data;
    BSTNode* left;
    BSTNode* right;
    BSTNode(int val) : data(val), left(nullptr), right(nullptr) {}
};

// BST class
class BST {
public:
    BSTNode* root;

    BST() : root(nullptr) {}

    void insert(int key) {
        root = INSERT(root, key);
    }

    BSTNode* INSERT(BSTNode* node, int key) {
        if (node == nullptr) {
            return new BSTNode(key);
        }
        if (key < node->data) {
            node->left = INSERT(node->left, key);
        } else {
            node->right = INSERT(node->right, key);
        }
        return node;
    }

    BSTNode* constructBSTFromPreorder(vector<int>& preorder){
        if (preorder.empty()){ return nullptr;}

        BSTNode* root = new BSTNode(preorder[0]);
        // Keep of ancestors of the current node
        stack<BSTNode*> nodeStack;
        nodeStack.push(root);

        for (int i = 1; i < preorder.size(); ++i) {
           BSTNode* newNode = new BSTNode(preorder[i]);
           BSTNode* temp = nullptr;

        // Find the correct parent of new node
           while (!nodeStack.empty() && preorder[i] > nodeStack.top()->data) {
                temp = nodeStack.top();
                nodeStack.pop();
            }

        // Attach the new node to its parent
            if (temp) {
                temp->right = newNode; // If the new node is greater, it's the right child
            } else {
                nodeStack.top()->left = newNode; // Otherwise, it's the left child
            }

        // Push the new node onto the stack
            nodeStack.push(newNode);
        }

        return root;
    }

     BSTNode* findLCA(BSTNode* node, int n1, int n2) {
        if (node == nullptr) {
            return nullptr;
        }
        if (node->data > n1 && node->data > n2) {
            return findLCA(node->left, n1, n2);
        }
        if (node->data < n1 && node->data < n2) {
            return findLCA(node->right, n1, n2);
        }
        return node;
    }

    BSTNode* SEARCH(BSTNode* root,int k){
        if(root == nullptr){
            return nullptr;
        }
        if (k == root->data){
            return root;
        }
        else if(k < root->data){
            return SEARCH(root->left,k);
        }
        else{
            return SEARCH(root->right,k);
        }
    }

    BSTNode* search(int key) {
        return SEARCH(root, key);
    }

     BSTNode* MINIMUM(BSTNode* x){
        while (x->left != NULL){
            x=x->left;
        }
        return x;
    }

    void deleteNode(int key) {
            DELETION(root, key);
    }

    BSTNode* DELETION(BSTNode* node, int key) {
        if (node == nullptr) {
            return node;
        }
        if (key < node->data) {
            node->left = DELETION(node->left, key);
        } else if (key > node->data) {
            node->right = DELETION(node->right, key);
        } else {
            if (node->left == nullptr) {
                BSTNode* temp = node->right;
                delete node;
                return temp;
            } else if (node->right == nullptr) {
                BSTNode* temp = node->left;
                delete node;
                return temp;
            }

            BSTNode* temp = MINIMUM(node->right);
            node->data = temp->data;
            node->right = DELETION(node->right, temp->data);
        }
        return node;
    }

    // Print tree in a tree structure
    void printTree(BSTNode* root, string indent, bool last) {
        if (root) {
            cout << indent;
            if (last) {
                cout << "R----";
                indent += "     ";
            } else {
                cout << "L----";
                indent += "|    ";
            }
            cout << root->data << endl;
            printTree(root->left, indent, false);
            printTree(root->right, indent, true);
        }
    }
};
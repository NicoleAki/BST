#include <iostream>
#include "bst.cpp"

int main() {
    // Testing BST functions
    BST bst;
    vector<int> preorder = {8, 5, 1, 7, 10, 12};
    bst.root = bst.constructBSTFromPreorder(preorder);
    bst.printTree(bst.root, "", true);

    cout << "Searching 7: " << (bst.search(7) ? "Found" : "Not Found") << endl;

    BSTNode* lca = bst.findLCA(bst.root, 1, 7);
    cout << "LCA of 1 and 7: " << (lca ? lca->data : -1) << endl;

    return 0;
}
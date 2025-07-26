/* 
*************************
Id : 22011471
Name : Muhamad Aniq Bin Mohd Zulastri
Lab : 8
*************************
*/





#include <iostream>
using namespace std;

class Node;

void preorder(Node* node);
void inorder(Node* node);
void postorder(Node* node);

class Node {
public:
    string name;
    Node* left;
    Node* right;

    Node(string n) {
        name = n;
        left = nullptr;
        right = nullptr;
    }
};

class Tree {
public:
    Node* root;

    Tree() {
        root = nullptr;
    }

    void insert(string name) {
        root = insert_recursive(root, name);
    }

    bool search(string name) {
        return search_recursive(root, name);
    }

private:
    Node* insert_recursive(Node* node, string name) {
        if (node == nullptr) {
            return new Node(name);
        }

        if (name < node->name) {
            node->left = insert_recursive(node->left, name);
        } else {
            node->right = insert_recursive(node->right, name);
        }
        return node;
    }

    bool search_recursive(Node* node, string name) {
        if (node == nullptr) return false;
        if (node->name == name) return true;
        if (name < node->name) return search_recursive(node->left, name);
        return search_recursive(node->right, name);
    }
};

void preorder(Node* node) {
    if (node != nullptr) {
        cout << node->name << " ";
        preorder(node->left);
        preorder(node->right);
    }
}

void inorder(Node* node) {
    if (node != nullptr) {
        inorder(node->left);
        cout << node->name << " ";
        inorder(node->right);
    }
}

void postorder(Node* node) {
    if (node != nullptr) {
        postorder(node->left);
        postorder(node->right);
        cout << node->name << " ";
    }
}

int main() {
    Tree tree;

    tree.insert("D");
    tree.insert("B");
    tree.insert("A");
    tree.insert("C");
    tree.insert("F");
    tree.insert("E");
    tree.insert("G");

    cout << "Root: " << tree.root->name << endl;

    if (tree.root->left)
        cout << "Left child of root: " << tree.root->left->name << endl;
    if (tree.root->right)
        cout << "Right child of root: " << tree.root->right->name << endl;

    if (tree.root->left && tree.root->left->left)
        cout << "Left child of B: " << tree.root->left->left->name << endl;
    if (tree.root->left && tree.root->left->right)
        cout << "Right child of B: " << tree.root->left->right->name << endl;

    if (tree.root->right && tree.root->right->left)
        cout << "Left child of F: " << tree.root->right->left->name << endl;
    if (tree.root->right && tree.root->right->right)
        cout << "Right child of F: " << tree.root->right->right->name << endl;

    cout << endl << "Preorder Traversal: ";
    preorder(tree.root);
    cout << endl << "Inorder Traversal: ";
    inorder(tree.root);
    cout << endl << "Postorder Traversal: ";
    postorder(tree.root);
    cout << endl;

    string key;
    cout << endl << "Enter name to search: ";
    cin >> key;

    if (tree.search(key)) {
        cout << key << " found in the tree." << endl;
    } else {
        cout << key << " not found in the tree." << endl;
    }

    return 0;
}
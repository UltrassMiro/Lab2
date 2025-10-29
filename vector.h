#pragma once
#include <iostream>
#include <vector>
#include <list>
#include <cmath>
#include <algorithm>
#include <stack>
using namespace std;

class Vector {
private:
    double x, y, z;
public:
    Vector(double x=0, double y=0, double z=0) : x(x), y(y), z(z) {}

    double length() const { return sqrt(x*x + y*y + z*z); }

    void print() const {
        cout << "(" << x << ", " << y << ", " << z << ")";
    }

    bool operator==(const Vector& other) const {
        return x == other.x && y == other.y && z == other.z;
    }

    bool operator<(const Vector& other) const {
        return length() < other.length();
    }

    void update(double nx, double ny, double nz) {
        x = nx; y = ny; z = nz;
    }
};

void print_all(const vector<Vector>& vec) {
    if (vec.empty()) {
        cout << "List is empty.\n";
        return;
    }
    cout << "Current vectors:\n";
    for (size_t i = 0; i < vec.size(); ++i) {
        cout << i+1 << ": "; vec[i].print();
        cout << " | length = " << vec[i].length() << endl;
    }
}

template <typename T>
class BinaryTree {
private:
    struct Node {
        T data;
        Node* left;
        Node* right;
        Node(const T& val) : data(val), left(nullptr), right(nullptr) {}
    };
    Node* root;

    void insert(Node*& node, const T& val) {
        if (!node) node = new Node(val);
        else if (val < node->data) insert(node->left, val);
        else insert(node->right, val);
    }

    void preorder(Node* node, int depth) const {
        if (!node) return;
        cout << string(depth * 4, ' ');
        node->data.print();
        cout << " | length = " << node->data.length() << endl;
        preorder(node->left, depth + 1);
        preorder(node->right, depth + 1);
    }

public:
    BinaryTree() : root(nullptr) {}

    void insert(const T& val) { insert(root, val); }

    void preorder() const { preorder(root, 0); }

    class Iterator {
    private:
        stack<Node*> nodes;
    public:
        Iterator(Node* root) { if (root) nodes.push(root); }
        bool operator!=(const Iterator& other) const { return nodes != other.nodes; }
        T& operator*() { return nodes.top()->data; }
        Iterator& operator++() {
            Node* curr = nodes.top();
            nodes.pop();
            if (curr->right) nodes.push(curr->right);
            if (curr->left) nodes.push(curr->left);
            return *this;
        }
    };

    Iterator begin() const { return Iterator(root); }
    Iterator end() const { return Iterator(nullptr); }
};

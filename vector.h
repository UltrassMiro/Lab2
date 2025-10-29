#pragma once
#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
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
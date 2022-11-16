#include <bits/stdc++.h>
#include "Matrix.hpp"
#include "Functions.hpp"
using namespace std;

template<typename T>
ostream& operator<<(ostream &o, const vector<T>& vec) {
    o << "["; for(auto &x : vec) o << x << " "; return o << "]";
}

ostream& operator<<(ostream &o, const Matrix& mat) {
    return o << mat.mat;
}

int main() {
    Matrix a(2, 2), b(2, 2);
    a.mat[0] = {3, 4};
    a.mat[1] = {1, 2};

    b.mat[0] = {5, 10};
    b.mat[1] = {10, 20};

    cout << a << " " << b << endl;
    cout << (a+b) << " " << (a-b) << " " << (b+a) << " " << (b-a) << endl;
    cout << (a*b) << " " << (a^b) << " " << (b*a) << " " << (b^a) << endl;
    a += b;
    cout << a << endl;

    vector<vector<double>> vec = {{1},{2},{1}};
    // vector<vector<double>> vec = {{3},{4},{1}};
    // vector<vector<double>> vec = {{ 1. , 4.2 , 0.6 , 1.23 , 4.3 , 1.2, 2.5 }};
    Matrix mvec(vec);
    cout << functions::softmax.first(mvec) << endl;
    cout << functions::softmax.second(mvec) << endl;

    return 0;
}
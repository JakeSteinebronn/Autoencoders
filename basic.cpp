#include <bits/stdc++.h>
#include "Matrix.hpp"
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

    return 0;
}
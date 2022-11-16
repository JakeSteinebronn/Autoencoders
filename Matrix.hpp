#ifndef MATRIX_H_
#define MATRIX_H_

#include <vector>
using namespace std;

struct Matrix {
    int n, m;
    vector<vector<double>> mat;
    Matrix(int n, int m): n(n), m(m), mat(n, vector<double>(m)) {}
    Matrix(const Matrix &o): n(o.n), m(o.m), mat(o.mat) {}
    Matrix(const Matrix *o): n(o->n), m(o->m), mat(o->mat) {}
    Matrix(const vector<vector<double>>& mat): n(mat.size()), m(mat[0].size()), mat(mat) {}

    double sum() const {
        double res = 0;
        for(auto &row : mat) for(auto x : row) res += x;
        return res;
    }

    double size() const { return n * m; }


    vector<double>& operator[](int r) { return mat[r]; }
    bool operator==(const Matrix& o) const { return n == o.n && m == o.m && mat == o.mat; }
    bool operator!=(const Matrix& o) const { return n != o.n || m != o.m || mat != o.mat; }

    Matrix operator+(const Matrix& o) const {
        assert(n == o.n && m == o.m);
        Matrix res = *this;
        for(int i = 0; i < n; i++)
            for(int j = 0; j < m; j++)
                res.mat[i][j] += o.mat[i][j];
        return res;
    }
    Matrix& operator+=(const Matrix& o) { return *this = *this + o; }

    Matrix operator-(const Matrix& o) const {
        assert(n == o.n && m == o.m);
        Matrix res = *this;
        for(int i = 0; i < n; i++)
            for(int j = 0; j < m; j++)
                res.mat[i][j] -= o.mat[i][j];
        return res;
    }
    Matrix& operator-=(const Matrix& o) { return *this = *this - o; }

    Matrix operator*(double d) const {
        Matrix res(this);
        for(int i = 0; i < n; i++)
            for(int j = 0; j < m; j++)
                res.mat[i][j] *= d;
        return res;
    }
    Matrix& operator*=(double d) { return *this = *this * d; }

    Matrix operator^(const Matrix& o) const {
        assert(n == o.n && m == o.m);
        Matrix res(this);
        for(int i = 0; i < n; i++)
            for(int j = 0; j < m; j++)
                res.mat[i][j] *= o.mat[i][j];
        return res;
    }
    Matrix& operator^=(const Matrix& o) { return *this = *this ^ o; }

    Matrix operator*(const Matrix& o) const {
        assert(m == o.n);
        Matrix res(n, o.m);
        for(int i = 0; i < n; i++) 
            for(int j = 0; j < o.m; j++)
                for(int k = 0; k < m; k++)
                    res.mat[i][j] += mat[i][k] * o.mat[k][j];
        return res;
    }   
    Matrix& operator*=(const Matrix& o) { return *this = *this * o; }

    Matrix T() const {
        Matrix res(m, n);
        for(int i = 0; i < n; i++)
            for(int j = 0; j < m; j++)
                res.mat[j][i] = mat[i][j];
        return res;
    }
};

#endif // MATRIX_H_
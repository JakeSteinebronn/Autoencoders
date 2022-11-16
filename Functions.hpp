#ifndef FUNCTIONS_H_
#define FUNCTIONS_H_

#include "Matrix.hpp"

const double K_LRELU = 0.10;
typedef pair<function<Matrix(const Matrix&)>, function<Matrix(const Matrix&)>> act_fun;

namespace functions {
    Matrix _l_relu(const Matrix &mat) {
        auto res(mat);
        for(auto &row : res.mat)
            for(auto &x : row) if(x < 0) x *= K_LRELU;
        return res;
    }

    Matrix _d_l_relu(const Matrix &mat) {
        auto res(mat);
        for(auto &row : res.mat)
            for(auto &x : row) 
                if(x < 0) x = K_LRELU;
                else x = 1.0;
        return res;
    }

    Matrix _softmax(const Matrix &mat) {
        auto res(mat);
        double sum = 0;
        for(auto &row : res.mat) for(auto &x : row) sum += exp(x);
        for(auto &row : res.mat) for(auto &x : row) x = exp(x) / sum;
        return res;
    }

    Matrix _d_softmax(const Matrix &mat) {
        auto res(mat);
        double sum = 0;
        for(auto &row : res.mat) for(auto &x : row) sum += exp(x);
        for(auto &row : res.mat) for(auto &x : row) x = (exp(x) * (sum - exp(x))) / (sum*sum);
        return res;
    }

    Matrix _d_softmax2(const Matrix &mat) { 
        auto res = _softmax(mat);
        for(auto &row : res.mat) for(auto &x : row) x = x * (1.0 - x);
        return res;
    }

    double MSE(const Matrix &y, const Matrix &yhat) {
        auto dif = (y - yhat).sum();
        return dif*dif / (y.size() * 2); 
    }

    act_fun l_relu = make_pair(&_l_relu, _d_l_relu);
    act_fun softmax = make_pair(&_softmax, _d_softmax2);

};

#endif // FUNCTIONS_H_
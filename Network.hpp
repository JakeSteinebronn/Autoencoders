#ifndef NETWORK_H_
#define NETWORK_H_

#include "Matrix.hpp"
#include "Functions.hpp"
#include <vector>
using namespace std;

struct Network {
    int layers;
    vector<int> sizes;

    vector<Matrix> weights;
    vector<Matrix> biases;
    vector<act_fun> act_funs;

    Network(const vector<int> &sizes, const vector<act_fun> &act_funs): sizes(sizes), layers(sizes.size()), act_funs(act_funs) {
        for(int i = 1; i < layers; i++) weights.emplace_back(sizes[i-1], sizes[i]);
        for(int i = 0; i < layers; i++) biases.emplace_back(1, sizes[i]);
    }

    
};

#endif
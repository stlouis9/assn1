//
// Created by stlou on 03-Oct-19.
//

#include "matrix.hpp"

matrix::matrix() {
    vect[0].push_back(0.0);
}

matrix::matrix(int n) {
    vect.resize(n);
    for(int i = 0; i<n; i++){
        vect[i].resize(n);
        for(int j = 0; j<n; j++){
            vect[i][j] = 0.0;
        }
    }
}

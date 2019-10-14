//
// Created by stlou on 03-Oct-19.
//

#include <cmath>
#include "matrix.hpp"
using namespace std;
matrix::matrix() {
    vect[0].push_back(0.0);
}

matrix::matrix(int n) {
    if(n <= 0)
        throw "n cannot be below 0!";
    vect.resize(n);
    for(int i = 0; i<n; i++){
        vect[i].resize(n);
        for(int j = 0; j<n; j++){
            vect[i][j] = 0.0;
        }
    }
}

matrix::matrix(int r, int c) {
    if(r <= 0 || c <=0)
        throw "r or c cannot be below 0!";
    vect.resize(r);
    for(int i = 0; i<r; i++){
        vect[i].resize(c);
        for(int j = 0; j<c; j++){
            vect[i][j] = 0.0;
        }
    }

}

matrix::matrix(vector<double> initVect) {
    long double sr = sqrt(initVect.size());
    if((sr - floor(sr)) != 0)
        throw "Size of array must be a perfect square!";

    vect.resize(sr);
    int index = 0;
    for(int i = 0; i<sr; i++){
        vect[i].resize(sr);
        for(int j = 0; j<sr; j++){
            vect[i][j] = initVect[index];
            index++;
        }
    }

}

matrix &matrix::operator++() {
    for (auto & i : vect) {
        for (double &j : i) {
            j++;
        }
    }
    return *this;
}

matrix matrix::operator++(int) {
    matrix temp = *this;
    for (auto & i : vect) {
        for (double &j : i) {
            ++j;
        }
    }
    return temp;
}

matrix &matrix::operator--() {
    for (auto & i : vect) {
        for (double &j : i) {
            j--;
        }
    }
    return *this;
}

matrix matrix::operator--(int) {
    matrix temp = *this;
    for (auto & i : vect) {
        for (double &j : i) {
            --j;
        }
    }
    return temp;
}

matrix::~matrix() {
    std::cout<<"Matrix destroyed"<<endl;
}

void matrix::operator=(__const matrix &m) {
    vect = m.vect;
}

matrix &matrix::operator+=(const matrix &rhs) {
    if((this->vect.size() == rhs.vect.size()) &&
       (this->vect[0].size() == rhs.vect[0].size())){
        for (int i = 0; i < this->vect.size(); i++){
            for(int j = 0; j < this->vect[i].size(); j++){
                this->vect[i][j] += rhs.vect[i][j];
            }
        }
        return *this;
    } else
        throw "Matrices are not the same size!";
}

matrix &matrix::operator-=(const matrix &rhs) {
    if((this->vect.size() == rhs.vect.size()) &&
       (this->vect[0].size() == rhs.vect[0].size())){
        for (int i = 0; i < this->vect.size(); i++){
            for(int j = 0; j < this->vect[i].size(); j++){
                this->vect[i][j] -= rhs.vect[i][j];
            }
        }
        return *this;
    } else
        throw "Matrices are not the same size!";
}

matrix matrix::operator+(const matrix &rhs) {

    if ((this->vect.size() == rhs.vect.size()) &&
        (this->vect[0].size() == rhs.vect[0].size())) {
        matrix m = rhs;
        for (int i = 0; i < this->vect.size(); i++) {
            for (int j = 0; j < this->vect[i].size(); j++) {
                m.vect[i][j] = this->vect[i][j] + rhs.vect[i][j];
            }
        }
        return m;
    } else
        throw "Matrices are not the same size!";
}

matrix matrix::operator-(const matrix &rhs) {
    if ((this->vect.size() == rhs.vect.size()) &&
        (this->vect[0].size() == rhs.vect[0].size())) {
        matrix m = rhs;
        for (int i = 0; i < this->vect.size(); i++) {
            for (int j = 0; j < this->vect[i].size(); j++) {
                m.vect[i][j] = this->vect[i][j] - rhs.vect[i][j];
            }
        }
        return m;
    } else
        throw "Matrices are not the same size!";
}

matrix matrix::operator*(const matrix &rhs) {
    if(this->vect[0].size() == rhs.vect.size()){
        matrix m(this->vect.size(), rhs.vect[0].size());
        for(int i = 0; i < this->vect.size(); i++){
            for(int j = 0; j<rhs.vect[0].size(); j++){
                for(int k = 0; k < this->vect[0].size(); k++){
                    m.vect[i][j] += this->vect[i][k] * rhs.vect[k][j];
                }
            }
        }
        return m;
    } else
        throw "Matrix 1 column and matrix 2 rows are not the same size!";
}

matrix &matrix::operator*=(const matrix &rhs) {
    if(this->vect[0].size() == rhs.vect.size()){
        matrix m(this->vect.size(), rhs.vect[0].size());
        for(int i = 0; i < this->vect.size(); i++){
            for(int j = 0; j<rhs.vect[0].size(); j++){
                for(int k = 0; k < this->vect[0].size(); k++){
                    m.vect[i][j] += this->vect[i][k] * rhs.vect[k][j];
                }
            }
        }
        *this = m;
        return *this;
    } else
        throw "Matrix 1 column and matrix 2 rows are not the same size!";
}

std::ostream & operator << (ostream &out, const matrix &m){
    for (auto & i : m.vect) {
        for (double j : i)
            cout << j << " ";
        cout << endl;
    }
    return out;
}
bool operator ==(const matrix &lhs, const matrix &rhs){
    if((lhs.vect.size() == rhs.vect.size()) &&
       (lhs.vect[0].size() == rhs.vect[0].size())){
        for (int i = 0; i < lhs.vect.size(); i++){
            for(int j = 0; j < lhs.vect[i].size(); j++){
                //tolerance of 0.5
                if(abs(lhs.vect[i][j] - rhs.vect[i][j]) > 0.5)
                    return false;
            }
        }
        return true;
    } else
        return false;
}
bool operator !=(const matrix &lhs, const matrix &rhs){
    if((lhs.vect.size() == rhs.vect.size()) &&
       (lhs.vect[0].size() == rhs.vect[0].size())){
        for (int i = 0; i < lhs.vect.size(); i++){
            for(int j = 0; j < lhs.vect[i].size(); j++){
                if(lhs.vect[i][j] != rhs.vect[i][j])
                    return true;
            }
        }
        return false;
    } else
        return true;
}

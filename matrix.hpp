//
// Created by stlou on 03-Oct-19.
//

#ifndef ASSN1_MATRIX_HPP
#define ASSN1_MATRIX_HPP

#include <iostream>
#include <vector>

using namespace std;

class matrix {
    private:

    public:
        vector<vector<double>> vect;
        matrix();
        explicit matrix(int n);
        matrix(int r, int c);
        explicit matrix(vector<double>);
        void set_value(int row, int col, double val);
        void get_value(int row, int col);
        void clear();
        ~matrix();
        matrix& operator ++();
        matrix operator ++(int); // NOLINT(cert-dcl21-cpp)
        matrix& operator --();
        matrix operator --(int); // NOLINT(cert-dcl21-cpp)
        void operator =(const matrix& m);
        matrix& operator+=(const matrix& rhs);
        matrix& operator-=(const matrix& rhs);
        matrix operator+(const matrix& rhs);
        matrix operator-(const matrix& rhs);
        matrix operator*(const matrix& rhs);
        matrix& operator*=(const matrix& rhs);
};
    std::ostream& operator << (std::ostream &out, __const matrix &m);
    bool operator ==(const matrix &lhs, const matrix &rhs);
    bool operator !=(const matrix &lhs, const matrix &rhs);


#endif //ASSN1_MATRIX_HPP

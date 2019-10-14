#include <iostream>
#include "matrix.hpp"
#include <vector>

using namespace std;
int main() {

    try {
        matrix vectorClass(5, 7);
        //cout<<vectorClass;
    }catch (const char* msg) {
        cerr << msg << endl;
    }

    /*
     * testing perfect square constructor
     */
    try {
        vector<double> testsquare;
        testsquare.push_back(1);
        testsquare.push_back(2);
        testsquare.push_back(3);
        testsquare.push_back(4);
        matrix vectorTest(testsquare);
        matrix matrix2(testsquare);
        matrix m(testsquare);




        cout<<++vectorTest;
        cout<<matrix2;
        m = (vectorTest * vectorTest);
        vectorTest *= vectorTest;
        cout<<m;
        cout<<vectorTest;

    }
    catch (const char* msg) {
        cerr << msg << endl;
    }

    return 0;
}
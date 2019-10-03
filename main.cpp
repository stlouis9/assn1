#include <iostream>
#include "matrix.hpp"
#include <vector>

using namespace std;
int main() {
    matrix vectorClass(10);

    for (int i = 0; i < vectorClass.vect.size(); i++) {
        for (int j = 0; j < vectorClass.vect[i].size(); j++)
            cout << vectorClass.vect[i][j] << " ";
        cout << endl;
    }

    return 0;
}
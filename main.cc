#include <iostream>
#include <ProjectMatrix.h>

int main()
{
    Matrix a(2, 2);
    Matrix b(2, 2);
    a(0, 0) = 1;
    a(0, 1) = 2;
    a(1, 0) = 3;
    a(1, 1) = 4;
    b(0, 0) = 1;
    b(0, 1) = 2;
    b(1, 0) = 3;
    b(1, 1) = 4;
    a.mul_number(3);
    a.sum_matrix(b);
    a += b;
    a.Print();
}
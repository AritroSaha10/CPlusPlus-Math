/*
Copyright Aritro Saha 2020

Program Description: given a quadratic equation in form of x^2 + bx + c, factor
                        the equation into (x ± c)(x ± d)
Inputs:
    From x^2 + bx + c:
        value of b
        value of c

Output:
    (x ± c)(x ± d)
    Steps to get factored form

*/


#include <iostream>

int main() {
    long long int b = 0;
    long long int c = 0;

    std::cout << 
    "Program: Large Quadratic Polynomial Factor Machine (LQPFM)\nUsage: Factors large polynomials and includes steps\nInput:\n\tFrom x^2 + bx + c:\n\t\tb\n\t\tc\nOutput: (x +- c)(x +- d)\n\n";

    std::cout << "If in form of x^2 + bx + c,\n\tb = ";
    std::cin >> b;

    std::cout << "\tc = ";
    std::cin >> c;
    return 0;
}
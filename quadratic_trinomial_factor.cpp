/*
Copyright Aritro Saha 2020

Program Description: given a quadratic equation in form of x^2 + bx + c, factor
                        the equation into (x ± c)(x ± d)
Inputs:
    From x^2 + bx + c:
        value of b
        value of c

Output:
    (x ± e)(x ± f)
    Steps to get factored form

*/

#include "quadratic_trinomial_factor.h"
#include <cmath>

std::ostream& operator << (std::ostream &os, const FactoredPolynomial &fp) {
    char e_polarity = fp.e > 0 ? '+' : '-';
    char f_polarity = fp.f > 0 ? '+' : '-';

   return (os << "( x " << e_polarity << " " << std::abs(fp.e) << " ) ( x " << e_polarity << " " << std::abs(fp.f) << " )" << std::endl); 
}

// Parameters are taken from x^2 + bx + c
struct FactoredPolynomial quadraticPolynomialFactor(long double b, long double c, bool showSteps = false)
{
    struct FactoredPolynomial poly;

    if (showSteps)
    {
        // Step 1: Divide the second coefficient (b) by 2
        long double tmp_step1 = b / 2;
        std::cout << "\nStep 1: Divide b by 2\n\t" << b << "/2=" << tmp_step1;

        // Step 2: Square the result of the previous step
        long double tmp_step2 = tmp_step1 * tmp_step1;
        std::cout << "\nStep 2: Square the result of the previous step\n\t" << tmp_step1 << " ^ 2 = " << tmp_step2;

        // Step 3: Find the result of the difference between the previous step and c
        long double tmp_step3 = std::abs(tmp_step2 - c);
        std::cout << "\nStep 3: Find the difference between the previous step and c\n\t|" << tmp_step2 << " - " << c << "| = " << tmp_step3;

        // Step 4: Square root the difference
        long double tmp_step4 = std::sqrt(tmp_step3);
        std::cout << "\nStep 4: Square root the difference\n\t" << tmp_step3 << " ^ 1/2 = " << tmp_step4;

        // Step 5: Add and subtract the square root to half of b to find e and f
        long double e = tmp_step1 + tmp_step4;
        long double f = tmp_step1 - tmp_step4;
        std::cout << "\nStep 5: Add and subtract the square root to half of b to find e and f\n\t" << b << " + " << tmp_step4 << " = " << e;
        std::cout << "\n\t" << b << " - " << tmp_step4 << " = " << f;

        // Final answer and steps in serial order
        char e_polarity = e > 0 ? '+' : '-';
        char f_polarity = f > 0 ? '+' : '-';

        std::cout << "\n\nSerialized Steps:";
        std::cout << "\n" << b << " / 2 = " << tmp_step1;
        std::cout << "\n"
                  << tmp_step1 << " ^ 2 = " << tmp_step2;
        std::cout << "\n|" << tmp_step2 << " - " << c << "| = " << tmp_step3;
        std::cout << "\n"
                  << tmp_step3 << " ^ 1/2 = " << tmp_step4;
        std::cout << "\n"
                  << b << " + " << tmp_step4 << " = " << e;
        std::cout << "\n"
                  << b << " - " << tmp_step4 << " = " << f;

        poly.e = e;
        poly.f = f;
    }
    else
    {
        long double divisionSquare = (b / 2) * (b / 2);
        long double rootedDifference = std::sqrt(std::abs(c - divisionSquare));
        poly.e = (b / 2) + rootedDifference;
        poly.f = (b / 2) - rootedDifference;
    }

    return poly;
}

int main()
{
    long double b = 0;
    long double c = 0;

    std::cout << "Program: Quadratic Trinomial Factor Machine (LQPFM)\nUsage: Factors quadratic trinomials and includes steps\nInput:\n\tFrom x^2 + bx + c:\n\t\tb\n\t\tc\nOutput: (x +- e)(x +- f)\n\n";

    std::cout << "If in form of x^2 + bx + c,\n\tb = ";
    std::cin >> b;

    std::cout << "\tc = ";
    std::cin >> c;
    
    FactoredPolynomial finalAns = quadraticPolynomialFactor(b, c, true);

    std::cout << "\n\nFinal answer: " << finalAns;
    return 0;
}
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


#include <iostream>
#include <cmath>


int main() {
    long double b = 0;
    long double c = 0;

    std::cout << 
    "Program: Quadratic Trinomial Factor Machine (LQPFM)\nUsage: Factors quadratic trinomials and includes steps\nInput:\n\tFrom x^2 + bx + c:\n\t\tb\n\t\tc\nOutput: (x +- e)(x +- f)\n\n";

    std::cout << "If in form of x^2 + bx + c,\n\tb = ";
    std::cin >> b;

    std::cout << "\tc = ";
    std::cin >> c;

    // Step 1: Divide the second coefficient (b) by 2
    long double tmp_step1 = b / 2;
    std::cout << "\nStep 1: Divide b by 2\n\tb/2=" << tmp_step1;

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
    std::cout << "\nb / 2 = " << tmp_step1;
    std::cout << "\n" << tmp_step1 << " ^ 2 = " << tmp_step2; 
    std::cout << "\n|" << tmp_step2 << " - " << c << "| = " << tmp_step3;
    std::cout << "\n" << tmp_step3 << " ^ 1/2 = " << tmp_step4;
    std::cout << "\n" << b << " + " << tmp_step4 << " = " << e;
    std::cout << "\n" << b << " - " << tmp_step4 << " = " << f;

    std::cout << "\n\nFinal answer: (x " << e_polarity << " " << std::abs(e) << ") (x " << f_polarity << " " << std::abs(f) << ")\n"; 
    return 0;
}
#include <iostream>

// In form of (x + e)(x + f) 
struct FactoredPolynomial {
    long double e;
    long double f;
};

std::ostream& operator<< (std::ostream &os, const FactoredPolynomial &fp);

struct FactoredPolynomial quadraticPolynomialFactor(long double, long double, bool);
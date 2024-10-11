#include <iostream>
#include <cmath>
#include <algorithm>

// Cumulative normal distribution function
double normalCDF(double x) {
    return 0.5 * erfc(-x / sqrt(2));
}

// Black-Scholes formula for call and put option
double blackScholesCall(double S, double X, double T, double r, double sigma) {
    double d1 = (log(S / X) + (r + 0.5 * sigma * sigma) * T) / (sigma * sqrt(T));
    double d2 = d1 - sigma * sqrt(T);

    return S * normalCDF(d1) - X * exp(-r * T) * normalCDF(d2);
}

double blackScholesPut(double S, double X, double T, double r, double sigma) {
    double d1 = (log(S / X) + (r + 0.5 * sigma * sigma) * T) / (sigma * sqrt(T));
    double d2 = d1 - sigma * sqrt(T);

    return X * exp(-r * T) * normalCDF(-d2) - S * normalCDF(-d1);
}

int main() {
    // Input parameters
    double S = 100.0;    // Stock price
    double X = 100.0;    // Strike price
    double T = 1.0;      // Time to expiration in years
    double r = 0.05;     // Risk-free rate (5%)
    double sigma = 0.2;  // Volatility (20%)

    // Calculate call and put option prices
    double callPrice = blackScholesCall(S, X, T, r, sigma);
    double putPrice = blackScholesPut(S, X, T, r, sigma);

    // Output the results
    std::cout << "Call Option Price: " << callPrice << std::endl;
    std::cout << "Put Option Price: " << putPrice << std::endl;

    return 0;
}


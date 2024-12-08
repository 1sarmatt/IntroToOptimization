#include <iostream>
#include <cmath>
#include <iomanip>

// Task 1: Bisection Method
double bisectionMethod(double a, double b, double epsilon) {
    auto f = [](double x) { return x * x * x - 6 * x * x + 11 * x - 6; };
    if (f(a) * f(b) >= 0) {
        std::cerr << "Invalid interval for the Bisection Method.\n";
        return NAN;
    }

    double c;
    while ((b - a) / 2.0 > epsilon) {
        c = (a + b) / 2.0;
        if (std::fabs(f(c)) < epsilon) {
            return c;
        }
        if (f(c) * f(a) < 0) {
            b = c;
        } else {
            a = c;
        }
    }
    return (a + b) / 2.0;
}

// Task 2: Golden Section Method
double goldenSectionMethod(double a, double b, double epsilon) {
    auto f = [](double x) { return (x - 2) * (x - 2) + 3; };
    const double phi = (1 + std::sqrt(5)) / 2.0;
    double resphi = 2 - phi;

    double c = a + resphi * (b - a);
    double d = b - resphi * (b - a);

    while ((b - a) > epsilon) {
        if (f(c) < f(d)) {
            b = d;
            d = c;
            c = a + resphi * (b - a);
        } else {
            a = c;
            c = d;
            d = b - resphi * (b - a);
        }
    }
    return (a + b) / 2.0;
}

// Task 3: Gradient Ascent Method
double gradientAscent(double x0, double alpha, int iterations) {
    auto f_prime = [](double x) { return -2 * x + 4; };

    double x = x0;
    for (int i = 0; i < iterations; ++i) {
        x += alpha * f_prime(x);
    }
    return x;
}

int main() {
    std::cout << std::fixed << std::setprecision(6);

    // Task 1: Bisection Method
    std::cout << "Task 1: Bisection Method\n";
    double root = bisectionMethod(1.0, 2.0, 1e-6);
    if (!std::isnan(root)) {
        std::cout << "Approximate root: " << root << "\n\n";
    }

    // Task 2: Golden Section Method
    std::cout << "Task 2: Golden Section Method\n";
    double xmin = goldenSectionMethod(0.0, 5.0, 1e-4);
    auto f = [](double x) { return (x - 2) * (x - 2) + 3; };
    std::cout << "Approximate xmin: " << xmin << "\n";
    std::cout << "f(xmin): " << f(xmin) << "\n\n";

    // Task 3: Gradient Ascent Method
    std::cout << "Task 3: Gradient Ascent Method\n";
    double xmax = gradientAscent(0.0, 0.1, 100);
    auto f_value = [](double x) { return -x * x + 4 * x + 1; };
    std::cout << "Approximate xmax: " << xmax << "\n";
    std::cout << "f(xmax): " << f_value(xmax) << "\n";

    return 0;
}

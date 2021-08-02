#include <iostream>
#include <cmath>
using namespace std;

int main() {

    int a, b, c;
    std::cout << "Enter coefficients of the equation in form ax^2 + bx + c = 0" << std::endl;
    std::cout << "a: ";
    std::cin >> a;
    std::cout << "b: ";
    std::cin >> b;
    std::cout << "c: ";
    std::cin >> c; 
    if (a == 0) {
        std::cout << "Thats not quadratic equation";
    }
    else {
        double d = pow(b, 2) - 4 * a * c;
        if (d < 0) {
            std::cout << "D is negative";
            return 0;
        }
        double x1 = (-b + sqrt(d)) / (2 * a);
        double x2 = (-b - sqrt(d)) / (2 * a);
        std::cout << x1 << std::endl;
        std::cout << x2 << std::endl;
    }
	return 0;
}
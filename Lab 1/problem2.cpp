#include <iostream>
#include <cmath>
using namespace std;

int main() {

    int number;
    int d = 2;
    cout << "Write the number you want to operate: ";
    cin >> number;
    number = abs(number);
    while (number % d != 0) {
        d++;
    }
    if (d == number) {
        cout << "The number " << number << " is Prime";
    }
    else {
        cout << "The number " << number << " is NOT Prime";
    }

	return 0;
}
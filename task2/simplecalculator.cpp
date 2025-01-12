#include <iostream>
using namespace std;
int main() {
    double num1, num2, result;
    char operation;
    cout << "You can perform addition (+), subtraction (-), multiplication (*), or division (/)." << endl;
    cout << "Enter the first number: ";
    cin >> num1;
    cout << "Enter the second number: ";
    cin >> num2;
    cout << "Enter an operation (+, -, *, /): ";
    cin >> operation;
    if (operation == '+') {
        result = num1 + num2;
        cout << "The result is: " << result << endl;
    } else if (operation == '-') {
        result = num1 - num2;
        cout << "The result is: " << result << endl;
    } else if (operation == '*') {
        result = num1 * num2;
        cout << "The result is: " << result << endl;
    } else if (operation == '/') {
        if (num2 != 0) {
            result = num1 / num2;
            cout << "The result is: " << result << endl;
        } else {
            cout << "Error: Division by zero is not allowed." << endl;
        }
    } else {
        cout << "Error: Invalid operation. Please use +, -, *, or /." << endl;
    }
    return 0;
}
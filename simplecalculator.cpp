/*  Developer : Saikat Acharjee
   * Project: Simple Calculator By taking User input
* Description:A Simple calculator program that performs basic arithmetic
               operations such as addition, subtraction, multiplication, and 
               division. Allow the user to input two numbers and choose an operators to perform there operation
*/

#include <iostream>
using namespace std;

int main() {
    double num1, num2;
    char op;
    double result;
    
     cout << "\t\t\t\t\t\tSimple Calculator by using C++ \n";
     cout << "________________________________________________________________________________________________________________________\n";
    
	 cout << "Input Type\t\t:\tYour Input\n";
    cout << "------------------------|-------------------\n";

    // Input section //
    cout << "Enter first number:\t|\t ";
    cin >> num1;
    cout << "------------------------|-------------------\n";
    cout << "Enter an operator:\n(+, -, *, /):\t\t|\t ";
    cin >> op;
    cout << "------------------------|-------------------\n";
    cout << "\nEnter second number:\t\t ";
    cin >> num2;
    cout << "------------------------|----------------------\n";

    // calculation based on operator
    switch(op) {
        case '+':
            result = num1 + num2;
            cout << "Result:\t\t\t|\t " << result << endl;
            break;
        case '-':
            result = num1 - num2;
            cout << "Result:\t\t\t|\t " << result << endl;
            break;
        case '*':
            result = num1 * num2;
            cout << "Result:\t\t\t|\t " << result << endl;
            break;
        case '/':
            if (num2 != 0) {
                result = num1 / num2;
                cout << "Result:\t\t\t|\t " << result << endl;
            } else {
                cout << "Error: Division by zero is not allowed." << endl;
            }
            break;
        default:
            cout << "Invalid operator!" << endl;
    }

    return 0;
}


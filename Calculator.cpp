// Calculator.cpp : Diese Datei enthält die Funktion "main". Hier beginnt und endet die Ausführung des Programms.
//

#include <iostream>
#include <cmath>
#include <string>

using std::cout;
using std::cin;
using std::string;

//calculates the result for an addition, subtraction, multiplication or division with two operands
string calculateResult() {
    double firstOperand = 0.0;
    double secondOperand = 0.0;
    double result = 0.0;
    char op = ' ';
    int resultLength = 0;
    bool invalidOperator = 0;
    bool invalidOperation = 0;
    string errorMessage = "";
    string resultMessage = "";

    do {
        invalidOperator = 0;
        invalidOperation = 0;

        cout << "Enter an operation (addition, subtraction, multiplication or division with two operands)\n";
        cout << "Any operators/operands after the second operand will be ignored!\n";
        cin >> firstOperand >> op >> secondOperand;
        cout << '\n';

        switch (op) {
            case '+':
                result = firstOperand + secondOperand;
                break;
            case '-':
                result = firstOperand - secondOperand;
                break;
            case '*':
                result = firstOperand * secondOperand;
                break;
            case 'x':
                result = firstOperand * secondOperand;
                break;
            case '/':
                if (secondOperand == 0) {
                    invalidOperation = 1;
                }
                else {
                    result = firstOperand / secondOperand;
                }
                break;
            case ':':
                if (secondOperand == 0) {
                    invalidOperation = 1;
                }
                else {
                    result = firstOperand / secondOperand;
                }
                break;
            default:
                invalidOperator = 1;
                break;
        }

        if (invalidOperator) {
            errorMessage = "Invalid operator! Only the following operators are valid: '+', '-', '*' or 'x', '/' or ':'\n\n";
            cout << errorMessage;
        } else if (invalidOperation) {
            errorMessage = "Invalid operation! You cannot divide by 0!\n\n";
            cout << errorMessage;
        }
    } while (invalidOperator || invalidOperation);

    resultMessage = "Result: " + std::to_string(round(result * 100.0) / 100); //round result to two decimal points
    resultLength = resultMessage.find(".") + 3; //trim result to two decimal points (remove trailing zeros)
    return resultMessage.substr(0, resultLength);
}

int main()
{
    string result = calculateResult();
    cout << result;
    return 0;
}

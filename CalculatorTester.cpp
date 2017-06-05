/**
 * Assignment 10X. Calculator
 *
 * An interactive calculator for arithmetic expressions with numbers
 * and the + - * / operators and parenthesized subexpressions.
 *
 * Extra credit #1: Allow leading + and -
 * Extra credit #2: Allow exponentiation with the ^ operator
 *
 * Author: Ron Mak
 *         Department of Computer Engineering
 *         San Jose State University
 */

#include <iostream>
#include <stdlib.h>
#include "Calculator.h"

using namespace std;

void evaluate_expression(Calculator& calculator);

/**
 * The main.
 */
int main()
{
    Calculator calculator;
    char ch;

    // Prompt for and evaluate arithmetic expressions.
    do
    {
        cout << endl << "Expression? ";

        cin >> ws;
        ch = cin.peek();

        // Evaluate the expression unless it's the end sentinel.
        if (ch != '.') evaluate_expression(calculator);
    } while (ch != '.');

    cout << endl << "Done!" << endl;
    return 0;
}

/**
 * Evaluate an arithmetic expression using a calculator.
 * @param calculator the calculator to use.
 */
void evaluate_expression(Calculator& calculator)
{
    try
    {
        // Evaluate the expression and print its value.
        cout << calculator.evaluate() << endl;

        // An = sign must follow the expression.
        char ch;
        cin >> ch;
        if (ch != '=') throw string("Unexpected ") + ch;
    }
    catch(string& msg)
    {
        cout << "***** " << msg << endl;
    }

    // Skip the rest of the input line.
    string rest_of_line;
    getline(cin, rest_of_line);
}

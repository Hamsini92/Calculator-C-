#include <iostream>
#include <stdlib.h>
#include <math.h>
#include "Calculator.h"

using namespace std;

/**
 * Default constructor.
 */
Calculator::Calculator()
{
}

/**
 * Destructor.
 */
Calculator::~Calculator()
{
}

/**
 * Public member function to evaluate an arithmetic expression.
 * @throw an error message if there was an error.
 */
double Calculator::evaluate() const throw(string)
{
    return expression();
}

/**
 * Private member function to evaluate an arithmetic expression.
 * @throw an error message if there was an error.
 */
double Calculator::expression() const throw(string)
{
    char ch;
    bool negative = false;

    cin >> ws;
    ch = cin.peek();

    // Is there a leading + or - sign?
    if (ch == '-')
    {
        cin >> ch;                  // read the -
        negative = true;            // and remember it
    }
    else if (ch == '+') cin >> ch;  // just read the +

    double value = term();          // evaluate the first term
    if (negative) value = -value;   // negate it if there was a leading -

    bool done = false;

    // Loop to evaluate any subsequent terms.
    do
    {
        // Skip blanks and check if there is a + or - operator.
        cin >> ws;
        ch = cin.peek();

        switch (ch)
        {
            case '+':
            {
                cin >> ch;        // read the +
                value += term();  // evaluate the next term and add its value
                break;
            }

            case '-':
            {
                cin >> ch;        // read the -
                value -= term();  // evaluate the next term and subtract its value
                break;
            }

            default: done = true; // no more terms
        }
    } while (!done);

    return value;  // the expression's value
}

/**
 * Member function to evaluate a term.
 * @throw an error message if there was an error.
 */
double Calculator::term() const throw(string)
{
    double value = power();  // evaluate the first power
    bool done = false;
    char ch;

    // Loop to evaluate any subsequent factors.
    do
    {
        // Skip blanks and check if there is a * or / operator.
        cin >> ws;
        ch = cin.peek();

        switch (ch)
        {
            case '*':
            {
                cin >> ch;         // read the *
                value *= power();  // evaluate the next power and multiply its value
                break;
            }

            case '/':
            {
                cin >> ch;                // read the /
                double value2 = power();  // evaluate the next power

                // Do the division unless the value is zero.
                if (value2 != 0) value /= value2;
                else
                {
                    throw string("Division by zero");
                    return 0;
                }

                break;
            }

            default: done = true;  // no more factors
        }
    } while (!done);

    return value;  // the term's value
}

/**
 * Member function to evaluate a power.
 * Evaluate consecutive powers from right to left.
 * @throw an error message if there was an error.
 */
double Calculator::power() const throw(string)
{
    double value = factor();  // evaluate the base factor
    bool done = false;
    char ch;

    // Loop to evaluate any subsequent powers.
    do
    {
        // Skip blanks and check if there is another ^ operator.
        cin >> ws;
        ch = cin.peek();

        if (ch == '^')
        {
            cin >> ch;                    // read the ^
            value = pow(value, power());  // raise the value to the next power
        }
        else done = true;                 // no more powers
    } while (!done);

    return value;
}

/**
 * Member function to evaluate a factor.
 * @throw an error message if there was an error.
 */
double Calculator::factor() const throw(string)
{
    cin >> ws;             // skip blanks
    char ch = cin.peek();  // what's the next input character?

    // Evaluate a number.
    if (isdigit(ch))
    {
        return number();  // evaluate and return a number's value
    }

    // Recursively evaluate a parenthesized subexpression.
    else if (ch == '(')
    {
        cin >> ch;                    // read the (
        double value = expression();  // evaluate the subexpression

        // The next character should be the matching )
        ch = cin.peek();
        if (ch == ')') cin >> ch;     // read the )
        else
        {
            throw string("Missing )");
        }

        return value;  // return the parenthesized subexpression's value
    }

    // Handle an invalid factor.
    else
    {
        throw string("Invalid factor");
        return 0;
    }
}

/**
 * Member function to evaluate a number.
 * @throw an error message if there was an error.
 */
double Calculator::number() const throw(string)
{
    double value;
    cin >> value;  // let >> read and evaluate the number
    return value;
}

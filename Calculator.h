#ifndef CALCULATOR_H_
#define CALCULATOR_H_

using namespace std;

/**
 * The arithmetic expression calculator.
 * Each member functions returns a calculated value
 * and can throw an error message.
 */
class Calculator
{
public:
    Calculator();
    virtual ~Calculator();

    double evaluate()   const throw(string);

private:
    double expression() const throw(string);
    double term()       const throw(string);
    double power()      const throw(string);
    double factor()     const throw(string);
    double number()     const throw(string);
};

#endif /* CALCULATOR_H_ */

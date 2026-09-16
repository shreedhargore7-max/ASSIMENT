#include <iostream>
using namespace std;

class Calculator
{
private:
  double a, b;

public:
  void getData()
  {
    cout << "Enter first operand: ";
    cin >> a;

    cout << "Enter second operand: ";
    cin >> b;
  }

  void calculate(char op)
  {
    switch (op)
    {
    case '+':
      cout << "Result = " << a + b << endl;
      break;

    case '-':
      cout << "Result = " << a - b << endl;
      break;

    case '*':
      cout << "Result = " << a * b << endl;
      break;

    case '/':
      if (b != 0)
        cout << "Result = " << a / b << endl;
      else
        cout << "Division by zero is not possible." << endl;
      break;

    default:
      cout << "Invalid operator." << endl;
    }
  }
};

int main()
{
  Calculator c;
  char op;

  c.getData();

  cout << "Enter operator (+, -, *, /): ";
  cin >> op;

  c.calculate(op);

  return 0;
}

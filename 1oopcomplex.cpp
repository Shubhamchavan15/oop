#include <iostream>
using namespace  std;
class Complex 
{
private:
    double real;
    double img;

public:
    Complex() //Constructor
    {
        real=0;
        img=0;
    }
    Complex(double r, double i) //parametarized constructor
    {
        real=r;
        img=i;
    }

    // Overloaded addition operator
    Complex operator+( Complex other)
    {
        return Complex(real + other.real, img + other.img);
    }

    // Overloaded multiplication operator
    Complex operator*( Complex other)
    {
        return Complex((real * other.real) - (img * other.img),
                       (real * other.img) + (img * other.real));
    }

    // Overloaded output stream operator
    friend ostream& operator<<(ostream& os, Complex& complex)
     {
        os << complex.real << "+" << complex.img << "i";
        return os;
    }

    // Overloaded input stream operator
    friend istream& operator>>(istream& is, Complex& complex) 
    {
        cout << "Enter real part: ";
        is >> complex.real;
        cout << "Enter imaginary part: ";
        is >> complex.img;
        return is;
    }
};

int main()
 {

    Complex c1, c2, result;

    // Read two complex numbers
    cout << "Enter the first complex number:\n";
    cin >> c1;
    cout << "Enter the second complex number:\n";
    cin >> c2;

    // Perform operations
    result = c1 + c2;
    cout << "Sum: " << result << endl;
    result = c1 * c2;
    cout << "Product: " << result << endl;
    return 0;
}
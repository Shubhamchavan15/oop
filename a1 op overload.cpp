#include <iostream>
using namespace std;

class Complex {
public:
    float real, img;

    Complex() {
        real = 0;
        img = 0;
    }

    Complex operator+(Complex);
    Complex operator*(Complex);
    friend ostream& operator<<(ostream&, Complex&);
    friend istream& operator>>(istream&, Complex&);
};

istream& operator>>(istream& is, Complex& obj) {
    is >> obj.real >> obj.img;
    return is;
}

ostream& operator<<(ostream& outt, Complex& obj) {
    outt << obj.real;
    if (obj.img >= 0) {
        outt << "+" << obj.img;
    } else {
        outt << obj.img;
    }
    outt << "i";
    return outt;
}

Complex Complex::operator+(Complex obj) {
    Complex temp;
    temp.real = real + obj.real;
    temp.img = img + obj.img;
    return temp;
}

Complex Complex::operator*(Complex obj) {
    Complex temp;
    temp.real = real * obj.real - img * obj.img;
    temp.img = real * obj.img + img * obj.real;
    return temp;
}

int main() {
    Complex a, b, c, d;
    cout << "1st complex number - Enter Real And Imaginary: ";
    cin >> a;
    cout << "2nd complex number - Enter Real And Imaginary: ";
    cin >> b;
    cout << "\nArithmetic Operations";
    c = a + b;
    cout << "\nAddition = " << c;
    d = a * b;
    cout << "\nMultiplication = " << d << endl;
    return 0;
}

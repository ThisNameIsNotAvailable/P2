//
//  main.cpp
//  zestaw4
//
//  Created by Alexey Valevich on 21/03/2021.
//

#include <iostream>

using namespace std;

class ComplexNumber {
    float realPart = 0, imaginaryPart = 0;
public:
    ComplexNumber(int real, int imaginary) {
        realPart = real;
        imaginaryPart = imaginary;
    }
    
    ComplexNumber() {
        
    }
    
    friend ComplexNumber operator+(const ComplexNumber& first, const ComplexNumber& second);
    friend ComplexNumber operator++(ComplexNumber& first, int);
    friend ComplexNumber operator++(ComplexNumber& first);
    friend ComplexNumber operator-(const ComplexNumber& first, const ComplexNumber& second);
    friend ComplexNumber operator-(const ComplexNumber& first);
    friend ComplexNumber operator--(ComplexNumber& first, int);
    friend ComplexNumber operator--(ComplexNumber& first);
    friend ComplexNumber operator*(const ComplexNumber& first, const ComplexNumber& second);
    friend ComplexNumber operator/(const ComplexNumber& first, const ComplexNumber& second);
    ComplexNumber& operator=(const ComplexNumber& second);
    ComplexNumber& operator+=(const ComplexNumber& second);
    ComplexNumber& operator-=(const ComplexNumber& second);
    ComplexNumber& operator*=(const ComplexNumber& second);
    ComplexNumber& operator/=(const ComplexNumber& second);
    friend bool operator==(const ComplexNumber& first, const ComplexNumber& second);
    friend ComplexNumber operator!(const ComplexNumber& first);
    friend ostream& operator<<(ostream& out, const ComplexNumber& first);
    friend istream& operator>>(istream& in, ComplexNumber& first);
};
ComplexNumber operator++(ComplexNumber& first, int) {
    ComplexNumber temp = first;
    first.imaginaryPart++;
    return temp;
}

ComplexNumber operator++(ComplexNumber& first) {
    ComplexNumber temp = first;
    first.realPart++;
    return temp;
}

ComplexNumber operator--(ComplexNumber& first, int) {
    ComplexNumber temp = first;
    first.imaginaryPart--;
    return temp;
}

ComplexNumber operator--(ComplexNumber& first) {
    ComplexNumber temp = first;
    first.realPart--;
    return temp;
}

ComplexNumber operator+(const ComplexNumber& first, const ComplexNumber& second) {
    return ComplexNumber(first.realPart + second.realPart, first.imaginaryPart + second.imaginaryPart);
}

ComplexNumber operator-(const ComplexNumber& first, const ComplexNumber& second) {
    return ComplexNumber(first.realPart - second.realPart, first.imaginaryPart - second.imaginaryPart);
}

ComplexNumber operator*(const ComplexNumber& first, const ComplexNumber& second) {
    return ComplexNumber(first.realPart * second.realPart - first.imaginaryPart * second.imaginaryPart,
                         first.realPart * second.imaginaryPart + first.imaginaryPart * second.realPart);
}

ComplexNumber operator!(const ComplexNumber& first) {
    return ComplexNumber(first.realPart, -first.imaginaryPart);
}

ComplexNumber operator/(const ComplexNumber& first, const ComplexNumber& second) {
    ComplexNumber temp = second * (!second);
    if(temp.realPart == 0) {
        throw new invalid_argument("DivisionByZeroError");
    }
    return ComplexNumber((first * (!second)).realPart / temp.realPart, (first * (!second)).imaginaryPart / temp.realPart);
}

bool operator==(const ComplexNumber& first, const ComplexNumber& second) {
    return first.realPart == second.realPart && first.imaginaryPart == second.imaginaryPart;
}

bool operator!=(const ComplexNumber& first, const ComplexNumber& second) {
    return !(first == second);
}

ComplexNumber& ComplexNumber::operator=(const ComplexNumber& second) {
    if(&second != this) {
        this->imaginaryPart = second.imaginaryPart;
        this->realPart = second.realPart;
    }
    return *this;
}

ComplexNumber& ComplexNumber::operator+=(const ComplexNumber& second) {
    this->imaginaryPart = this->imaginaryPart + second.imaginaryPart;
    this->realPart = this->realPart + second.realPart;
    return *this;
}

ComplexNumber& ComplexNumber::operator-=(const ComplexNumber& second) {
    this->imaginaryPart = this->imaginaryPart - second.imaginaryPart;
    this->realPart = this->realPart - second.realPart;
    return *this;
}

ComplexNumber& ComplexNumber::operator*=(const ComplexNumber& second) {
    *this = *this * second;
    return *this;
}

ComplexNumber& ComplexNumber::operator/=(const ComplexNumber& second) {
    *this = *this / second;
    return *this;
}

ComplexNumber operator-(const ComplexNumber& first) {
    return ComplexNumber(-first.realPart, -first.imaginaryPart);
}




istream& operator>>(istream& in, ComplexNumber& first) {
    in >> first.realPart >> first.imaginaryPart;
    return in;
}



ostream& operator<<(ostream& out, const ComplexNumber& first) {
    if(first.imaginaryPart == 0 && first.realPart == 0) {
        out << "0";
    }else if(first.realPart == 0) {
        out << first.imaginaryPart << "i";
    }else if(first.imaginaryPart == 0) {
        out << first.realPart;
    }else {
        if(first.imaginaryPart > 0) {
            if(first.imaginaryPart == 1) {
                out << first.realPart << "+i";
            }else
                out << first.realPart << "+" << first.imaginaryPart << "i";
        }else {
            if(first.imaginaryPart == -1) {
                out << first.realPart << "-i";
            }else
                out << first.realPart << "-" << -first.imaginaryPart << "i";
        }
    }
    return out;
}



int main() {
    ComplexNumber num(1,8), num2(2,3), num3;
    cout << num-- << " " << num << endl;
    cout << num++ << " " << num << endl;
    cout << --num << " " << num << endl;
    cout << ++num << " " << num << endl;
    cout << (num + num2) << endl;
    cout << (num * num2) << endl;
    num *= num2;
    cout << num << endl;
    cout << (num / num2) << endl;
    cout << (num == num2) << endl;
    return 0;
}

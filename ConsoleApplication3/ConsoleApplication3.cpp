
#include <iostream>
#include <limits>
#include <Windows.h>
#include <ostream>
#include <istream>

using namespace std;

class Integer {
    int value;
public:
    Integer()
    {
        this->value = 0;
    };

    Integer(int value) {
        this->value = value;
    }

    void setValue(int value) {
        this->value = value;
    }

    int getValue() {
        return this->value;
    }

    void Print() {

        cout << "Value - " << value;
    }

    Integer operator +(Integer& other)const {

        long double result = (double)this->value + (double)other.value;
        if (result > INT_MAX || result < INT_MIN) {
            throw "Incorrect value";
        }
        return (this->value + other.value);
    };

    Integer operator -(Integer& other) {
        long double result = (double)this->value - (double)other.value;
        if (result > INT_MAX || result < INT_MIN) {
            throw "Incorrect value";
        }
        return (this->value - other.value);
    };

    Integer operator *(Integer& other) {
        long double result = (double)this->value * (double)other.value;
        if (result > INT_MAX || result < INT_MIN) {
            throw "Incorrect value";
        }
        return (this->value * other.value);
    };

    Integer operator /(Integer& other) {
        long double result = (double)this->value / (double)other.value;
        if (result > INT_MAX || result < INT_MIN) {
            throw "Incorrect value";
        }
        return (this->value / other.value);
    };

    friend istream& operator>>(istream& stream, Integer& forInput);
};

ostream& operator<<(ostream& os, Integer& Output)
{
    return os << Output.getValue();
}

istream& operator>>(istream& is, Integer& Input)
{
    is >> Input.value;
    return is;
}

int main()
{


    Integer a;
    Integer b;
    Integer c;

    cout << "Enter 2 value's" << endl;
    cin >> a;
    cin >> b;
    try
    {
       
        c = a + b;
        cout << "a + b \t" << c << endl;
        c = a - b;
        cout << "a - b \t" << c << endl;
        c = a * b;
        cout << "a * b \t" << c << endl;
        c = a / b;
        cout << "a / b \t" << c << endl;

    }

    catch (const char* error)
    {
        cout << error;
    }

}

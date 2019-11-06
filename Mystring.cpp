#include <cstring>
#include <string>
#include <iostream>
#include "Mystring.h"

// No-args constructor.. Makes the string into "/0" or ""
Mystring::Mystring()
    : str{nullptr} {
        str = new char[1];
        *str = '\0';
}

// Overloaded constructor.. This is const so we don't mess up the string we're being passed.
Mystring::Mystring(const char* s)
    : str{nullptr} {
        if (s==nullptr) {
            str = new char[1];
            str = '\0';
    } else {
            str = new char[std::strlen(s) +1];
            std::strcpy(str, s);
    }
}

// Copy constructor
Mystring::Mystring(const Mystring &source)
    : str{nullptr} {
        str = new char[std::strlen(source.str) +1];
        std::strcpy(str, source.str);
}

// Destructor
Mystring::~Mystring() {
    delete [] str;
}

// Copy assignment
Mystring &Mystring::operator=(const Mystring &rhs) {
    std::cout << "Copy assignment." << std::endl;       // stub to function call
    
    if (this == &rhs)
        return *this;
        
    delete[] this->str; // same as delete[] str;
    str = new char[std::strlen(rhs.str) +1];
    std::strcpy(this->str, rhs.str);
    return *this;
}

// Move constructor
Mystring::Mystring(Mystring &&source)
    : str(source.str) {
        source.str = nullptr;
        std::cout << "Move constructor used." << std::endl;
}

// Move assignment operator
Mystring &Mystring::operator=(Mystring &&rhs) {
    std::cout << "Using move assignment operator." << std::endl;
    if (this == &rhs) // self assignment case
        return *this;
    delete[] str;
    str = rhs.str; // steal pointer
    rhs.str = nullptr;
    return *this;
    
}

// Make lower case function
Mystring Mystring::operator-() const {
    // Do not want to change object, hence const
    char *buff = new char[std::strlen(str) +1];
    std::strcpy(buff, str); // copy of str
    // set to lower
    for (size_t i{0}; i<std::strlen(buff);i++)
        buff[i] = std::tolower(buff[i]);
    // create temp object to hold buff, delete buff, return temp object
    Mystring temp {buff};
    delete[] buff;
    return temp;
}

// concatenate
Mystring Mystring::operator+(const Mystring &rhs) const {
    char *buff = new char[std::strlen(str) + std::strlen(rhs.str) +1];
    // copy str into buff
    std::strcpy(buff, str);
    // concatenate rhs with buff
    std::strcat(buff, rhs.str);
    // create temp object to hold buff, delete buff, return temp object
    Mystring temp {buff};
    delete[] buff;
    return temp;
}

// Overloaded equality operator
bool Mystring::operator==(const Mystring &rhs) const {
    return (std::strcmp(str, rhs.str) == 0);
}

// Display method
void Mystring::display() const {
    std:: cout << str << ": " << get_length() << std::endl;
}

// length getter
int Mystring::get_length() const { return std::strlen(str); }

// string getter
const char *Mystring::get_str() const { return str; }

// overloaded inseration opetator
std::ostream &operator<<(std::ostream &os, const Mystring &rhs) {
    os << rhs.str;
    return os;
}

// overload extraction operator
std::istream &operator>>(std::istream &is, Mystring &rhs) {
    char *buff = new char[1000];
    is >> buff;
    rhs = Mystring{buff}; // requires copy or move assignment
    delete [] buff;
    return is;
}

// Programming Challenge //
bool Mystring::operator!=(const Mystring &rhs) const {
    return !(std::strcmp(str, rhs.str) == 0);
}

bool Mystring::operator>(const Mystring &rhs) const {
    if (std::strcmp(str, rhs.str) < 0)
        return true;
    return false;
}

bool Mystring::operator<(const Mystring &rhs) const {
    if (std::strcmp(str, rhs.str) > 0)
        return true;
    return false;
}

Mystring Mystring::operator*(int n) {
    Mystring temp;
    for (int i{0}; i < n; i++)
        temp = temp + *this;
    return temp;
}
    
    


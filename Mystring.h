#ifndef _MYSTRING_H
#define _MYSTRING_H

class Mystring
{
    // overloaded >> and << operators
   friend std::ostream &operator<<(std::ostream &os, const Mystring &rhs);
   friend std::istream &operator>>(std::istream &is, Mystring &rhs); // not const because we're modifying this object based on input
   
private:
    char *str; // pointer to a char[] that holds a C-style string
    
public:
    Mystring();                         // No-args constructor 
    Mystring(const char* s);            // Overloaded constructor
    Mystring(const Mystring &source);   // Copy constructor
    ~Mystring();                        // Destructor
    
    Mystring &operator=(const Mystring &rhs); // Copy assignment... LHS = *this pointer
    
    Mystring(Mystring &&source);              // Move constructor
    Mystring &operator=(Mystring &&rhs);      // Move assignment
    
    Mystring operator-() const;               // Make lowercase version of string
    Mystring operator+(const Mystring &rhs) const;  // concatenate
    bool operator==(const Mystring &rhs) const;     // if (s1 == s2)
    
    void display() const;
    
    int get_length() const;             // geters
    const char *get_str() const;
    
    
    // Programming Challenge //
    bool operator!=(const Mystring &rhs) const;
    
    bool operator>(const Mystring &rhs) const;
    
    bool operator<(const Mystring &rhs) const;
    
    Mystring operator*(int n);

};

#endif // _MYSTRING_H

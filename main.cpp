#include <iostream>
#include "Mystring.h"

using namespace std;

int main() {
    
    /*Mystring empty; // no-args constructor
    Mystring larry("Larry"); // overloaded constructor
    Mystring stooge{"Larry"}; // copy constructor
    
    empty.display();
    larry.display();
    stooge.display();*/
    
    //////////////////////////////////////////////////////////////////////
                        // COPY ASSIGNMENT //
    
    /*Mystring a{"Hello"};        // overloaded constructor
    Mystring b;                 // no-args constructor
    b = a;                      // copy assignment or b.operator=(a)
    
    b = "This is a test.";      // b.operator=("This is a test.");*/
    
    //////////////////////////////////////////////////////////////////////
                        // MOVE CONSTRUCTOR //
    
    /*Mystring a{"Hello"};         // Overloaded constructor
    a.display();
    a = Mystring{"Hola"};       // Overloaded constructor then move assignment
    a.display();
    a = "Bonjour";              // Overloaded constructor then move assignment
    a.display();*/
    
    //////////////////////////////////////////////////////////////////////
                        // Overloading == and + operators //
    /*cout << boolalpha << endl;
    
    Mystring larry{"Larry"};
    Mystring moe{"Moe"};
    
    Mystring stooge = larry;
    larry.display();                    // Larry
    moe.display();                      // Moe
    
    cout << (larry == moe) << endl;     // false
    cout << (larry == stooge) << endl;  // true
    
    larry.display();                    // Larry
    Mystring larry2 =- larry;
    larry2.display();                   // larry
    
    Mystring stoges = larry + "Moe";    // ok with member function
    //Mystring stooges = "Larry" + moe; // compiler error
    
    Mystring two_stooges = moe + " " + "Larry";
    two_stooges.display();                          // Moe Larry
    
    Mystring three_stooges = moe + " " + larry + " " + "Curly"; // Moe Larry Curly
    three_stooges.display();*/
    
    /////////////////////////////////////////////////////////////////////
                        // Overloaded >> and << operators //

    /*Mystring larry {"Larry"};
    Mystring moe {"Moe"};
    Mystring curly;
    
    cout << "Enter the third stooge's first name: ";
    cin >> curly;
    
    cout << "The three stooges are " << larry << ", " << moe << ", and " << curly << endl;
    
    cout <<"\nEnter the three stooges names sperated by a space: ";
    cin >> larry >> moe >> curly;
    
    cout << "The three stooges are " << larry << ", " << moe << ", and " << curly << endl;*/
    
    /////////////////////////////////////////////////////////////////////////
                        // Programming Challenge //

    Mystring larry{"Larry"};
    Mystring larry1{"Larry"};
    cout << (larry1 != larry) << endl; // return 0
    
    larry = "Lar";
    larry1 = "Little Lar";
    cout << (larry1 != larry) << endl; // return 1
    
    Mystring apple{"Apple"};
    Mystring zeebra{"Zeebra"};
    cout << (apple > zeebra) << endl; // return 1
    cout << (zeebra > apple) << endl; // return 0
    cout << (zeebra < apple) << endl; // return 1
    cout << (apple < zeebra) << endl; // return 0
    
    Mystring abc{"ABC"};
    Mystring concat{""};
    concat = (abc*3);
    cout << concat << endl;
    
    
    return 0;
}
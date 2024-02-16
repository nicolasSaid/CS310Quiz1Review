#include <iostream>
#include "Movie.h"

using namespace std;

int main(){
    string s1, s2, s3, s4;
    s1 = "str1";
    s2 = "str2";
    s3 = "str3";
    s4 = "str4";

    cout << endl << endl;
/**
 * QUESTION:
 * 1. What constructors do each of
 * these lines call?
 * ANSWER:
 * 1. Value, copy, copy, default, assignment operator
 */

    Movie a(0, s1);
    Movie b(a);
    Movie c = a;
    Movie d;
    d = c;

    cout << endl << endl;

    // Checking to see what the values on a, b, c, d are.
    cout << "a.) " << a << endl;
    cout << "b.) " << b << endl;
    cout << "c.) " << c << endl;
    cout << "d.) " << d << endl;

    int n = 10;

    // Manually setting values
    b.set_title_pointer_memory(s2);
    b.num_inc_value(n);

    c.set_title_pointer_memory(s3);
    c.num_inc_reference(n);

    d.set_title_pointer_memory(s4);
    d.num_inc_value(n);

    cout << endl << endl;

    // Checking again
    cout << "a.) " << a << endl;
    cout << "b.) " << b << endl;
    cout << "c.) " << c << endl;
    cout << "d.) " << d << endl;

    return 0;

}

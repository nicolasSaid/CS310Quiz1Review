#include <iostream>
#include "Song.h"

using namespace std;

int main(){
    string s1, s2, s3, s4;
    s1 = "title1";
    s2 = "title2";
    s3 = "title3";
    s4 = "title4";

    cout << endl << endl;
/**
 * QUESTION:
 * 1. What constructors do each of
 * these lines call?
 **/

    Song a(0, s1);
    Song b(a);
    Song c = a;
    Song d;
    d = c;
    Song e;

    cout << endl << endl;

    // Checking to see what the values on a, b, c, d are.
    cout << "a.) " << a << endl;
    cout << "b.) " << b << endl;
    cout << "c.) " << c << endl;
    cout << "d.) " << d << endl;

    int n = 0;

    // Manually setting values
    b.set_title_pointer_memory(s2);
    b.plays_inc_value(n);

    c.set_title_pointer_memory(s3);
    c.plays_inc_reference(n);

    d.set_title_pointer_memory(s4);
    d.plays_inc_value(n);

    cout << endl << endl;

    // Checking again
    cout << "a.) " << a << endl;
    cout << "b.) " << b << endl;
    cout << "c.) " << c << endl;
    cout << "d.) " << d << endl;

    return 0;

}

// QUESTION:
// 11. Describe what this #include statement does
#include "Song.h"

using namespace std;

// QUESTION:
// 12. Why do we use 'Movie::'
// instead of 'class Movie{}' here?

Song::Song(){
    cout << "**DEFAULT CONSTRUCTOR CALLED**" << endl;

    // QUESTION:
    // 13. What is the purpose of this?
    title_pointer = nullptr;
}

Song::Song(int n, string const &str){
    cout << "**VALUE CONSTRUCTOR CALLED**" << endl;

    plays = n;

    // QUESTION:
    // 14. What does this line do?
    // What does 'new' do, and what
    // constructor is being called?
    //
    // 15. Where in memory does title_pointer reside?
    // What about the thing it points to?

    title_pointer = new string(str);
}

Song::Song(Song const &s){
    cout << "**COPY CONSTRUCTOR CALLED**" << endl;

    this->plays = s.plays;

    if(s.title_pointer == nullptr){
        this->title_pointer = nullptr;
        return;
    }

    // QUESTION:
    // 16. Complicated line. What are we
    // doing, and what are we AVOIDING
    // with this?
    this->title_pointer = new string(*(s.title_pointer));

    // Hint: start from the inside of parenthesis
    // and work your way out.
    // Hint: what would
    // 'this->title_pointer = s.title_pointer' do?
}

Song & Song::operator=(Song const &s){
    cout << "**OVERLOADED = OPERATOR CALLED**" << endl;

    // QUESTION:
    // 17. What does this do? Why do we bother?
    if(this == &s){return *this;}

    this->plays = s.plays;

    if(s.title_pointer == nullptr){
        this->title_pointer = nullptr;
        return *this;
    }

    this->title_pointer = new string(*(s.title_pointer));
    return *this;
}




void Song::set_title_pointer_memory(string const &str){

    // QUESTION:
    // 18. Why would we want this check? When could title_pointer be nulllptr?
    // Hint: Check the constructors
    if(title_pointer == nullptr){
        title_pointer = new string(str);
        return;
    }

    // QUESTION:
    // 19. Huh? Why aren't we using 'new' here?
    // I thought that if we were using the heap
    // that we assigned with 'new'? Why would we
    // do this?
    *title_pointer = str;
    // Hint: What would happen to the old string
    // that title_pointer points to if we used
    // 'new'?
}

string Song::get_str_from_title_pointer() const{

    // QUESTION:
    // 20. No way. This is getting ridiculous.
    // Why on earth does this WORK???
    return *&*&*&*&*&*&*&*&*&*&*&*&*title_pointer;

    //Hint: here's a diagram.
    /*
    *    title_pointer at          the string, at
    *    address 0x15            address 0x75
    *     ┌─────────┐             ┌──────────┐
    *     │         │             │          │
    * 0x15│  0x75   ├────────►0x75│ "string!"│
    *     │         │             │          │
    *     └─────────┘             └──────────┘
    */
}

// QUESTION:
// 21. What's going on here?
// Which of these two functions
// is *more* correct?
void Song::plays_inc_value(int n){
    n ++;
    plays = n;
}

void Song::plays_inc_reference(int &n){
    n ++;
    plays = n;
}



Song::~Song(){
    cout << "**DESTRUCTOR CALLED**" << endl;

    // QUESTION:
    // 22. What if 'title_pointer == nullptr'?
    delete title_pointer;
}

/**
 * QUESTIONS:
 * 23. What is the rule of 3?
 *
 * 24. What is the difference between compiling and linking?
 *
 * 25. What is the difference between the following lines:
 *
 * Movie *s1 = new Movie;
 * Movie *s2 = s1;
 *
 * and
 *
 * Movie s3;
 * Movie s4 = s3;
 */

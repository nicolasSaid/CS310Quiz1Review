// QUESTION:
// 11. Describe what this #include statement does
// ANSWER:
// 11. During the compilation step of a makefile, the compiler
// essentially copies the contents of the "Movie.h" file and pastes them
// here. That way, all of the scoping operators (Movie::) know
// where to go when they are defining the implementation of functions.
#include "Movie.h"

// QUESTION:
// 12. Why do we use 'Movie::'
// instead of 'class Movie{}' here?
// ANSWER:
// 12. We use 'Movie::' to tell the compiler "hey, go and define
// the functionality for this function, inside the Movie class".
// We do not use 'class Movie{}' because that would be telling the
// compiler, "hey, make me a NEW class named Movie", even though
// we have one already!

Movie::Movie(){
    std::cout << "**DEFAULT CONSTRUCTOR CALLED**" << std::endl;

    // QUESTION:
    // 13. What is the purpose of this?
    // ANSWER:
    // 13. the value of a member variable (unless declared statically,
    // I believe), is unpredictable. Prior to this line, title_pointer could
    // have the value 0x1234 or 0x4657, or anything! It COULD be a valid location!
    // Since we haven't initialized anything yet, we would rather set it to "nothing",
    // with nullptr.
    title_pointer = nullptr;
}

Movie::Movie(int n, std::string const &str){
    std::cout << "**VALUE CONSTRUCTOR CALLED**" << std::endl;

    num = n;

    // QUESTION:
    // 14. What does this line do?
    // What does 'new' do, and what
    // constructor is being called?
    //
    // 15. Where in memory does title_pointer reside?
    // What about the thing it points to?
    // ANSWER:
    // 14. This line is creating a new string (calling
    // a std::string constructor) with the value of 'str'.
    // then 'new' is setting aside enough memory on the HEAP
    // to store that string, and putting that heap address
    // into title_pointer.
    //
    // 15. Very tricky question. title_pointer will reside wherever
    // the Movie class is instantiated. It can be either on
    // the stack or the heap. However, the thing that the pointer
    // points to WILL be on the heap because of 'new'

    title_pointer = new std::string(str);
}

Movie::Movie(Movie const &s){
    std::cout << "**COPY CONSTRUCTOR CALLED**" << std::endl;

    this->num = s.num;

    if(s.title_pointer == nullptr){
        this->title_pointer = nullptr;
        return;
    }

    // QUESTION:
    // 16. Complicated line. What are we
    // doing, and what are we AVOIDING
    // with this?
    // ANSWER:
    // 16. This is
    // 1.) going to the location of title_pointer,
    // 2.) getting the string that is there
    // 3.) creating a new string with the same value as
    // the old string by calling a std::string constructor
    // 4.) setting aside enough memory on the heap
    // to store our new string
    // 5.) storing the address of that heap location in
    // title_pointer

    // Corresponding bullet points:
    //             5.)  4.)        3.) 2.)   1.)
    this->title_pointer = new std::string(*(s.title_pointer));
    // We are avoiding both the old Movie and our new Movie
    // having title_pointers that point to the same string.
    // That would be achieved with:
    // 'this->title_pointer = s.title_pointer'
    // See the difference?

    // Hint: start from the inside of parenthesis
    // and work your way out.
    // Hint: what would
    // 'this->title_pointer = s.title_pointer' do?
}

Movie & Movie::operator=(Movie const &s){
    std::cout << "**OVERLOADED = OPERATOR CALLED**" << std::endl;

    // QUESTION:
    // 17. What does this do? Why do we bother?
    // ANSWER:
    // 17. This checks for self assignment, like:
    // Movie a;
    // a = a;
    // Because if we DO write the above line, we don't actually want
    // anything to CHANGE in a.
    if(this == &s){return *this;}

    this->num = s.num;

    if(s.title_pointer == nullptr){
        this->title_pointer = nullptr;
        return *this;
    }

    this->title_pointer = new std::string(*(s.title_pointer));
    return *this;
}




void Movie::set_title_pointer_memory(std::string const &str){

    // QUESTION:
    // 18. Why would we want this check? When could title_pointer be nulllptr?
    // Hint: Check the constructors
    // ANSWER:
    // 18. When calling this function, there are two cases:
    // 1.) we have not yet allocated memory and stored the
    // address in title_pointer
    // 2.) we have.
    // If we have not yet stored something (title_pointer == nullptr),
    // we can safely reassign
    // title_pointer to a new address because we will not LOSE the
    // old address.
    if(title_pointer == nullptr){
        title_pointer = new std::string(str);
        return;
    }

    // QUESTION:
    // 19. Huh? Why aren't we using 'new' here?
    // I thought that if we were using the heap
    // that we assigned with 'new'? Why would we
    // do this?
    // ANSWER:
    // 19. The overloaded = operator belonging to the
    // std::string class is called, and changes the value of
    // the string on the heap to have the same characters
    // as the one passed as an argument into this function.
    // There is no need to re-allocate space, since we
    // trust that the string = operator works correctly.
    *title_pointer = str;
    // Hint: What would happen to the old string
    // that title_pointer points to if we used
    // 'new'?
}

std::string Movie::get_str_from_title_pointer() const{

    // QUESTION:
    // 20. No way. This is getting ridiculous.
    // Why on earth does this WORK???
    // ANSWER:
    // 20. & and * cancel each other out.
    // You can remove every pair from the below line
    // and end up with:
    //return *title_pointer
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
// ANSWER:
// 21.  See Movie.h, it's probably the first one of
// these two.
void Movie::num_inc_value(int n){
    n += 5;
    num = n;
}

void Movie::num_inc_reference(int &n){
    n += 5;
    num = n;
}



Movie::~Movie(){
    std::cout << "**DESTRUCTOR CALLED**" << std::endl;

    // QUESTION:
    // 22. What if 'title_pointer == nullptr'?
    // ANSWER:
    // 22. C++ allows you to call delete on a nullptr, no problem
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
 *
 * ANSWERS:
 * 23. If you're dealing with dynamic memory you need:
 * a. Copy constructor
 * b. Destructor
 * c. Assignment operator
 *
 * 24. Compiling takes an individual .cpp file and turns it into a .o file,
 * linking takes .o file(s) and turns them into an executable
 *
 * 25. The first lines sets both s1 and s2 to point to the SAME object.
 * The second lines assigns unique copies of an object to s3 and s4.
 *
 */

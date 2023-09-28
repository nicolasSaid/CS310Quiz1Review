/**
 * QUESTION:
 * 2. What are these? Why do we use them?
 * ANSWER:
 * 2. These are header guards. We include them
 * to prevent the same class from getting defined
 * multiple times.
 */
#ifndef MOVIE_H
#define MOVIE_H

#include <string>
#include <iostream>

class Movie{
    private:
        int num;
        std::string *title_pointer;

    public:
        /**
         * QUESTION:
         * 3. What are these functions? How are they different?
         *  Can you come up with the ways that they are called?
         * ANSWER:
         * 3. default constructor: Movie a;
         *    value constructor: Movie a(10, "string");
         *    copy constructor: Movie a(b);
         */
        Movie();
        Movie(int n, std::string const &str);
        Movie(Movie const &s);

        /**
         * QUESTION:
         * 4. This isn't a constructor, but we
         * need it... Why?
         *
         * 5. Why do we return a 'Movie&' instead
         * of void?
         *
         * ANSWER:
         * 4. We need it to assign the value of one Movie
         * to another.
         * Example:
         * Movie a, b;
         * a = b;
         *
         * 5. We return a `Movie&` to enable assignment chaining.
         * Example:
         * Movie a, b, c;
         * a = b = c;
         */

        Movie & operator=(Movie const &s);

        /**
         * QUESTION:
         * 6. How is the `const` keyword
         * different in these two cases?
         *
         * ANSWER:
         * 6.  the 'const' keyword in the first function ensures
         * that the string 'str' is never modified. The 'const' keyword
         * in the second ensures that the function does not modify
         * ANY member variables of the object it is called upon.
         */

        void set_title_pointer_memory(std::string const &str);
        std::string get_str_from_title_pointer() const;

        /**
         * QUESTION:
         * 7. How are these functions different?
         * ANSWER:
         * The first is pass by value, the second is pass
         * by reference. The first creates a copy (by calling the
         * copy constructor) of 'n' for the function to use/modify
         * as it likes. The second does not create a copy, allowing
         * the function to modify the 'n' that is outside of the
         * function.
         */
        void num_inc_value(int n);
        void num_inc_reference(int &n);

        /**
         * QUESTION:
         * 8. Without looking at the implementation
         * What *should* the destructor do?
         * ANSWER:
         * 8. it should use 'delete' on any dynamically
         * allocated memory belonging to the object.
         * In our case, it should 'delete' the 'title_pointer'
         */

        ~Movie();

        /**
         * QUESTION:
         * 9.What does this do?
         * Why do we define it as
         * a friend function?
         * ANSWER:
         * 9. This allows us to print the contents of our object
         * (among other things) by putting the member variables into an ostream.
         * It allows us to write the following code:
         * Movie a;
         * std::cout << a << std::endl;
         * The reason that we define it as a friend function is (in non-technical terms)
         * it really SHOULD be a member function of the ostream class, but since we can't
         * edit the ostream class source code -- we write it here and treat it like
         * a ostream member function.
         */
        friend std::ostream& operator<<(std::ostream &o, Movie const &s){
            o << "num=" << s.num;
            o << " | title_pointer points to ";

            if (s.title_pointer == nullptr){
                o << "a nullptr";
                return o;
            }

            /**
             * QUESTION:
             * 10. What could happen if we didn't
             * have the above check?
             * ANSWER: We could have a segmentation fault from dereferencing
             * a nullpointer, or even worse, undefined behavior!
             * We don't want that!
             */
            o << *(s.title_pointer);
            return o;
        }

};



#endif

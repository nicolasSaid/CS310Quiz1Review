/**
 * QUESTION:
 * 2. What are these? Why do we use them?
*/


#ifndef SONG_H
#define SONG_H

#include <string>
#include <iostream>

using namespace std;

class Song{
    private:
        int plays;
        string *title_pointer;

    public:
        /**
         * QUESTION:
         * 3. What are these functions? How are they different?
         * How can we call each of them?
         */


        Song();
        Song(int n, string const &str);
        Song(Song const &s);


        /**
         * QUESTION:
         * 4. This isn't a constructor, but it is still important. Why is that?
         * 
         * 5. Why do we return a 'Movie&'?
         */


        Song & operator=(Song const &s);



        /**
         * QUESTION:
         * 6. How is the `const` keyword
         * different in these two cases?
         */


        void set_title_pointer_memory(string const &str);
        string get_str_from_title_pointer() const;


        /**
         * QUESTION:
         * 7. How are these functions different?
         */


        void plays_inc_value(int n);
        void plays_inc_reference(int &n);


        /**
         * QUESTION:
         * 8. Without looking at the implementation
         * What *should* the destructor do?
         */

        ~Song();

        /**
         * QUESTION:
         * 9.What does this do?
         * Why do we define it as
         * a friend function?
         */
        
        friend ostream& operator<<(ostream &o, Song const &s){
            o << "plays=" << s.plays;
            o << " | title_pointer points to ";

            if (s.title_pointer == nullptr){
                o << "a nullptr";
                return o;
            }

            /**
             * QUESTION:
             * 10. What could happen if we didn't
             * have the above check?
             */
            o << *(s.title_pointer);
            return o;
        }

};



#endif







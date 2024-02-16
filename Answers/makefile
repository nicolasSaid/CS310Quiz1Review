all: mainexec 

#26. what does this command do to the object files?
#This command *links* the object files
mainexec: mainFile.o Movie.o 
	g++ mainFile.o Movie.o -o mainexec

#27. what does this command do to the source code files?
# this command *compiles* the source code
main.o: mainFile.cpp Movie.h
	g++ -c mainFile.cpp

#28. What do we call the Movie.o in line below? What do we call the files to the right of :?
# What do we call the line below that uses g++?
# Target: Dependencies
#     commands/rules
Movie.o: Movie.cpp Movie.h
	g++ -c Movie.cpp

clean:
	rm -f *.o mainexec
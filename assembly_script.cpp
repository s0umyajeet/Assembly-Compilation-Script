#include <iostream>	 //used cout
#include <string>        //used string
#include <string.h>	 //used strlen() function

using namespace std;

int main(int argc, char **argv) {
	/*
	  If number of arguments != 2, exit
	  First argument -- command -- ./asm64
   	  Second argument -- name of the assembly file without extension
	*/

	if (argc != 2) {
		cout << "Usage: ./asm64 <assembly-main-file> (no extension)\n";
		exit(1);
	}

	/*
	  Had to use string data type to be able to add the file name
	  to the command (see line 28, 29 below)
	*/

	string file = "";

	/*
	  Used for loop to transfer contents of argv[1] (assembly file name)
	  into the string variable 'file'
	*/

	for (int i = 0; i < strlen(argv[1]); i++) {
		file += argv[1][i];
	}

	string assemble = "nasm -f elf64 " + file + ".asm -o " + file + ".o -l " + file + ".lst";
	string link = "ld " + file + ".o -o " + file;

	/*
	  char* variables to store the final commands as the system() func
	  (line 52, 53) accepts const char* as arguments and not the
	  std C++ string data type.
	*/
	char* assemble_command;
	char* link_command;

	/*
	  for loops to convert the string commands into char* commands
	*/
	for (int i = 0; i < assemble.size(); i++) {
		assemble_command[i] = assemble[i];
	}

	for (int i = 0; i < link.size(); i++) {
		link_command[i] = link[i];
	}

	/*
	  Calling the commands using system function
	*/
	system(assemble_command);
	system(link_command);
	return 0;
}

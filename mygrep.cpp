#include <iostream>
#include <string>
#include "FileContents.h"

using namespace std; // should not use

// program that is a reduced version of the grep command in Linux, used version C++17
int main(int argc, char* argv[]) { // command line arguments

	string searchword; // keyword
	string filename; // filename to be given 
	string options; // options to be given

	if (argc == 1) { // basic program search (needle) string from given string (haystack)
		search_string_from_given_string();
	}
	else if (argc == 3) { // file + searchword + filename
		searchword = argv[1]; // searchword is the second command
		filename = argv[2]; // filename is the third command
		search_keyword_print_keyword_row_with_options(filename, searchword, options); // 
	}
	else if (argc == 4) { // file + options + searchword + filename
		options = argv[1];
		searchword = argv[2];
		filename = argv[3];
		if (is_valid_option(options)) { // check that option characters / command is valid
			search_keyword_print_keyword_row_with_options(filename, searchword, options); // 
		}
	} 
	else {
		cout << "Invalid parameter";
	}

	return 0;
}

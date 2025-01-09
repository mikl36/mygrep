#include "FileContents.h"
#include <iostream>
#include <fstream>
#include <algorithm>
#include <exception>
#include <string>

using namespace std; // should not use

struct optionvalues { // struct for values of options, could define options outside of the functions
	bool o = false; // false if not proven else, occurrences
	bool l = false; // line number
	bool i = false; // ignore case
	bool r = false; // reverse search
} option_values; // initialize

// file's basic program: give a string and search string, search string is compared to string
// and printed with position if found, otherwise a message that not found
// printing could / should combine with the second function
void search_string_from_given_string() {
	string str;
	string searchword;
	cout << "Give a string from which to search for: "; 
	getline(cin,str); // get string from where search the keyword

	cout << "Give search string: "; // give keyword
	getline(cin,searchword);
	cout << endl;

	size_t position = str.find(searchword); // to find the searchword from str, initial position

	// loop while can find the searchword, untill the end of the string
	if (position != string::npos) {
		while (position != string::npos) { 
			cout << "\"" << searchword << "\" found in \"" 
			<< str << "\" in position " << position << endl;
			position = str.find(searchword,position+1); // change the position to the next position to find
		}
	}
	else { // if cannot find the searchword from str
		cout << "\"" << searchword << "\" NOT found in \"" << str << "\"" << endl;
	}
}

// function to check that if option character is to be used
// could / should combine with the lower function
void if_option_character_valid (const string& OPTION) { 
	size_t o_double_position = OPTION.find("-o"); // for double o check that o is after '-o' to be true
	const int NEXT_CHARACTERS_CHECK = 2;
	option_values.o = (o_double_position != string::npos && 
	OPTION.find('o', o_double_position + NEXT_CHARACTERS_CHECK) != string::npos);
	option_values.l = (OPTION.find('l') != string::npos);
	option_values.r = (OPTION.find('r') != string::npos);
	option_values.i = (OPTION.find('i') != string::npos);
}

// function to check that option to be given is valid, 
// -o(lori or some kind of combination or just one character)
bool is_valid_option (const string& OPTION) { 
	const int SIZE = 3;
	// valid if size bigger than 2 and star with '-o'
	if (OPTION.size() < SIZE || OPTION.substr(0,2) != "-o") { 
		cout << "Invalid parameter" << endl;
		return false;
	}
	const string VALID_CHARS = "lori"; // to check if next charaters are valid "lori"
	for (size_t i=2; i < OPTION.size(); ++i) { // after -o = 2 check characters depending size
		char next_char = OPTION[i];
		if (VALID_CHARS.find(next_char) == string::npos) {
		cout << "Invalid parameter" << endl;
		return false;
		}
	}
	return true;
}

// print row(s) which have the keyword, options: o: occurrences of lines containing keyword, 
// l: print row numbers containing keyword, r: reverse search, 
// i: ignore keyword's upper or lower cases
void search_keyword_print_keyword_row_with_options(const string& FILENAME, string& searchword, const string& OPTIONS) {
	
	string input, original_searchword;
	original_searchword = searchword; // let's save the original searchword
	fstream file(FILENAME,ios::in);
	int occurrences = 0; // occurences of lines containing keyword
	int rownumber = 1; // row number, starting point 1

	if_option_character_valid(OPTIONS); // to check which option chars are to be used

	try {
		if (!file.fail()) { // if file opens, continue

    		while (getline(file, input)) { // read each line from the file, possibly use vector instead if bigger files
				if(option_values.i) { // to lower case input and searchword to make them equal
					transform(input.begin(), input.end(), input.begin(), ::tolower); 
					transform(searchword.begin(), searchword.end(), searchword.begin(), ::tolower);	
				}
					bool contains_searchword = (input.find(searchword) != string::npos); // true if input contains searchword
					// check that contains or NOT the keyword, for normal find or r: reverse find
					if ((option_values.r && !contains_searchword) || (!option_values.r && contains_searchword)) {
            			if(option_values.l) {
							cout << rownumber << ":"; // option l true, line numbering
						}
            			cout << input << endl; // printing row if containing or NOT keyword 
						occurrences++; // add one more to occurences if keyword found in line			
					}
        			rownumber++; // option l: add one more to row number
    		}
			if (option_values.o) { // option o true
				if (option_values.r) { // option r true
					cout << "\nOccurrences of lines NOT containing \"" 
					<< original_searchword << "\": " << occurrences << " "; 
				}
				else {
					cout << "\nOccurrences of lines containing \"" 
					<< original_searchword << "\": " << occurrences << " "; 
				}
			}
			if (occurrences == 0) { // print if keyword not found
				cout << "Value not found in file" << endl;
			}
    		file.close(); // closing the file
   		}
   		else {
    		throw runtime_error("ERROR: Cannot open file."); // error message if cannot open the file
   		}
	} catch (const exception& e) { // if try fails, catch and print the error
		cout << "An exception occurred: " << e.what() << endl;
	}
}

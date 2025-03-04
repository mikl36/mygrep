# A course project: a program to simulate grep command in Linux. A stripped-down version.

The program was developed using VS Code and the C++17 programming language (standard). The code is included in the attachment (mygrep.exe and FileContents.cpp). The program operates as follows:

- Main Program: Utilizes command-line arguments argc and argv. There are three different modes. Running the program with just the name (mygrep.exe) starts the basic program. With three command-line arguments, you can add a search term and a file to search within. With four command-line arguments, you can add options -o(l,o,r,i) for various search refinements. Any other number of arguments returns an error message.

- Basic Program: Executes a function that prompts for a string and a search term. The search term is looked for within the string, and if found, the line and position are printed. The search continues in a loop until no more matches are found, then the results are printed to the command prompt. If no match is found, a message is displayed.

- Three Command-Line Arguments: Executes functions based on the search term (2nd argument) and filename (3rd argument). The function attempts to open the file and read its lines. Exception handling ensures the file opens successfully; otherwise, an error is reported. If the file opens, all lines are read, and lines containing the search term are printed. If no match is found, a message is displayed. Finally, the file is closed.

- Four Command-Line Arguments: Executes functions based on the option(s) (2nd argument), search term (3rd argument), and filename (4th argument). The program checks if the given option is valid (-o(l,o,r,i)). If valid, the function performs the search with the specified options. The function operates similarly to the previous case but includes additional options:

i: Converts the search term and file content to lowercase for case-insensitive comparison.

l: Prints the line number of the matching line.

o: Prints occurrences of the search term within the lines.

r: Performs a reverse search, printing lines that do not contain the search term.


![image](https://github.com/user-attachments/assets/7bd7e020-6b6d-4c5d-9520-db2476062bb3)

![image](https://github.com/user-attachments/assets/f1c1ba9c-47e5-4f12-89f4-bb58961e9c78)

![image](https://github.com/user-attachments/assets/b6333c20-5b9c-4c15-aa9f-c2972587daff)

![image](https://github.com/user-attachments/assets/c1550c48-9b9d-4223-acf5-e748e83c16c3)

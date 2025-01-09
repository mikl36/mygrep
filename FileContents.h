#ifndef FILECONTENTS_H
#define FILECONTENTS_H

#include <string>

void search_string_from_given_string();
bool is_valid_option(const std::string& OPTION);
void search_keyword_print_keyword_row_with_options(const std::string& FILENAME, std::string& searchword, const std::string& OPTIONS = "");

#endif // FILECONTENTS_H

#ifndef UTILS_H
#define UTILS_H

#include <string>
#include <vector>

bool containsCode(const std::string& transmission, const std::string& code, int& position);
bool isPalindrome(const std::string& s);
std::pair<int, std::string> longestPalindrome(const std::string& transmission);
std::pair<int, std::string> longestCommonSubstring(const std::string& t1, const std::string& t2);
std::string readFile(const std::string& filename);

#endif//UTILS_H
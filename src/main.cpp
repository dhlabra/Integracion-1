#include <iostream>
#include "utils.h"

int main() {
    std::string transmission1 = readFile("C:/Users/super/CLionProjects/Integracion_continua/src/transmission1.txt");
    std::string transmission2 = readFile("C:/Users/super/CLionProjects/Integracion_continua/src/transmission2.txt");
    std::string mcode1 = readFile("C:/Users/super/CLionProjects/Integracion_continua/src/mcode1.txt");
    std::string mcode2 = readFile("C:/Users/super/CLionProjects/Integracion_continua/src/mcode2.txt");
    std::string mcode3 = readFile("C:/Users/super/CLionProjects/Integracion_continua/src/mcode3.txt");

    std::cout << "Parte 1: \n\n";

    int pos;
    std::cout << (containsCode(transmission1, mcode1, pos) ? "true " + std::to_string(pos) : "false") << std::endl;
    std::cout << (containsCode(transmission1, mcode2, pos) ? "true " + std::to_string(pos) : "false") << std::endl;
    std::cout << (containsCode(transmission1, mcode3, pos) ? "true " + std::to_string(pos) : "false") << std::endl;
    std::cout << (containsCode(transmission2, mcode1, pos) ? "true " + std::to_string(pos) : "false") << std::endl;
    std::cout << (containsCode(transmission2, mcode2, pos) ? "true " + std::to_string(pos) : "false") << std::endl;
    std::cout << (containsCode(transmission2, mcode3, pos) ? "true " + std::to_string(pos) : "false") << std::endl;

    std::cout << "\nParte 2: \n\n";
    std::pair<int, std::string> palindrome1 = longestPalindrome(transmission1);
    std::cout << palindrome1.first << " " << palindrome1.first + palindrome1.second.size() - 1 << " " << palindrome1.second << std::endl;

    std::pair<int, std::string> palindrome2 = longestPalindrome(transmission2);
    std::cout << palindrome2.first << " " << palindrome2.first + palindrome2.second.size() - 1 << " " << palindrome2.second << std::endl;

    std::cout << "\nParte 3: \n\n";
    std::pair<int, std::string> commonSubstring = longestCommonSubstring(transmission1, transmission2);
    std::cout << commonSubstring.first << " " << commonSubstring.first + commonSubstring.second.size() - 1 << " " << commonSubstring.second << std::endl;

    return 0;
}
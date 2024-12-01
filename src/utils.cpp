#include "utils.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>

bool containsCode(const std::string& transmission, const std::string& code, int& position) {
    size_t pos = transmission.find(code);
    if (pos != std::string::npos) {
        position = pos + 1;  // Devuelve la posición iniciando en 1
        return true;
    }
    return false;
}

bool isPalindrome(const std::string& s) {
    int left = 0;
    int right = s.size() - 1;
    while (left < right) {
        if (s[left] != s[right])
            return false;
        left++;
        right--;
    }
    return true;
}

std::pair<int, std::string> longestPalindrome(const std::string& transmission) {
    int maxLength = 0;
    std::pair<int, std::string> result(0, "");

    for (int i = 0; i < transmission.size(); i++) {
        for (int j = i; j < transmission.size(); j++) {
            std::string substring = transmission.substr(i, j - i + 1);
            if (isPalindrome(substring) && substring.size() > maxLength) {
                maxLength = substring.size();
                result = {i + 1, substring};  // Posición inicial y contenido
            }
        }
    }
    return result;
}

std::pair<int, std::string> longestCommonSubstring(const std::string& t1, const std::string& t2) {
    int maxLength = 0;
    int endPos = 0;
    std::vector<std::vector<int>> dp(t1.size() + 1, std::vector<int>(t2.size() + 1, 0));

    for (int i = 1; i <= t1.size(); i++) {
        for (int j = 1; j <= t2.size(); j++) {
            if (t1[i - 1] == t2[j - 1]) {
                dp[i][j] = dp[i - 1][j - 1] + 1;
                if (dp[i][j] > maxLength) {
                    maxLength = dp[i][j];
                    endPos = i;  // Guardar la posición final del substring
                }
            }
        }
    }

    // Obtener el substring más largo
    std::string longestSubstring = t1.substr(endPos - maxLength, maxLength);
    return {endPos - maxLength + 1, longestSubstring};  // Posición inicial y el substring
}

std::string readFile(const std::string& filename) {
    std::ifstream file(filename);

    std::stringstream result;
    result << file.rdbuf();
    return result.str();      // Convierte el bufferenunstring
}
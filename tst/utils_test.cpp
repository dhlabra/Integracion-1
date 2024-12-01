// utils_test.cpp
#include <gtest/gtest.h>
#include "utils.h"
#include <sstream>
#include <fstream>

// Prueba para containsCode
TEST(UtilsTest, ContainsCode) {
    std::string transmission = "Esta es una transmisión con código malicioso.";
    std::string code = "código";
    int position;

    EXPECT_TRUE(containsCode(transmission, code, position));
    EXPECT_EQ(position, 31);

    code = "ausente";
    EXPECT_FALSE(containsCode(transmission, code, position));
}

// Prueba para isPalindrome
TEST(UtilsTest, IsPalindrome) {
    EXPECT_TRUE(isPalindrome("radar"));
    EXPECT_FALSE(isPalindrome("hello"));
    EXPECT_TRUE(isPalindrome("a"));
    EXPECT_TRUE(isPalindrome(""));
}

// Prueba para longestPalindrome
TEST(UtilsTest, LongestPalindrome) {
    std::string transmission = "abcddcba123";
    auto result = longestPalindrome(transmission);

    EXPECT_EQ(result.second, "abcddcba");
    EXPECT_EQ(result.first, 1);
}

// Prueba para longestCommonSubstring
TEST(UtilsTest, LongestCommonSubstring) {
    std::string t1 = "abcdefg";
    std::string t2 = "zbcdfg";

    auto result = longestCommonSubstring(t1, t2);

    EXPECT_EQ(result.second, "bcdfg");
    EXPECT_EQ(result.first, 2);
}

// Prueba para readFile
TEST(UtilsTest, ReadFile) {
    std::string filename = "testfile.txt";

// Crear un archivo temporal para prueba
    std::ofstream testFile(filename);
    testFile << "Este es un archivo de prueba.";
    testFile.close();

    std::string content = readFile(filename);
    EXPECT_EQ(content, "Este es un archivo de prueba.");

// Limpiar el archivo de prueba
    std::remove(filename.c_str());
}
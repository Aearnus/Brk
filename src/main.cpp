#include <iostream>
#include <fstream>
#include <streambuf>
#include "lexer.hpp"

int main (int argc, char **argv)
{
    for (int i = 1; i < argc; i++) {
        char *filename = argv[i];

        std::ifstream file(filename);
        std::string content;

        file.seekg(0, std::ios::end);
        content.reserve(file.tellg());
        file.seekg(0, std::ios::beg);

        content.assign((std::istreambuf_iterator<char>(file)), std::istreambuf_iterator<char>());

        std::cout << content << std::endl;
        Lexer lexer(content);
    }

    std::cout << "Hello World!" << std::endl;

    return 0;
}
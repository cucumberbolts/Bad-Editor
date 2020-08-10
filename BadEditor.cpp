#include <iostream>
#include <string>
#include <fstream>

char StringToChar(std::string_view input) {
    char result = 0;

    for (int i = 0; i < input.size(); ++i) {
        if (input[i] == '1') {
            result += 1 << (7 - i);
        }
    }

    return result;
}

int main(int argc, const char** argv) {
    // You have to specify a file :)
    if (argc == 1) {
        std::cout << "No file specified!!!" << std::endl;
        return -1;
    }

    // Opens the specified file
    std::string fileName(argv[1]);
    std::ofstream stream(fileName, std::ios_base::app);

    if (!stream) {
        std::cout << "Could not open file " << fileName << std::endl;
        return -1;
    }

    // Gets users input
    std::string input;
    std::cin >> input;

    // Makes sure each charater is 8 bytes
    if (input.size() % 8 != 0) {
        std::cout << "Invalid input: Not in bytes!" << std::endl;
        return -1;
    }

    // Comverts input to binary and writes to file
    const char* index = input.c_str();
    for (int offset = 0; offset < input.size(); offset += 8) {
        stream << StringToChar(std::string_view(index + offset, 8));
    }
    stream.close();
}


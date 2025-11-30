#include "decoder.hpp"
#include <stdexcept>
#include <iostream>

// Expects each argument to be a Morse code string which it converts and prints to stdout
int main(int argc, char* argv[]) {
    if (argc < 2) {
        std::cerr << "Usage: " << argv[0] << " <morse_code1> <morse_code2> ...\n";
        return 1;
    }

    Decoder decoder;
    for (int i = 1; i < argc; ++i) {
        std::string morseCode = argv[i];
        char decodedChar = decoder.decode(morseCode);
        std::cout << decodedChar;
    }
    std::cout << std::endl;

    return 0;
}
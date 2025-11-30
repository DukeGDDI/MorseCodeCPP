#include "decoder.hpp"
#include <stdexcept>

Decoder::Decoder() {
    root = new Node(); // empty root

    // Build tree by inserting morse patterns
    insert(".-",   'A');
    insert("-...", 'B');
    insert("-.-.", 'C');
    insert("-..",  'D');
    insert(".",    'E');
    insert("..-.", 'F');
    insert("--.",  'G');
    insert("....", 'H');
    insert("..",   'I');
    insert(".---", 'J');
    insert("-.-",  'K');
    insert(".-..", 'L');
    insert("--",   'M');
    insert("-.",   'N');
    insert("---",  'O');
    insert(".--.", 'P');
    insert("--.-", 'Q');
    insert(".-.",  'R');
    insert("...",  'S');
    insert("-",    'T');
    insert("..-",  'U');
    insert("...-", 'V');
    insert(".--",  'W');
    insert("-..-", 'X');
    insert("-.--", 'Y');
    insert("--..", 'Z');
    // Numbers
    insert("-----", '0');
    insert(".----", '1');
    insert("..---", '2');
    insert("...--", '3');
    insert("....-", '4');
    insert(".....", '5');
    insert("-....", '6');
    insert("--...", '7');
    insert("---..", '8');
    insert("----.", '9');   
    // Punctuation
    insert(".-.-.-", '.');
    insert("--..--", ',');
    insert("..--..", '?');
    insert(".----.", '\'');
    insert("-.-.--", '!');
    insert("-..-.",  '/');
    insert("-.--.",  '(');
    insert("-.--.-", ')');
    insert(".-...",  '&');
    insert("---...", ':');
    insert("-.-.-.", ';');
    insert("-...-",  '=');
    insert(".-.-.",  '+');
    insert("-....-", '-');
    insert("..--.-", '_');
    insert(".-..-.", '"');
    insert("...-..-", '$');
    insert(".--.-.", '@');  
}

Decoder::~Decoder() {
    destroy(root);
}

// Insert a letter into the tree based on its Morse code
// ('.' for dot, '-' for dash)
void Decoder::insert(const std::string& morse, char letter) {
    Node* cur = root;
    for (char c : morse) {
        if (c == '.') {
            if (!cur->dot) cur->dot = new Node();
            cur = cur->dot;
        } else if (c == '-') {
            if (!cur->dash) cur->dash = new Node();
            cur = cur->dash;
        } else {
            throw std::invalid_argument("Invalid Morse symbol");
        }
    }
    cur->value = letter;
}

// Recursively destroy nodes
void Decoder::destroy(Node* n) {
    if (!n) return;
    destroy(n->dot);
    destroy(n->dash);
    delete n;
}

// Decode a Morse code string into a character
char Decoder::decode(const std::string& morse) const {
    const Node* cur = root;
    for (char c : morse) {
        if (c == '.') {
            if (!cur->dot) return '?';
            cur = cur->dot;
        } else if (c == '-') {
            if (!cur->dash) return '?';
            cur = cur->dash;
        } else {
            return '?';
        }
    }
    return cur->value ? cur->value : '?';
}

// Decode an Array of Morse code strings into a string
std::string Decoder::decode(const std::string* morseArray, size_t length) const {
    std::string result;
    for (size_t i = 0; i < length; ++i) {
        result += decode(morseArray[i]);
    }
    return result;
}
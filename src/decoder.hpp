#ifndef DECODER_HPP
#define DECODER_HPP

#include <string>

// Represents a single Morse-code tree node.
class Node {
public:
    char value;
    Node* dot;
    Node* dash;

    Node(char v = '\0') : value(v), dot(nullptr), dash(nullptr) {}
};


// Tree-based Morse decoder
class Decoder {
private:
    Node* root;

    void insert(const std::string& morse, char letter);
    void destroy(Node* n);

public:
    Decoder();
    ~Decoder();

    // Decode a Morse code string into a character (e.g., "..."" -> 'S')
    char decode(const std::string& morse) const;

    // Decode an Array of Morse code strings into a string (e.g., {"...", "---", "..."} -> "SOS")
    std::string decode(const std::string* morseArray, size_t length) const;

    // disable copying for simplicity
    Decoder(const Decoder&) = delete;
    Decoder& operator=(const Decoder&) = delete;
};

#endif

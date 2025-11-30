# Morse Code Decoder (C++ Binary Tree Example)

This project demonstrates how **binary trees** work in C++ by using them to
decode **Morse code**. Each letter in the Morse alphabet is stored in a binary
tree where:

- a **dot (·)** means go **left**
- a **dash (–)** means go **right**

The root node starts empty, and each letter is inserted by following its Morse
pattern through the tree. Decoding works by traversing from the root according
to a dot/dash string.

This project is intended as a simple educational example for learning:
- dynamic memory and pointer-based tree structures  
- binary tree traversal  
- mapping codes to characters  
- building and using a basic class in C++  

---

## 📁 Project Structure

```text
.
├── Makefile
├── README.md
├── src
│   ├── main.cpp
│   ├── decoder.cpp
│   └── decoder.hpp
└── build/        (generated automatically)
````

* `Node` — represents a node in the Morse binary tree
* `Decoder` — builds the Morse tree and provides a `decode()` method
* `main.cpp` — command-line tool that decodes Morse code arguments

---

## 🔧 Building

Run:

```bash
make
```

This compiles the source files into `build/` and produces the executable:

```bash
./morse
```

To clean the project:

```bash
make clean
```

---

## ▶️ Usage

The program expects each **command-line argument** (after the program name)
to be a Morse code sequence made of `.` and `-`. It decodes each argument
to a character and prints the resulting string.

### Example

```bash
./morse ".-" "-..." "-.-."
```

Output:

```text
ABC
```

If no Morse codes are provided, it prints a usage message and exits with a
non-zero status:

```bash
./morse
```

```text
Usage: ./morse <morse_code1> <morse_code2> ...
```

---

## 🧠 How the Decoder Works

* Each `Node` contains:

  * `char value` — the decoded character (or `'\0'` if empty)
  * `Node* dot` — pointer to next node on `.`
  * `Node* dash` — pointer to next node on `-`

* The `Decoder` constructor builds the entire alphabet by inserting:

  ```text
  A → .-
  B → -...
  C → -.-.
  ...
  ```

* The `decode()` function traverses the tree following the Morse pattern for each
  argument passed to `./morse`.

Unknown or invalid patterns return `'?'`.

---

## 📘 Educational Use

This project is excellent for demonstrating:

* pointer-based tree construction
* memory management and destructors
* class design (`Node` and `Decoder`)
* Makefile basics
* simple CLI tools and argument parsing


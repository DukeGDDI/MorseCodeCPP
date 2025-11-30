CXX      = g++
CXXFLAGS = -Wall -Wextra -pedantic -std=c++17 -g

SRC_DIR   = src
BUILD_DIR = build
TARGET    = morse

# All .cpp files in src/
SRCS := $(wildcard $(SRC_DIR)/*.cpp)
# Map src/foo.cpp -> build/foo.o
OBJS := $(patsubst $(SRC_DIR)/%.cpp,$(BUILD_DIR)/%.o,$(SRCS))

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $@ $^

# Compile any src/*.cpp into build/*.o
$(BUILD_DIR)/%.o: $(SRC_DIR)/%.cpp
	@mkdir -p $(BUILD_DIR)
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -rf $(BUILD_DIR) $(TARGET)

.PHONY: all clean

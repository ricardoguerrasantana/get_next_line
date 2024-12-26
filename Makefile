#	Makefile for Get Next Line project

# Test runner
NAME = test_runner

# Compiler and flags
CC = gcc
CFLAGS = -Wall -Wextra -Werror -I$(INCLUDE)
TEST_FLAGS = -lcriterion

# Directories
INCLUDE = include/
SRC_DIR = src/
TEST_DIR = tests/
OBJ_DIR = obj/
TEST_OBJ_DIR = test_obj/

# Source files
SRC = $(wildcard $(SRC_DIR)*.c)
TEST_SRC = $(wildcard $(TEST_DIR)*.c)

# Object files
OBJ = $(patsubst $(SRC_DIR)%.c, $(OBJ_DIR)%.o, $(SRC))
TEST_OBJ = $(patsubst $(TEST_DIR)%.c, $(TEST_OBJ_DIR)%.o, $(TEST_SRC))

# Default target (build the test runner)
all: $(NAME)

# Build the test runner
$(NAME): norm $(OBJ_DIR) $(TEST_OBJ_DIR) $(OBJ) $(TEST_OBJ)
	$(CC) $(OBJ) $(TEST_OBJ) -o $(NAME) $(TEST_FLAGS)

# Build object files
$(OBJ_DIR)%.o: $(SRC_DIR)%.c | $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

# Create object directory
$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

# Build test object files
$(TEST_OBJ_DIR)%.o: $(TEST_DIR)%.c | $(TEST_OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

# Create test object directory
$(TEST_OBJ_DIR):
	mkdir -p $(TEST_OBJ_DIR)

# Clean rule
clean:
	rm -rf $(OBJ) $(TEST_OBJ) $(OBJ_DIR) $(TEST_OBJ_DIR)

# Full clean rule
fclean: clean
	rm -f $(NAME)

# Remake rule
re: fclean all

# Norminette rule
norm:
	@norminette $(SRC) $(INCLUDE)

# Test rule
test: fclean $(NAME)
	@echo "Running tests..."
	./$(NAME)
	$(MAKE) fclean

# Test rule with TAP output format
test-tap: fclean $(NAME)
	@echo "Running tests with TAP format..."
	./$(NAME) --tap
	$(MAKE) fclean

# Test with valgrind
valgrind: $(NAME)
	valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes ./$(NAME)
	$(MAKE) fclean

.PHONY: all clean fclean re norm test test-tap valgrind

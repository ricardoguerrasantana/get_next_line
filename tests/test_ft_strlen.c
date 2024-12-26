#include <criterion/criterion.h>
#include "get_next_line.h" // Include your header file

// Test for basic strings
Test(ft_strlen, basic_strings) {
    cr_assert_eq(ft_strlen("hello"), 5, "Expected length: 5");
    cr_assert_eq(ft_strlen("C programming"), 13, "Expected length: 13");
}

// Test for empty string and single space
Test(ft_strlen, edge_cases) {
    cr_assert_eq(ft_strlen(""), 0, "Expected length: 0 for empty string");
    cr_assert_eq(ft_strlen(" "), 1, "Expected length: 1 for single space");
}

// Test for special characters
Test(ft_strlen, special_characters) {
    cr_assert_eq(ft_strlen("hello\nworld"), 11, "Expected length: 11 including newline");
    cr_assert_eq(ft_strlen("@#$%^&*()"), 9, "Expected length: 9 for symbols");
}

// Test for long strings
Test(ft_strlen, long_string) {
    char long_string[1001];
    for (int i = 0; i < 1000; i++) {
        long_string[i] = 'a';
    }
    long_string[1000] = '\0'; // Null-terminate the string
    cr_assert_eq(ft_strlen(long_string), 1000, "Expected length: 1000 for long string");
}

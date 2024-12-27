/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_strchr.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ricguerr <ricguerr@student.42adel.org.au>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/27 08:40:12 by ricguerr          #+#    #+#             */
/*   Updated: 2024/12/27 09:06:41 by ricguerr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <criterion/criterion.h>
#include "get_next_line.h"

// Test 1: character in middle
Test(ft_strchr, character_in_middle) {
    const char *s = "Hello, World!";
    char *result = ft_strchr(s, 'o');
    cr_assert_not_null(result, "ft_strchr returned NULL when 'o' is present.");
    cr_assert_str_eq(result, "o, World!", "Expected 'o, World!' but got '%s'", result);
}

// Test 2: character at beginning
Test(ft_strchr, character_at_beginning) {
    const char *s = "Hello";
    char *result = ft_strchr(s, 'H');
    cr_assert_not_null(result, "ft_strchr returned NULL when 'H' is present.");
    cr_assert_str_eq(result, "Hello", "Expected 'Hello' but got '%s'", result);
}

// Test 3: character at end
Test(ft_strchr, character_at_end) {
    const char *s = "Hello";
    char *result = ft_strchr(s, 'o');
    cr_assert_not_null(result, "ft_strchr returned NULL when 'o' is present.");
    cr_assert_str_eq(result, "o", "Expected 'o' but got '%s'", result);
}

// Test 4: null terminator
Test(ft_strchr, null_terminator) {
    const char *s = "Hello";
    char *result = ft_strchr(s, '\0');
    cr_assert_not_null(result, "ft_strchr returned NULL for null terminator.");
    cr_assert_eq(result, s + 5, "Result should point to string terminator");
    cr_assert_eq(*result, '\0', "Expected null terminator but got '%c'", *result);
}

// Test 5: character not found
Test(ft_strchr, character_not_found) {
    const char *s = "Hello";
    char *result = ft_strchr(s, 'x');
    cr_assert_null(result, "ft_strchr should return NULL when character is not found.");
}

// Test 5: empty string
Test(ft_strchr, empty_string) {
    const char *s = "";
    char *result = ft_strchr(s, 'a');
    cr_assert_null(result, "ft_strchr should return NULL for empty string.");
}

// Test 6: null string
Test(ft_strchr, null_string) {
    const char *s = NULL;
    char *result = ft_strchr(s, 'a');
    cr_assert_null(result, "ft_strchr should return NULL for NULL string.");
}

// Test 7: special character
Test(ft_strchr, special_characters) {
    const char *s = "Line1\nLine2";
    char *result = ft_strchr(s, '\n');
    cr_assert_not_null(result, "ft_strchr returned NULL when '\\n' is present.");
    cr_assert_str_eq(result, "\nLine2", "Expected '\\nLine2' but got '%s'", result);
}

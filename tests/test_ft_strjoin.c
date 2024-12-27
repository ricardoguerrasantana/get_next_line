/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_strjoin.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ricguerr <ricguerr@student.42adel.org.au>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/26 10:52:38 by ricguerr          #+#    #+#             */
/*   Updated: 2024/12/27 08:28:14 by ricguerr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include <criterion/criterion.h>
#include "get_next_line.h"
#include <string.h> // For strcmp

// Test 1: Basic concatenation
Test(ft_strjoin, basic_concatenation) {
    char *result = ft_strjoin("Hello", " World");
    cr_assert_not_null(result, "ft_strjoin returned NULL for valid inputs.");
    cr_assert_str_eq(result, "Hello World", "Expected 'Hello World' but got '%s'", result);
    free(result);
}

// Test 2: one of the strings is empty
Test(ft_strjoin, empty_strings) {
    char *result = ft_strjoin("", "World");
    cr_assert_not_null(result, "ft_strjoin returned NULL for valid inputs.");
    cr_assert_str_eq(result, "World", "Expected 'World' but got '%s'", result);
    free(result);

    result = ft_strjoin("Hello", "");
    cr_assert_not_null(result, "ft_strjoin returned NULL for valid inputs.");
    cr_assert_str_eq(result, "Hello", "Expected 'Hello' but got '%s'", result);
    free(result);
}

// Test 3: both strings are empty
Test(ft_strjoin, both_strings_empty) {
    char *result = ft_strjoin("", "");
    cr_assert_not_null(result, "ft_strjoin returned NULL for empty inputs.");
    cr_assert_str_eq(result, "", "Expected an empty string but got '%s'", result);
    free(result);
}

// Test 4: at least one of the strings is NULL
Test(ft_strjoin, null_strings) {
	char *result;
	
	result = ft_strjoin("Hello", NULL);
    cr_assert_null(result, "ft_strjoin not returned NULL when s2 was NULL.");
    free(result);

	result = ft_strjoin(NULL, "World");
    cr_assert_null(result, "ft_strjoin not returned NULL when s1 was NULL.");
    free(result);

    result = ft_strjoin(NULL, NULL);
    cr_assert_null(result, "ft_strjoin should return NULL when both inputs are NULL.");
    free(result);
}

// Test 6: special characters
Test(ft_strjoin, special_characters) {
    char *result = ft_strjoin("Line1\n", "Line2");
    cr_assert_not_null(result, "ft_strjoin returned NULL for valid inputs.");
    cr_assert_str_eq(result, "Line1\nLine2", "Expected 'Line1\\nLine2' but got '%s'", result);
    free(result);
}

// Test 7: long strings
Test(ft_strjoin, long_strings) {
    char *s1 = malloc(1001);
    char *s2 = malloc(1001);
    memset(s1, 'A', 1000);
    memset(s2, 'B', 1000);
    s1[1000] = '\0';
    s2[1000] = '\0';

    char *result = ft_strjoin(s1, s2);
    cr_assert_not_null(result, "ft_strjoin returned NULL for long strings.");
    cr_assert(strlen(result) == 2000, "Expected length 2000 but got %zu", strlen(result));

    for (int i = 0; i < 1000; i++) {
        cr_assert(result[i] == 'A', "Character mismatch at index %d. Expected 'A' but got '%c'", i, result[i]);
    }
    for (int i = 1000; i < 2000; i++) {
        cr_assert(result[i] == 'B', "Character mismatch at index %d. Expected 'B' but got '%c'", i, result[i]);
    }
    free(s1);
    free(s2);
    free(result);
}

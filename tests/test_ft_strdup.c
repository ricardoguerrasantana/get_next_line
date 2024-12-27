/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_strdup.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ricguerr <ricguerr@student.42adel.org.au>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/27 09:18:10 by ricguerr          #+#    #+#             */
/*   Updated: 2024/12/27 09:22:49 by ricguerr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <criterion/criterion.h>
#include "get_next_line.h"

// Test 1: basic string
Test(ft_strdup, basic_string) {
    const char *s = "Hello";
    char *result = ft_strdup(s);
    cr_assert_not_null(result, "ft_strdup returned NULL for valid input.");
    cr_assert_str_eq(result, "Hello", "Expected 'Hello' but got '%s'", result);
    free(result);
}

// Test 2: empty string
Test(ft_strdup, empty_string) {
    const char *s = "";
    char *result = ft_strdup(s);
    cr_assert_not_null(result, "ft_strdup returned NULL for empty input.");
    cr_assert_str_eq(result, "", "Expected an empty string but got '%s'", result);
    free(result);
}

// Test 3: special characters
Test(ft_strdup, special_characters) {
    const char *s = "Line1\nLine2\t";
    char *result = ft_strdup(s);
    cr_assert_not_null(result, "ft_strdup returned NULL for valid input.");
    cr_assert_str_eq(result, "Line1\nLine2\t", "Expected 'Line1\\nLine2\\t' but got '%s'", result);
    free(result);
}

// Test 4: null input
Test(ft_strdup, null_input) {
    const char *s = NULL;
    char *result = ft_strdup(s);
    cr_assert_null(result, "ft_strdup should return NULL for NULL input.");
}

// Test 5: long string
Test(ft_strdup, long_string) {
    char *s = malloc(1001);
    for (size_t i = 0; i < 1000; i++)
        s[i] = 'A';
    s[1000] = '\0';

    char *result = ft_strdup(s);
    cr_assert_not_null(result, "ft_strdup returned NULL for a long string.");
    cr_assert_str_eq(result, s, "Expected a string of 1000 'A's but got '%s'", result);

    free(s);
    free(result);
}

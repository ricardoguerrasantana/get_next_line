/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_strcpy.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ricguerr <ricguerr@student.42adel.org.au>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/27 08:03:15 by ricguerr          #+#    #+#             */
/*   Updated: 2024/12/27 08:17:48 by ricguerr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <criterion/criterion.h>
#include "get_next_line.h"
#include <string.h>

// Test 1: Basic copy
Test(ft_strcpy, basic_copy) {
    char dest[10];
    char *result = ft_strcpy(dest, "Hello");
    cr_assert_str_eq(dest, "Hello", "Expected 'Hello' but got '%s'", dest);
    cr_assert_eq(result, dest, "The return value should point to dest.");
}

// Test 2: Empty string
Test(ft_strcpy, empty_string) {
    char dest[10];
    char *result = ft_strcpy(dest, "");
    cr_assert_str_eq(dest, "", "Expected an empty string but got '%s'", dest);
    cr_assert_eq(result, dest, "The return value should point to dest.");
}

// Test 3: Special characters
Test(ft_strcpy, special_characters) {
    char dest[20];
    char *result = ft_strcpy(dest, "Line1\nLine2\t");
    cr_assert_str_eq(dest, "Line1\nLine2\t", "Expected 'Line1\\nLine2\\t' but got '%s'", dest);
    cr_assert_eq(result, dest, "The return value should point to dest.");
}

// Test 4: Self copy
Test(ft_strcpy, self_copy) {
    char buffer[20] = "Hello";
    char *result = ft_strcpy(buffer, buffer);
    cr_assert_str_eq(buffer, "Hello", "Expected 'Hello' but got '%s'", buffer);
    cr_assert_eq(result, buffer, "The return value should point to buffer.");
}

// Test 5: Null source
Test(ft_strcpy, null_source) {
    char dest[10];
    cr_expect_null(ft_strcpy(dest, NULL), "Expected NULL when src is NULL.");
}

// Test 6: Null destination
Test(ft_strcpy, null_destination) {
    cr_expect_null(ft_strcpy(NULL, "Hello"), "Expected NULL when dest is NULL.");
}

// Test 7: Large string
Test(ft_strcpy, large_string) {
    char src[1001];
    char dest[1001];
    memset(src, 'A', 1000);
    src[1000] = '\0';
    char *result = ft_strcpy(dest, src);
    cr_assert_str_eq(dest, src, "Expected a string of 1000 'A's but got '%s'", dest);
    cr_assert_eq(result, dest, "The return value should point to dest.");
}

// No need to pass this test as strcpy is not supposed to be used with insufficient destination size and out of this context
// // Test 8: Insufficient destination size
// Test(ft_strcpy, insufficient_destination_size) {
//     char dest[3];
//     cr_expect_null(ft_strcpy(dest, "Hello"), "Expected memory corruption or undefined behavior when destination size is insufficient.");
// }

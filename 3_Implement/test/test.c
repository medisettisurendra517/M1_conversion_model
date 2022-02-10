/**
 * @file test_project.c
 * @author your name (you@domain.com)
 * @brief Unity testing for Number System Converter
 * @version 0.1
 * @date 2022-10-02
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#include <string.h>
#include <stdio.h>
#include "../src/binary.h"
#include "../src/octal.h"
#include "../src/hexadecimal.h"
#include "../src/bcd.h"
#include "../src/xs.h"
#include "../src/gray.h"
#include "../unity/unity.h"
/**
 * @brief Set the Up object
 * 
 */
void setUp()
{
}
/**
 * @brief Required by the unity test framework 
 * 
 */
void tearDown()
{
}
/**
 * @brief Required by the unity test framework 
 * 
 */
void test_binary(void)
{
    Input_bin bin;
    Conversion_bin res_bin;
    bin.num = 0;
    bin.base = 2;
    res_bin = transformBinary(bin);
    TEST_ASSERT_EQUAL(0, *(res_bin.binary_op));

    bin.num = 83;
    bin.base = 2;
    res_bin = transformBinary(bin);
    TEST_ASSERT_EQUAL(1, *(res_bin.binary_op));
    TEST_ASSERT_EQUAL(1, *(res_bin.binary_op + 1));
    TEST_ASSERT_EQUAL(0, *(res_bin.binary_op + 2));
    TEST_ASSERT_EQUAL(0, *(res_bin.binary_op + 3));
    TEST_ASSERT_EQUAL(1, *(res_bin.binary_op + 4));
    TEST_ASSERT_EQUAL(0, *(res_bin.binary_op + 5));
    TEST_ASSERT_EQUAL(1, *(res_bin.binary_op + 6));
}
void test_octal(void)
{
    Input_oct oct;
    Conversion_oct res_oct;
    oct.num = 0;
    oct.base = 8;
    res_oct = transformOct(oct);
    TEST_ASSERT_EQUAL(0, *(res_oct.octal_op));
    oct.num = 83;
    oct.base = 8;
    res_oct = transformOct(oct);
    TEST_ASSERT_EQUAL(3, *(res_oct.octal_op));
    TEST_ASSERT_EQUAL(2, *(res_oct.octal_op + 1));
    TEST_ASSERT_EQUAL(1, *(res_oct.octal_op + 2));
    oct.num = 8;
    oct.base = 8;
    res_oct = transformOct(oct);
    TEST_ASSERT_EQUAL(0, *(res_oct.octal_op));
    TEST_ASSERT_EQUAL(1, *(res_oct.octal_op + 1));
}

void test_hexadecimal(void)
{
    Input_hex hexa;
    Conversion_hex res_hexa;
    hexa.num = 0;
    hexa.base = 16;
    res_hexa = transformHexadecimal(hexa);
    TEST_ASSERT_EQUAL(48, *(res_hexa.hexadecimal_op));
    hexa.num = 83;
    hexa.base = 16;
    res_hexa = transformHexadecimal(hexa);
    TEST_ASSERT_EQUAL(51, *(res_hexa.hexadecimal_op));
    TEST_ASSERT_EQUAL(53, *(res_hexa.hexadecimal_op + 1));
    hexa.num = 10;
    hexa.base = 16;
    res_hexa = transformHexadecimal(hexa);
    TEST_ASSERT_EQUAL(65, *(res_hexa.hexadecimal_op));
    hexa.num = 16;
    hexa.base = 16;
    res_hexa = transformHexadecimal(hexa);
    TEST_ASSERT_EQUAL(48, *(res_hexa.hexadecimal_op));
    TEST_ASSERT_EQUAL(49, *(res_hexa.hexadecimal_op + 1));
    hexa.num = 123;
    hexa.base = 16;
    res_hexa = transformHexadecimal(hexa);
    TEST_ASSERT_EQUAL(66, *(res_hexa.hexadecimal_op));
    TEST_ASSERT_EQUAL(55, *(res_hexa.hexadecimal_op + 1));
}

void test_bcd(void)
{
    Input_bcd bcd;
    Conversion_bcd res_bcd;
    bcd.num = 0;
    res_bcd = transformBcd(bcd);
    int x = res_bcd.arr_l;
    for (int i = x - 1; i >= 0; i--)
    {
        TEST_ASSERT_EQUAL(0, *(res_bcd.bcd_op + i));
    }
    bcd.num = 83;
    res_bcd = transformBcd(bcd);
    TEST_ASSERT_EQUAL(1, *(res_bcd.bcd_op));
    TEST_ASSERT_EQUAL(1, *(res_bcd.bcd_op + 1));
    TEST_ASSERT_EQUAL(0, *(res_bcd.bcd_op + 2));
    TEST_ASSERT_EQUAL(0, *(res_bcd.bcd_op + 3));
    TEST_ASSERT_EQUAL(0, *(res_bcd.bcd_op + 4));
    TEST_ASSERT_EQUAL(0, *(res_bcd.bcd_op + 5));
    TEST_ASSERT_EQUAL(0, *(res_bcd.bcd_op + 6));
    TEST_ASSERT_EQUAL(1, *(res_bcd.bcd_op + 7));
}

void test_xs(void)
{
    Input_xs xs;
    Conversion_xs res_xs;
    xs.num = 0;
    res_xs = transformXS(xs);
    int y = res_xs.arr_l;
    for (int i = y - 1; i >= 2; i--)
    {
        TEST_ASSERT_EQUAL(0, *(res_xs.xs_op + i));
    }
    for (int i = 1; i >= 0; i--)
    {
        TEST_ASSERT_EQUAL(1, *(res_xs.xs_op + i));
    }
    xs.num = 83;
    res_xs = transformXS(xs);
    TEST_ASSERT_EQUAL(0, *(res_xs.xs_op));
    TEST_ASSERT_EQUAL(1, *(res_xs.xs_op + 1));
    TEST_ASSERT_EQUAL(1, *(res_xs.xs_op + 2));
    TEST_ASSERT_EQUAL(0, *(res_xs.xs_op + 3));
    TEST_ASSERT_EQUAL(1, *(res_xs.xs_op + 4));
    TEST_ASSERT_EQUAL(1, *(res_xs.xs_op + 5));
    TEST_ASSERT_EQUAL(0, *(res_xs.xs_op + 6));
    TEST_ASSERT_EQUAL(1, *(res_xs.xs_op + 7));
}
void test_gray(void)
{
    Input_gray gray;
    Conversion_gray res_gray;
    gray.num = 0;
    res_gray = transformGray(gray);
    TEST_ASSERT_EQUAL(0, *(res_gray.gray_op));
    gray.num = 83;
    res_gray = transformGray(gray);
    TEST_ASSERT_EQUAL(0, *(res_gray.gray_op));
    TEST_ASSERT_EQUAL(1, *(res_gray.gray_op + 1));
    TEST_ASSERT_EQUAL(0, *(res_gray.gray_op + 2));
    TEST_ASSERT_EQUAL(1, *(res_gray.gray_op + 3));
    TEST_ASSERT_EQUAL(1, *(res_gray.gray_op + 4));
    TEST_ASSERT_EQUAL(1, *(res_gray.gray_op + 5));
    TEST_ASSERT_EQUAL(1, *(res_gray.gray_op + 6));
    gray.num = 8;
    res_gray = transformGray(gray);
    TEST_ASSERT_EQUAL(0, *(res_gray.gray_op));
    TEST_ASSERT_EQUAL(0, *(res_gray.gray_op + 1));
    TEST_ASSERT_EQUAL(1, *(res_gray.gray_op + 2));
    TEST_ASSERT_EQUAL(1, *(res_gray.gray_op + 3));
}
int main(void)
{
    /* Initiate the Unity Test Framework */
    UNITY_BEGIN();

    /* Run Test functions */
    RUN_TEST(test_binary);
    RUN_TEST(test_octal);
    RUN_TEST(test_hexadecimal);
    RUN_TEST(test_bcd);
    RUN_TEST(test_xs);
    RUN_TEST(test_gray);

    /* Close the Unity Test Framework */
    return UNITY_END();
}

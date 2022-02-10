/**
 * @file octal.h
 * @author your name (you@domain.com)
 * @brief Header file for octal (base-8) method
 * @version 0.1
 * @date 2022-10-02
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#include <stdio.h>
#include <stdlib.h>
/**
 * @brief Structures for storing the input & output stream
 * 
 */
typedef struct Conversion_oct
{
    int octal_op[50];
    int arr_l;
} Conversion_oct;
typedef struct Input_oct
{
    long int num;
    int base;
} Input_oct;
Conversion_oct transformOct(Input_oct a);

/**
 * @brief Function to convert a number from decimal to octal system
 * 
 * @param a 
 * @return Conversion_oct 
 */
Conversion_oct transformOct(Input_oct a)
{
    int num = a.num, b = a.base;
    int k = 0, store_num = num;
    Conversion_oct res;
    while (num != 0)
    {
        *(res.octal_op + k) = num % b;
        num /= b;
        k++;
    }
    res.arr_l = k;
    if (store_num == 0)
    {
        *(res.octal_op) = 0;
        res.arr_l = 1;
    }
    return res;
}

/**
 * @file hexadecimal.h
 * @author your name (you@domain.com)
 * @brief Header file for hexadecimal (base-16) method
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
typedef struct Conversion_hex
{
    char hexadecimal_op[50];
    int arr_l;
} Conversion_hex;
typedef struct Input_hex
{
    long int num;
    int base;
} Input_hex;
Conversion_hex transformHexadecimal(Input_hex a);

/**
 * @brief Function to convert a number from decimal to hexadecimal system
 * 
 * @param a 
 * @return Conversion_hex 
 */
Conversion_hex transformHexadecimal(Input_hex a)
{
    int num = a.num, b = a.base;
    int k = 0, store_num = num;
    Conversion_hex res;
    while (num != 0)
    {
        if (num % b < 10)
        {
            *(res.hexadecimal_op + k) = 48 + num % b;
            k++;
        }
        else
        {
            *(res.hexadecimal_op + k) = 55 + num % b;
            k++;
        }
        num = num / b;
    }
    res.arr_l = k;
    if (store_num == 0)
    {
        *(res.hexadecimal_op) = 48;
        res.arr_l = 1;
    }
    return res;
}
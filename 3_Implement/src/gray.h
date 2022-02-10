/**
 * @file gray.h
 * @author your name (you@domain.com)
 * @brief Header file for gray coding method
 * @version 0.1
 * @date 2022-10-022021-04-09
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
typedef struct Conversion_gray
{
    int gray_op[50];
    int arr_l;
} Conversion_gray;
typedef struct Input_gray
{
    int num;
} Input_gray;
Conversion_gray transformGray(Input_gray a);

/**
 * @brief Function to convert a number from decimal to Gray coding system
 * 
 * @param a 
 * @return Conversion_gray 
 */
Conversion_gray transformGray(Input_gray a)
{
    int num = a.num;
    int arr[50];
    int k = 0, store_num = num;
    Conversion_gray res;
    while (num != 0)
    {
        arr[k++] = num % 2;
        num = num / 2;
    }
    *(res.gray_op + k - 1) = *(arr + k - 1);
    for (int i = k - 2; i >= 0; i--)
    {
        *(res.gray_op + i) = *(arr + i) ^ *(arr + i + 1);
    }
    if (store_num == 0)
    {
        *(res.gray_op) = 0;
        k = 1;
    }
    res.arr_l = k;
    return res;
}

// Problem: Given an array of integers, count the frequency of each distinct element and print the result.

// Input:
// - First line: integer n (size of array)
// - Second line: n integers

// Output:
// - Print each element followed by its frequency in the format element:count

// Example:
// Input:
// 5
// 1 2 2 3 1

// Output:
// 1:2 2:2 3:1

#include <stdio.h>
#include <stdlib.h>
int main()
{
    int n;
    scanf("%d", &n);
    int a[n];
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }
    int freq[100] = {0}; // Assuming the elements are in the range 0-99
    for (int i = 0; i < n; i++)
    {
        freq[a[i]]++;
    }
    for (int i = 0; i < 100; i++)
    {
        if (freq[i] > 0)
        {
            printf("%d:%d ", i, freq[i]);
        }
    }
    return 0;
}
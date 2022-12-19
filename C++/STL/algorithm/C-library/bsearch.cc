#include <iostream>
#include <string>
#include <array>
#include <vector>
#include <deque>
#include <forward_list>
#include <list>
#include <set>
#include <unordered_set>
#include <map>
#include <unordered_map>
#include <stack>
#include <queue>
#include <algorithm>
#include <functional>
#include <numeric>
#include <iterator>

using namespace std;

#include <bits/stdc++.h>

/*

https://en.cppreference.com/w/cpp/algorithm/bsearch

Finds an element equal to element pointed to by key in an array pointed to by ptr. The array contains 
count elements of size bytes each and must be partitioned with respect to the object pointed to by key, 
that is, all the elements that compare less than must appear before all the elements that compare equal 
to, and those must appear before all the elements that compare greater than the key object. A fully 
sorted array satisfies these requirements. The elements are compared using function pointed to by comp.

The behavior is undefined if the array is not already partitioned in ascending order with respect to key, 
according to the same criterion that comp uses.

If the array contains several elements that comp would indicate as equal to the element searched for, 
then it is unspecified which element the function will return as the result.

Return value
Pointer to the found element or null pointer if the element has not been found.

Notes
Despite the name, neither C nor POSIX standards require this function to be implemented using binary 
search or make any complexity guarantees.

The two overloads provided by the C++ standard library are distinct because the types of the parameter 
comp are distinct (language linkage is part of its type).

*/

// below code example is from https://www.geeksforgeeks.org/stdbsearch-in-cpp/?ref=gcse

/*

std::bsearch in C++

Difficulty Level : Medium
Last Updated : 07 Aug, 2017
Basics of Binary Search

std::bsearch searches for an element in a sorted array. Finds an element equal to element pointed to by key 
in an array pointed to by ptr.
If the array contains several elements that comp would indicate as equal to the element searched for, then 
it is unspecified which element the function will return as the result.

Syntax :

void* bsearch( const void* key, const void* ptr, std::size_t count,
               std::size_t size, * comp );

Parameters :
key     -    element to be found
ptr     -    pointer to the array to examine
count    -    number of element in the array
size    -    size of each element in the array in bytes
comp    -    comparison function which returns ?a negative integer value if 
             the first argument is less than the second,
             a positive integer value if the first argument is greater than the second
             and zero if the arguments are equal.

Return value :
Pointer to the found element or null pointer if the element has not been found.
Implementing the binary predicate comp :

// Binary predicate which returns 0 if numbers found equal
int comp(int* a, int* b)
{
  
    if (*a < *b)
        return -1;
  
    else if (*a > *b)
        return 1;
  
    // elements found equal
    else
        return 0;
}
Implementation


// CPP program to implement
// std::bsearch
#include <bits/stdc++.h>
  
// Binary predicate
int compare(const void* ap, const void* bp)
{
    // Typecasting
    const int* a = (int*)ap;
    const int* b = (int*)bp;
  
    if (*a < *b)
        return -1;
    else if (*a > *b)
        return 1;
    else
        return 0;
}
  
// Driver code
int main()
{
    // Given array
    int arr[] = { 1, 2, 3, 4, 5, 6, 7, 8 };
  
    // Size of array
    int ARR_SIZE = sizeof(arr) / sizeof(arr[0]);
  
    // Element to be found
    int key1 = 4;
  
    // Calling std::bsearch
    // Typecasting the returned pointer to int
    int* p1 = (int*)std::bsearch(&key1, arr, ARR_SIZE, sizeof(arr[0]), compare);
  
    // If non-zero value is returned, key is found
    if (p1)
        std::cout << key1 << " found at position " << (p1 - arr) << '\n';
    else
        std::cout << key1 << " not found\n";
  
    // Element to be found
    int key2 = 9;
  
    // Calling std::bsearch
    // Typecasting the returned pointer to int
    int* p2 = (int*)std::bsearch(&key2, arr, ARR_SIZE, sizeof(arr[0]), compare);
  
    // If non-zero value is returned, key is found
    if (p2)
        std::cout << key2 << " found at position " << (p2 - arr) << '\n';
    else
        std::cout << key2 << " not found\n";
}

Output:

4 found at position 3
9 not found
Where to use :Binary search can be used on sorted data where a key is to be found. It can be used in cases 
like computing frequency of a key in a sorted list.

Why Binary Search?
Binary search is much more effective than linear search because it halves the search space at each step. 
This is not significant for our array of length 9. Here, linear search takes at most 9 steps and binary search 
takes at most 4 steps. But consider an array with 1000 elements, here linear search takes at most 1000 steps, 
while binary search takes at most 10 steps. For 1 billion elements, binary search will find our key in at 
most 30 steps.

*/

// Binary predicate
int compare(const void* ap, const void* bp)
{
    // Typecasting
    const int* a = (int*)ap;
    const int* b = (int*)bp;
  
    if (*a < *b)
        return -1;
    else if (*a > *b)
        return 1;
    else
        return 0;
}
  
// Driver code
int main()
{
    // Given array
    int arr[] = { 1, 2, 3, 4, 5, 6, 7, 8 };
  
    // Size of array
    int ARR_SIZE = sizeof(arr) / sizeof(arr[0]);
  
    // Element to be found
    int key1 = 4;
  
    // Calling std::bsearch
    // Typecasting the returned pointer to int
    int* p1 = (int*)std::bsearch(&key1, arr, ARR_SIZE, sizeof(arr[0]), compare);
  
    // If non-zero value is returned, key is found
    if (p1)
        std::cout << key1 << " found at position " << (p1 - arr) << '\n';
    else
        std::cout << key1 << " not found\n";
  
    // Element to be found
    int key2 = 9;
  
    // Calling std::bsearch
    // Typecasting the returned pointer to int
    int* p2 = (int*)std::bsearch(&key2, arr, ARR_SIZE, sizeof(arr[0]), compare);
  
    // If non-zero value is returned, key is found
    if (p2)
        std::cout << key2 << " found at position " << (p2 - arr) << '\n';
    else
        std::cout << key2 << " not found\n";
}


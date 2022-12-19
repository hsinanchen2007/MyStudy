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

https://en.cppreference.com/w/cpp/algorithm/qsort

Sorts the given array pointed to by ptr in ascending order. The array contains count elements 
of size bytes. Function pointed to by comp is used for object comparison.

If comp indicates two elements as equivalent, their order is unspecified.

If the type of the elements of the array is not a PODType (until C++11)TriviallyCopyable type 
(since C++11), the behavior is undefined.

Return value
(none)

Notes
Despite the name, C++, C, and POSIX standards do not require this function to be implemented 
using quicksort or make any complexity or stability guarantees.

The two overloads provided by the C++ standard library are distinct because the types of the 
parameter comp are distinct (language linkage is part of its type)

*/

// below code example is from https://www.geeksforgeeks.org/c-qsort-vs-c-sort/
// and https://www.programiz.com/cpp-programming/library-function/cstdlib/qsort
// However, my run actually shows qsort is faster on my machine!!!

/*

C qsort() vs C++ sort()

Difficulty Level : Medium
Last Updated : 14 Aug, 2018
Standard C library provides qsort function that can be used for sorting an array. Following is 
the prototype of qsort() function.

// Sort an array of any type. The parameters are, base
// address of array, size of array and pointer to
// comparator function
void qsort (void* base, size_t num, size_t size, 
            int (*comparator)(const void*, const void*));
It requires a pointer to the array, the number of elements in the array, the size of each element 
and a comparator function. We have discussed qsort comparator in detail here.

C++ Standard Library provides a similar function sort() that originated in the STL. We have discussed 
C++ sort here. Following are prototypes of C++ sort() function.

// To sort in default or ascending order.
template 
void sort(T first, T last);

// To sort according to the order specified
// by comp.
template
void sort(T first, T last, Compare comp);
The order of equal elements is not guaranteed to be preserved. C++ provides std::stable_sort that can 
be used to preserve order.

Comparison to qsort and sort()
1. Implementation details:
As the name suggests, qsort function uses QuickSort algorithm to sort the given array, although the 
C standard does not require it to implement quicksort.

C++ sort function uses introsort which is a hybrid algorithm. Different implementations use different 
algorithms. The GNU Standard C++ library, for example, uses a 3-part hybrid sorting algorithm: introsort 
is performed first (introsort itself being a hybrid of quicksort and heap sort) followed by an insertion 
sort on the result.

2. Complexity :
The C standard doesn’t talk about its complexity of qsort. The new C++11 standard requires that the 
complexity of sort to be O(Nlog(N)) in the worst case. Previous versions of C++ such as C++03 allow 
possible worst case scenario of O(N^2). Only average complexity was required to be O(N log N).

3. Running time:
STL’s sort ran faster than C’s qsort, because C++’s templates generate optimized code for a particular 
data type and a particular comparison function.

STL’s sort runs 20% to 50% faster than the hand-coded quicksort and 250% to 1000% faster than the C qsort 
library function. C might be the fastest language but qsort is very slow.

When we tried to sort one million integers on C++14, Time taken by C qsort() was 0.247883 sec and time 
taken by C++ sort() was only 0.086125 sec


// C++ program to demonstrate performance of
// C qsort and C++ sort() algorithm
#include <bits/stdc++.h>
using namespace std;
  
// Number of elements to be sorted
#define N 1000000
  
// A comparator function used by qsort
int compare(const void * a, const void * b)
{
    return ( *(int*)a - *(int*)b );
}
  
// Driver program to test above functions
int main()
{
    int arr[N], dupArr[N];
  
    // seed for random input
    srand(time(NULL));
  
    // to measure time taken by qsort and sort
    clock_t begin, end;
    double time_spent;
  
    // generate random input
    for (int i = 0; i < N; i++)
        dupArr[i] = arr[i] = rand()%100000;
  
    begin = clock();
    qsort(arr, N, sizeof(int), compare);
    end = clock();
  
    // calculate time taken by C qsort function
    time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
  
    cout << "Time taken by C qsort() - "
         << time_spent << endl;
  
    time_spent = 0.0;
  
    begin = clock();
    sort(dupArr, dupArr + N);
    end = clock();
  
    // calculate time taken by C++ sort
    time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
  
    cout << "Time taken by C++ sort() - "
         << time_spent << endl;
  
    return 0;
}
Output :

Time taken by C qsort() - 0.247883
Time taken by C++ sort() - 0.086125

C++ sort() is blazingly faster than qsort() on equivalent data due to inlining. sort() on a container 
of integers will be compiled to use std::less::operator() by default, which will be inlined and sort() 
will be comparing the integers directly. On the other hand, qsort() will be making an indirect call 
through a function pointer for every comparison which compilers fails to optimize.

4. Flexibility:
STL’s sort works for all data types and for different data containers like C arrays, C++ vectors, C++ 
deques, etc and other containers that can be written by the user. This kind of flexibility is rather 
difficult to achieve in C.

5. Safety:
Compared to qsort, the templated sort is more type-safe since it does not require access to data items 
through unsafe void pointers, as qsort does.

References:
http://theory.stanford.edu/~amitp/rants/c++-vs-c
https://en.wikipedia.org/wiki/Sort_(C%2B%2B)

This article is contributed by Aditya Goel. If you like GeeksforGeeks and would like to contribute, 
you can also write an article and mail your article to contribute@geeksforgeeks.org. See your article 
appearing on the GeeksforGeeks main page and help other Geeks.

Please write comments if you find anything incorrect, or you want to share more information about the topic discussed above

*/

// Number of elements to be sorted
#define N 1000000
  
// A comparator function used by qsort
int compare1(const void * a, const void * b)
{
    return ( *(int*)a - *(int*)b );
}

int compare2(const void* a, const void* b)
{
	const int* x = (int*) a;
	const int* y = (int*) b;

	if (*x > *y)
		return 1;
	else if (*x < *y)
		return -1;

	return 0;
}

// Driver program to test above functions
int main()
{
    cout << "Example 1" << endl;
    // 1st example
    int arr[N], dupArr[N];
  
    // seed for random input
    srand(time(NULL));
  
    // to measure time taken by qsort and sort
    clock_t begin, end;
    double time_spent;
  
    // generate random input
    for (int i = 0; i < N; i++)
        dupArr[i] = arr[i] = rand()%100000;
  
    begin = clock();
    qsort(arr, N, sizeof(int), compare1);
    end = clock();
  
    // calculate time taken by C qsort function
    time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
  
    cout << "Time taken by C qsort() - "
         << time_spent << endl;
  
    time_spent = 0.0;
  
    begin = clock();
    sort(dupArr, dupArr + N);
    end = clock();
  
    // calculate time taken by C++ sort
    time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
  
    cout << "Time taken by C++ sort() - "
         << time_spent << endl;
    cout << endl;

    // 2nd example
    cout << "Example 2" << endl;
	const int num = 10;
	int arr2[num] = {9,4,19,2,7,9,5,15,23,3};
	cout << "Before sorting" << endl;
	for (int i=0; i<num; i++)
		cout << arr2[i] << " ";

	qsort(arr2,num,sizeof(int),compare2);
	cout << endl << endl;
	cout << "After sorting" << endl;

	for (int i=0; i<num; i++)
		cout << arr2[i] << " ";
    cout << endl;

    return 0;
}


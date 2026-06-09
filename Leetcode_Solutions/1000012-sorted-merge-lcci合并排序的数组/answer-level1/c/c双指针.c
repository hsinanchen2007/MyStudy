```
#include <stdio.h>
#include <stdlib.h>


void merge(int *A, int ASize, int m, int *B, int BSize, int n)
{
    int total = m + n;
    int ia = m - 1;
    int ib = n - 1;
    int index = total - 1;
    while(ia >= 0 && ib >= 0) {
        if (A[ia] >= B[ib]) {
            A[index--] = A[ia--];
        } else {
            A[index--] = B[ib--];
        }
    }

    while (ib >= 0) {
        A[index--] = B[ib--];
    }
}

```

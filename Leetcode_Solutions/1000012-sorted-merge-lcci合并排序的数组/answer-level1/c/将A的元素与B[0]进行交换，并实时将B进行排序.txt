### 解题思路
B[0] 与 A[i] 进行排序；
然后将B进行排序

### 代码

```c
#define SWAP(A, B) do {   \
    int temp;   \
    temp = A;   \
    A = B;  \
    B = temp;   \
} while(0)

void BubbleSort(int *B, int n)
{
    int i;
    for(i = 0; i < (n - 1); ++i) {
        if (B[i] > B[i + 1]) {
            SWAP(B[i], B[i + 1]);
        } else {
            break;
        }
    }
    return;
}

void merge(int* A, int ASize, int m, int* B, int BSize, int n){
    int i;
    if (A == NULL || B == NULL) {
        return;
    }
    if (ASize == 0 || BSize == 0 || n == 0) {
        return;
    }

    for(i = 0; i < m; ++i) {
        if(A[i] <= B[0]) {
            continue;
        } else {
            SWAP(A[i], B[0]);
            BubbleSort(B, n);
        }
    }
    for (i = 0; i < n; ++i) {
        A[m + i] = B[i];
    }
    return;
}
```
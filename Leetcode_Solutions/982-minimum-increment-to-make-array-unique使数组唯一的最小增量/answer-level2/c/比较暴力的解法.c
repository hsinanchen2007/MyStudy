### 解题思路
就当复习一下快排。

### 代码

```c
void quick_sort(int left, int right, int* A) {
    if (left >= right) {
        return;
    }
    int base = A[left];
    int i = left;
    int j = right;
    while (i < j) {
        while (i < j && A[j] >= base) {
            --j;
        }
        if (i < j) {
            int tmp = A[i];
            A[i] = A[j];
            A[j] = tmp;
        }
        while (i < j && A[i] <= base) {
            ++i;
        }
        if (i < j) {
            int tmp = A[i];
            A[i] = A[j];
            A[j] = tmp;           
        }
    }
    quick_sort(left, i-1, A);
    quick_sort(i+1, right, A);
}

int minIncrementForUnique(int* A, int ASize){
    int i;
    int count;
    if (A == NULL || ASize <= 0) {
        return 0;
    }
    quick_sort(0, ASize-1, A);
    count = 0;
    for (i = 1; i < ASize; i++) {
        while (A[i] <= A[i-1]) {
            ++A[i];
            ++count;
        }
    }
    return count;
}
```
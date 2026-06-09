### 解题思路
C语言：
先把B的元素放进A的后面，然后用qsort排序

### 代码

```c
int Compare(const void *a, const void *b) {
    return (*(int *)a - *(int *)b);
}

void merge(int* A, int ASize, int m, int* B, int BSize, int n){
    if (A == NULL) {
        return;
    }

    if (B == NULL || n == 0) {
        return;
    }

    for (int i = 0; i < n; i++) {
        A[m + i] = B[i];
    }

    qsort(A, m + n, sizeof(int), Compare);
    return;
}
```
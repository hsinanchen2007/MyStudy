### 解题思路
此处撰写解题思路

### 代码

```c
int comp(const void *a, const void *b)
{
    return (*(int*)a - *(int*)b);
}

void merge(int* A, int ASize, int m, int* B, int BSize, int n){
    for (int i = 0; i < n; i++) {
        A[m + i] = B[i];
    }

    qsort(A, (m + n), sizeof(int), comp);

    return;
}
```
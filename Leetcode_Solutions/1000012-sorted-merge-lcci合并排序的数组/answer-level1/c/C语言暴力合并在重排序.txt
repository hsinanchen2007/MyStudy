### 解题思路
暴力合并在重排序

### 代码

```c
int cmp(const void *a, const void *b)
{
    return *((int *)a) - *((int *)b);
}

void merge(int* A, int ASize, int m, int* B, int BSize, int n)
{
    if ((A == NULL) || (ASize == 0)) {
        return;
    }

    if ((B == NULL) || (BSize == 0) || (n == 0)) {
        return;
    }

    int index;
    int bIndex;
    for (index = m, bIndex = 0; (index < ASize) && (bIndex < n); index++) {
        A[index] = B[bIndex++];
    }

    qsort(A, m + n, sizeof(int), cmp);

    return;
}
```
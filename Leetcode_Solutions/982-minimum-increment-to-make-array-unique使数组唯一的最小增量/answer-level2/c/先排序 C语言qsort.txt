### 解题思路
此处撰写解题思路

### 代码

```c
int cmp(void *a, void *b)
{
    return *(int *)a > *(int *)b;
}

int minIncrementForUnique(int* A, int ASize){
    int res = 0;
    qsort(A, ASize, sizeof(int), cmp);
    for (int i = 1; i < ASize; i++) {
#if 0
        for (int j = 0; j < ASize; j++) {
            printf("%d ", A[j]);
        }
        printf("\n");
#endif
        while (A[i] <= A[i - 1]) {
            A[i]++;
            res++;
        }
    }
    return res;
}
```
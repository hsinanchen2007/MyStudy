### 代码

```c
static int
cmpint(const void *p1, const void *p2)
{
        int a = *(int *)p1;
        int b = *(int *)p2;
        return a > b ? 1 : 0;
}

int minIncrementForUnique(int *A, int ASize)
{
        int i;
        int rc = 0;
        qsort(A, ASize, sizeof(int), cmpint);

        for (i = 1; i < ASize; i++) {
                if (A[i] <= A[i - 1]) {
                       rc += 1 + A[i - 1] - A[i];
                       A[i] = 1 + A[i - 1];
                }
        }
        return rc;
}
```
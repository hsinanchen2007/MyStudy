### 贪心算法

```C
int comp(void *a, void *b) {
    int rt = *(int *)a - *(int *)b;
    if (rt > 0) {
        return 1;
    }
    if (rt < 0) {
        return -1;
    }
    return 0;
}

int minIncrementForUnique(int* A, int ASize){
    int res = 0;
    qsort(A, ASize, sizeof(int), comp);
    for(int i = 1; i < ASize; i++) {
        if(A[i] <= A[i - 1]) {
            res += A[i - 1] - A[i] + 1;
            A[i] = A[i - 1] + 1;
        }
    }
    return res;
}
```
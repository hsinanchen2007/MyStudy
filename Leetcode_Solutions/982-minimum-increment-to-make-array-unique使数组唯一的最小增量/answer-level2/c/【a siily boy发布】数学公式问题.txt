```
int cmp(const void *a, const void *b) {
    return *(int *)a - *(int *)b;
}

#define tttt(a, b) (a > b ? (a - b) : (b - a))

int minIncrementForUnique(int* A, int ASize){
    int i;
    int returnCount = 0;
    int tmpValue;
    if ((A == NULL) || (ASize == 0)) {
        return 0;
    }
    qsort(A, ASize, sizeof(A[0]), cmp);
    //printf("A[0]: %u", A[0]);

    for (i = 0; i < ASize - 1; i++) {
        if (A[i + 1] <= A[i]) {
            tmpValue = A[i + 1];
            A[i + 1] = A[i] + 1;
            returnCount = returnCount + tttt(tmpValue, A[i]) + 1;
        }
    }

    return returnCount;
}
```

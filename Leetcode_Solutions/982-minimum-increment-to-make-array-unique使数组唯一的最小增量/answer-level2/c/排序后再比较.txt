```
int CMP(const void *a, const void *b)
{
    return *(int *)a - *(int *)b;
}
int minIncrementForUnique(int* A, int ASize){
    qsort(A, ASize, sizeof(int), CMP);
    int i;
    int cnt = 0;

    if (ASize < 2) {
        return 0;
    }

    int tmp = A[0];
    for (i = 1; i < ASize; i++) {
        if (A[i] <= tmp) {
            cnt += (tmp + 1 - A[i]);
            tmp++;
        } else {
            tmp = A[i];
        }
    } 
    
    return cnt;
}
```
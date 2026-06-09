### 解题思路
每次找最小值取反，最后统一加。
复杂度O（nk)还有优化空间

### 代码

```c
void findmin(int *A, int ASize) {
    int min = INT_MAX;
    int index = -1;
    for(int i = 0; i < ASize; i++) {
        if (A[i] < min) {
            min = A[i];
            index = i;
        }
    }
    A[index] = -A[index];
}
int largestSumAfterKNegations(int* A, int ASize, int K){
    int i = 0;
    for (i = 0; i < K; i++) {
        findmin(A, ASize);
    }
    int ret = 0;

    for (i = 0; i < ASize; i++) {
        ret += A[i];
    }
    return ret;
}
```
```
# 单调队列
int shortestSubarray(int* A, int ASize, int K){
    int *sum = (int *) malloc(sizeof(int) * (ASize + 10));
    int *q = (int *) malloc(sizeof(int) * (ASize + 10));
    int i;
    int hh = 0, tt = -1;
    int res = ASize + 1;
    
    //求前缀和
    sum[0] = 0;
    for (i = 1; i <= ASize; i++) sum[i] = sum[i - 1] + A[i - 1];

    //维护单调队列 sum[j] <= sum[i] - k
    for (i = 0; i <= ASize; i++) {
        while (hh <= tt && sum[q[tt]] >= sum[i]) --tt; 
        while (hh <= tt && sum[i] - sum[q[hh]] >= K) {
            res = res < i - q[hh] ? res : i - q[hh];
            hh++;
        }
        q[++tt] = i;
    }
    K = res == ASize + 1 ? -1 : res;
    free(sum), free(q);
    return K;
}
```

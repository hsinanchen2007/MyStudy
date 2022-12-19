### 解题思路
此处撰写解题思路

### 代码

```c
int getMaxIndex(int *data, int *index, int primesSize) {
    int min = 0;
    int i;

    for (i = 1; i < primesSize; i++) {
        if (data[min] > data[i]) {
            min = i;
        }
    }
    return min;
}

int nthSuperUglyNumber(int n, int* primes, int primesSize){
    int dp[n];
    int index[primesSize];
    int data[primesSize];
    int i;
    int min = 0;

    if (n < 1) {
        return 0;
    }
    //初始化,每次找出最小的data相应的下标i，然后data[i]=dp[++index[i]] * primes[i],之后继续找下一个最小data的下标i。
    dp[0] = 1;
    for (i = 0; i < primesSize; i++) {
        index[i] = 0;
        data[i] = dp[index[i]] * primes[i];
    }

    for (i = 1; i < n; ) {
        min = getMaxIndex(data, index, primesSize);
        //如果当前的最小值data[min]与上一个dp相同，则不赋值
        if (dp[i-1] < data[min]) {
            dp[i++] = data[min];
        }
        data[min] = dp[++index[min]] * primes[min];
    }

    return dp[n-1];
}
```
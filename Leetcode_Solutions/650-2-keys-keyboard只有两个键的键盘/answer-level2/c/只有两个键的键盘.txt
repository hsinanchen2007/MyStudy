### 解题思路
动态规划

1、如果n为一个质数，那么结果就是n,因为只能一个个粘贴。

2、如果n为一个合数，那么他的结果就是分解因式的结果之和，

比如n 为8 ，
那么dp[8] = dp[4]+dp[2]; 因为，8 = 4*2
dp[4] = dp[2]+dp[2]; 因为，4 = 2*2
由于因为2是一个质数，dp[2] = 2;
于是dp[8] = 6就是我们要求的结果。

### 代码

```c
int minSteps(int n){
    int *dp = (int *)calloc(sizeof(int), n+1);
    for (int i = 2; i <= n; i++) {
        dp[i] = i;
        for (int j = 2; j < i/2; j++) {
            if (i % j == 0) {
                dp[i] = dp[j] + dp[i/j];
                break;
            }
        }
    }
    return dp[n];
}
```
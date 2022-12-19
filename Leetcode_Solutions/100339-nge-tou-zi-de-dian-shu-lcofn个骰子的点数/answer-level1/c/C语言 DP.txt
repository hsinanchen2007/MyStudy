### 解题思路
动态规划

### 代码

```c
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
double* twoSum(int n, int* returnSize){
    double dp[12][67] = {0};
    double* ret = (double*)malloc(sizeof(double) * (5 * n + 1));
    int i = 0;
    int j = 0;
    int k = 0;
    int temp = 0;
    for (i = 1; i < 7; i++) {
        dp[1][i] = 1.0 / 6;
    }

    for (i = 2; i <= n; i++) {
        temp = 6 * i - 5;
        for (j = i - 1; j < temp; j++) {
            for (k = 1; k < 7; k++) {
                dp[i][k + j] += dp[1][k] * dp[i - 1][j];
            }
        }
    }

    temp = 5 * n + 1;
    *returnSize = temp;
    for (i = 0; i < temp; i++) {
        ret[i] = dp[n][i + n];
    }

    return ret;
}
```
先算六个筛子点数和，即出现的每一种结果，最后在计算出现该结果的概率。

```
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
double* twoSum(int n, int* returnSize){

        int dp[15][70] = {0};
     
        for (int i = 1; i <= 6; i ++) {
            dp[1][i] = 1;
        }
        for (int i = 2; i <= n; i ++) {
            for (int j = i; j <= 6*i; j ++) {
                for (int cur = 1; cur <= 6; cur ++) {
                    if (j - cur <= 0) {
                        break;
                    }
                    dp[i][j] += dp[i-1][j-cur];//第n个骰子的点数为cur，它与前n-1个筛子的点数和为某个确定的数时，共有多少种骰子点数的组合
                }
            }
        }
        int all = pow(6, n);
        int count = 0;
        double *res = (double *)malloc(sizeof(double) * (6 * n + 1));
        for (int i = n; i <= 6 * n; i ++) {//最小点数为n个骰子全为1，最大全为6
            res[i - n] = dp[n][i] * 1.0 / all;
            count++;
        }
        *returnSize = count;
        return res;
    
}
```

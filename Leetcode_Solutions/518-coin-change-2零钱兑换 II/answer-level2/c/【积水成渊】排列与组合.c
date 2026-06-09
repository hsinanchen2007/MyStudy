### 解题思路
可以参考这篇题解，对排列和组合进行区分
https://leetcode-cn.com/problems/coin-change-2/solution/ling-qian-dui-huan-iihe-pa-lou-ti-wen-ti-dao-di-yo/

### 代码

```c
#define max(a,b) ((a) > (b) ? (a) : (b))
int change(int amount, int* coins, int coinsSize){
    int i, j;
    int *dp = (int *)malloc((amount + 1) * sizeof(int));
    int amountNum = 0;

    for (i = 0; i <= amount; i++) {
        dp[i] = 0;
    }
    memset(dp, 0, strlen(dp));
    dp[0] = 1;
    //for (i = 0; i < coinsSize; i++) {
    //    dp[coins[i]] = 1;
    //}
    for (j = 0; j < coinsSize; j++) {
        for (i = 1; i < amount + 1; i++) {
            if (i < coins[j]) {
                continue;
            }
            dp[i] = dp[i] + dp[i - coins[j]];
        }
    }
    amountNum = dp[amount];
    free(dp);
    dp = NULL;
    return amountNum;
}
```
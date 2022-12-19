### 解题思路
经典动态规划问题。股票类问题，这里给出C语言的解法。

dp[i][0]表示第i天，拥有股票时的最大收益；
dp[i][1]表示第i天，无股票的最大收益。

dp[i][0] = MMAX(dp[i - 1][0], dp[i - 1][1] + prices[i]);
dp[i][1] = MMAX(dp[i - 1][1], dp[i - 2][0] - prices[i]);

![image.png](https://pic.leetcode-cn.com/2d9bb1dbb07f62908a29ef2559e2ba68c069711be0ff57c9dd54b922719fca91-image.png)


### 代码

```c
#include <stdlib.h>
#include <stdio.h>

#define MMAX(a, b)          ((a) > (b)? (a) : (b))

#define MAX_LEN     5000

int dp[MAX_LEN][2];

int maxProfit(int* prices, int pricesSize){
    if(pricesSize <= 1) {
        return 0;
    }

    for(int i = 0; i < pricesSize; i++) {
        dp[i][0] = 0;
        dp[i][1] = 0;
    }

    dp[0][0] = 0;
    dp[0][1] = -prices[0];

    dp[1][0] = MMAX(dp[0][0], dp[0][1] + prices[1]);
    dp[1][1] = MMAX(dp[0][1], -prices[1]);

    for(int i = 2; i < pricesSize; i++) {
        dp[i][0] = MMAX(dp[i - 1][0], dp[i - 1][1] + prices[i]);
        dp[i][1] = MMAX(dp[i - 1][1], dp[i - 2][0] - prices[i]);
    }

    for(int i = 0; i < pricesSize; i++) {
        printf("<%d>[0] = %d, [1] = %d\n", i, dp[i][0], dp[i][1]);
    }
    printf("\n");

    return dp[pricesSize - 1][0];
}
```
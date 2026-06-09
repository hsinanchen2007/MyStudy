### 解题思路

### 代码

```c
/* 零钱兑换 */
#define MIN(a, b) (a) < (b) ? (a) : (b)

void initArr(int **arr, int row, int col)
{
    for(int i = 0; i < row; i++) {
        if(arr[i] == NULL) continue;
        for (int j = 0; j < col; j++) {
            arr[i][j] = 0;
        }
    }

    return;
}

int coinChange(int *coins, int coinsSize, int amount)
{
    if ((coins == NULL) || (coinsSize == 0) || (amount < 0)) {
        return -1;
    }

    int left = 0;
    int dp[coinsSize][amount + 1];
    
    for (int i = 0; i < coinsSize; i++) {
        for (int j = 0; j < amount + 1; j++) {
            dp[i][j] = 0;
        }
    }
    // initArr(dp, coinsSize, amount+1);

    for (int j = 1; j <= amount; j++) {
        dp[0][j] = INT_MAX;
        if ((j - coins[0] >= 0) && (dp[0][j - coins[0]] != INT_MAX)) {
            dp[0][j] = dp[0][j - coins[0]] + 1;
        }
    }

    for (int i = 1; i < coinsSize; i++) {
        for (int j = 1; j <= amount; j++) {
            left = INT_MAX;
            if ((j - coins[i] >= 0) && (dp[i][j - coins[i]] != INT_MAX)) {
                left = dp[i][j - coins[i]] + 1;
            }

            dp[i][j] = MIN(left, dp[i - 1][j]);
        }
    }
    
    return dp[coinsSize - 1][amount] != INT_MAX ? dp[coinsSize - 1][amount] : -1;
}
```
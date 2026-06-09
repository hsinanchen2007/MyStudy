### 解题思路
递推公式：dp(i, v) += dp(i - 1, v - c[i])
优化空间复杂度：dp(v) += dp（v - c[i])

### 代码

```c

int change(int amount, int* coins, int coinsSize){
    int i;
    int j;
    int res[5001] = {0};

    if (amount == 0)
        return 1;
    if (coins == NULL || coinsSize == 0)
        return 0;

    res[0] = 1;
    for (i = 1; i <= amount; i++) {
        if ((i % coins[0]) == 0)
            res[i] = 1;
    }
    for (i = 1; i < coinsSize; i++) {
        for (j = 0; j <= amount; j++) {
            if (j >= coins[i])
                res[j] += res[j - coins[i]];
        }
    }

    return res[amount];
}
```
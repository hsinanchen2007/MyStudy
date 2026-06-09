### 解题思路
动态规划，清清爽爽

### 代码

```c
int coinChange(int* coins, int coinsSize, int amount){
    int* pCount = (int*)malloc(sizeof(int) * (amount + 1));
    int indexOfCount = 0;
    int indexOfCoins = 0;
    pCount[0] = 0; // 初始条件
    
    for (indexOfCount = 1; indexOfCount <= amount; indexOfCount++)
    {
        pCount[indexOfCount] = INT_MAX;

        for (indexOfCoins = 0; indexOfCoins <= coinsSize - 1; indexOfCoins++)
        {
            if ((indexOfCount >= coins[indexOfCoins])                                  && \
                (pCount[indexOfCount - coins[indexOfCoins]] != INT_MAX)                 )
            {
                pCount[indexOfCount] = (pCount[indexOfCount - coins[indexOfCoins]] + 1) < \
                                       (pCount[indexOfCount])                           ? \
                                       (pCount[indexOfCount - coins[indexOfCoins]] + 1) : \
                                       (pCount[indexOfCount]);
            }                      
        }

        if (INT_MAX == pCount[amount])
        {
            pCount[amount] = -1;
        }
    }

    return pCount[amount];
}
```
### 解题思路
1. 两次循环

### 代码

```c
int maxProfit(int* prices, int pricesSize){
    int i, j, profit = 0;

    for (i = 0; i < pricesSize; i++)
    {
        for (j = i + 1; j < pricesSize; j++)
        {
            if (prices[j] > prices[i] && profit < prices[j] - prices[i]) 
                profit = prices[j] - prices[i];
        }
    }
    return profit;
}
```
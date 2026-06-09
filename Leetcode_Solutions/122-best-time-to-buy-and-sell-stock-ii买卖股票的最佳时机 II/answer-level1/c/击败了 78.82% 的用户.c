### 解题思路
1. 比较前后两个值，如果后值大于前值，将差值累加就是利润

### 代码

```c
int maxProfit(int* prices, int pricesSize){
    int i, profit = 0;

    for (i = 0; i < pricesSize - 1; i++)
    {
        if (prices[i] < prices[i + 1]) profit += (prices[i + 1] - prices[i]);
    }
    return profit;
}
```
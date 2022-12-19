### 解题思路
动态规划，有点类似最长不下降子序列问题（(LIS)。

### 代码

```c
int maxProfit(int* prices, int pricesSize)
{
    int i, j, max = 0;
    for(i = 0; i < pricesSize; i++){
        for(j = 0; j < i; j++){
            if(prices[j] < prices[i] && prices[i] - prices[j] > max){
                max = prices[i] - prices[j];
            }
        }
    }
    return max;
}
```

# O(n)的做法

```
int maxProfit(int* prices, int pricesSize)
{
    int i, max = 0, minprice = 0x7fffffff;
    for(i = 0; i < pricesSize; i++){
        if(prices[i] < minprice)
            minprice = prices[i];
        else if(prices[i] - minprice > max)
            max = prices[i] - minprice;
    }
    return max;
}
```

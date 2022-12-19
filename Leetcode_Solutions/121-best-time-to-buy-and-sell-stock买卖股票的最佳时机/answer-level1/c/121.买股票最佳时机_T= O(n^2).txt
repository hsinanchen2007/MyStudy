### 解题思路
先来一个常规解法。T= O(n^2)。

### 代码

```c
int maxProfit(int* prices, int pricesSize){
    int profit = 0;
    int max = 0;
    for(int i = 0; i < pricesSize-1; i++)
    {
        max = prices[i];
        for(int j = i; j < pricesSize; j++)
        {
            if(max < prices[j])
            {
                max = prices[j];    //找最大值
            }    
        }
        if((max- prices[i])>profit) //更新最大收益
            profit = (max - prices[i]);
    }
    return profit;
}
```
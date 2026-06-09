### 解题思路
贪心算法思想：当前一步利益最大化

### 代码

```c
int maxProfit(int* prices, int pricesSize){
    int profit = 0;
    // 等价于每日进行买卖交易
    for(int i = 1; i < pricesSize; ++i){
        if(prices[i] > prices[i - 1]){
            profit += prices[i] - prices[i - 1];//今天去昨天相比。涨价即进行买卖，赚；否则，不畸形买卖。
        }
    }
    return profit;
}
```
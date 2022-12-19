### 解题思路
纯C

### 代码

```c
int maxProfit(int* prices, int pricesSize){
    int minPrice = INT_MAX;
    int maxProfit = 0;
    int day = 0;

    for (day = 0; day <= pricesSize - 1; day++)
    {
        minPrice = minPrice < prices[day] ? minPrice : prices[day];
        maxProfit = maxProfit > (prices[day] - minPrice) ? maxProfit : (prices[day] - minPrice);
    }

    return maxProfit;
}
```
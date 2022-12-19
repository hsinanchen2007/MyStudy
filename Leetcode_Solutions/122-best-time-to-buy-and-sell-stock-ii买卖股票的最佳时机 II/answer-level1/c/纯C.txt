### 解题思路
纯C

### 代码

```c
int maxProfit(int* prices, int pricesSize){
    int day = 1;
    int low = prices[0];
    int high = prices[0];
    int maxProfit = 0;

    while (day <= pricesSize - 1)
    {
        while (day <= pricesSize - 1 && prices[day] <= prices[day - 1])
        {
            day++;
        }

        low = day - 1;

        while (day <= pricesSize - 1 && prices[day - 1] <= prices[day])
        {
            day++;
        }

        high = day - 1;

        maxProfit += prices[high] - prices[low];
    }

    return maxProfit;
}
```
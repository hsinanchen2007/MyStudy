### 解题思路
直接上代码

### 代码

```c
int maxProfit(int* prices, int pricesSize){
    if (prices == NULL || pricesSize < 1) {
        return 0;
    }

    int profit = 0;

    for (int i = 0; i < pricesSize; i++) {
        for (int j = i + 1; j < pricesSize; j++) {
            if (prices[j] - prices[i] > profit) {
                profit = prices[j] - prices[i];
            }
        }
    }
    return profit;
}
```
### 解题思路
先买，后卖
j = i + 1

### 代码

```c
int maxProfit(int* prices, int pricesSize){
    int MaxProfit = 0;
    int i, j;//先买，后卖
    for(i = 0; i < pricesSize - 1; i++){
        for(j = i + 1; j < pricesSize; j++){
            int temp = prices[j] - prices[i];
            MaxProfit = temp > MaxProfit ? temp : MaxProfit;
        }
    }
    if(MaxProfit <= 0) return 0;
    return MaxProfit;
}
```
### 解题思路
自己看不出来动态规划，看答案！老弟！

### 代码

```c
int maxProfit(int* prices, int pricesSize){
    if ((NULL == prices) || (0 == pricesSize)) {
        printf("return 0");
        return 0;
    }
    int lowPrice = *prices;
    int maxProfit = 0;
    for (int i = 0; i<pricesSize; i++) {  
        if (maxProfit < (*(prices + i) - lowPrice)) {
            maxProfit = *(prices + i) - lowPrice;
        }
        if (*(prices + i) < lowPrice) {
            lowPrice = *(prices + i);
        }
    }
    return maxProfit;
}
```
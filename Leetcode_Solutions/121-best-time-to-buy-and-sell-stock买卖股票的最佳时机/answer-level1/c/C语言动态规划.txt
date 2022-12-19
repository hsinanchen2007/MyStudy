
### 代码

```c
int maxProfit(int* prices, int pricesSize){
    if((prices == NULL) || (pricesSize == 0)) {
        return 0;
    }
    int max = 0;
    for(int i = 1, j = 0; i < pricesSize; i++) {
        if(prices[j] > prices[i]) {
            j = i;
        } else if(max < (prices[i] - prices[j])){
            max = prices[i] - prices[j];
        }
    }
    return max;
}
```
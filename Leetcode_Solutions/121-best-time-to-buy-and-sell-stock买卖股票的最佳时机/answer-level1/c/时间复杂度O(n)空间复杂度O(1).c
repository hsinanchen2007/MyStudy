### 解题思路
记录最小值，遍历做差

### 代码

```c
int maxProfit(int* prices, int pricesSize){
    if(pricesSize == 0)
        return 0;
    int i = 0;
    int min = prices[0];
    int ret = 0;
    int tmp = 0;
    for(; i < pricesSize; i++){
        tmp = prices[i] - min;
        ret = tmp > ret ? tmp : ret;
        min = min < prices[i] ? min : prices[i];
    }
    return ret;
}
```
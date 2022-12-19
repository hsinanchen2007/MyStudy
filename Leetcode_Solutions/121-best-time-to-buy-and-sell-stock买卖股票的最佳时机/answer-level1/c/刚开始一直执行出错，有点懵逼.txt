### 解题思路
记得是pricesSize - 1

### 代码

```c
int maxProfit(int* prices, int pricesSize){
    int temp = 0;
    int max = 0;
    for(int i = 0; i < pricesSize - 1; ++i) {
        temp += prices[i + 1] - prices[i];
        if(temp > max) {
            max = temp;
        }
        if(temp < 0) temp = 0;
    }
    return max;
}
```
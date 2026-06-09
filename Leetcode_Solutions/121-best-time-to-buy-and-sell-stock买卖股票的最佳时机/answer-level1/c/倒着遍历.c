### 解题思路
数组倒着遍历，过程中记录销售的最大额和售价最高的值

### 代码

```c
int maxProfit(int* prices, int pricesSize){
    int max = 0;
    int pMax = 0;
    int tmp = 0;
    
    for (int i = pricesSize-1; i >= 0; i--){
       tmp = pMax - prices[i];
       pMax = pMax > prices[i] ? pMax:prices[i];
       max = tmp > max? tmp:max;
    }
    return max;
}
```
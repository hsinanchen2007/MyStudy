### 解题思路
此处撰写解题思路
由于是买卖股票问题，因此会有一个顺序的限制，即后面的元素减前面的元素。
外层循环确定每一个卖出的值，内层循环依次遍历当前元素前面的值，然后做差，大于max即为最大差值。
遍历整个数组，求出最佳。
### 代码

```c
int maxProfit(int* prices, int pricesSize){
   int max = 0;
   for (int i = pricesSize - 1; i > 0; i--)
        for (int j = 0; j < i; j++){
        if (prices[i] - prices[j] > max)
            max = prices[i] - prices[j];
        }
    return max;
}
```
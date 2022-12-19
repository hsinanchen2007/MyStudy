### 解题思路
给定一个数组，它的第 i 个元素是一支给定股票第 i 天的价格。

如果你最多只允许完成一笔交易（即买入和卖出一支股票一次），设计一个算法来计算你所能获取的最大利润。

注意：你不能在买入股票前卖出股票。

 

示例 1:

输入: [7,1,5,3,6,4]
输出: 5
解释: 在第 2 天（股票价格 = 1）的时候买入，在第 5 天（股票价格 = 6）的时候卖出，最大利润 = 6-1 = 5 。
     注意利润不能是 7-1 = 6, 因为卖出价格需要大于买入价格。



### 代码

```c
int maxProfit(int* prices, int pricesSize){
    #if 0
    int i , j, temp, max = 0;
    for (i = 0; i < pricesSize; i++){
        for (j = i + 1; j < pricesSize; j++) {
            temp = prices[j] - prices[i];
            max = max > temp ? max : temp;
        }
    }
    return max;
    #endif

    int i, maxpro = 0, min;
    
    if(pricesSize == 0)
        return 0;
    
    min = prices[0];
    for (i = 1; i < pricesSize; i++){
        maxpro = maxpro > (prices[i] - min) ? maxpro : (prices[i] - min);
        min = min < prices[i] ? min : prices[i];
    }

    return maxpro;
}
```
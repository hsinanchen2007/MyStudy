### 解题思路
执行用时 :4 ms, 在所有 C 提交中击败了98.98%的用户
内存消耗 :8 MB, 在所有 C 提交中击败了36.86%的用户

首先要判断最低买入，然后再去每次计算
### 代码

```c


int maxProfit(int* prices, int pricesSize){
    if (pricesSize == 0)
        return 0;
    int max = 0;
    int min = prices[0];
    for(int i = 1;i < pricesSize;i++){
        if(prices[i] < min){
            min = prices[i];
        }
        if(prices[i] - min > max){
            max = prices[i] -min;
        }
    }
    return max;
}


```
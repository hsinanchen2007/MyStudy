### 解题思路
1.暴力思想很简单想到，取两个数做差，最后找出来大的，那么我们对暴力法进行优化
2.例如列表[1,2,3,4],假设我们确定在第四天卖股票，那么我们要找到啥时候买最好，显然第一天买最好，即找到之前的最小值
3.所以我们可以做一个列表把每个点之前的最小值储存起来[1,2,3,4] -> [1,1,1,1],再用一个全局最优变量去比较即可

### 代码

```c
int maxProfit(int* prices, int pricesSize){
    if (pricesSize<=1)
        return 0;
    int *min=malloc(sizeof(int)*pricesSize),best=0;
    min[0] = prices[0];
    for (int i=1;i<pricesSize;i++){
        if (min[i-1]>prices[i])
            min[i] = prices[i];
        else
            min[i] = min[i-1];
        if (best<(prices[i]-min[i-1]))
            best = prices[i] - min[i-1];
    }
    return best;
}
```
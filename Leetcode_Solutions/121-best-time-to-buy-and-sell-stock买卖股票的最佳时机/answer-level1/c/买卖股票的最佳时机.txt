### 解题思路
我觉得这道题有点像动态规划那种，每一天都选择抛出或者购进。
在这里，我们假设每一天抛出的时候，他都是在当天的前面的最低价格购入的，这样他就能获得在当前价格抛出的最佳方案。
我们使用一个循环，使用min记录最低价格，使用maxPro记录到目前来看的最好受益，如果当前元素大于最低值，我们进行售出，如果小于当天，我们进行购入，min更新。
如果感觉不是很理解的话，可以像是动态规划那样使用一个数组把每一天的状态记录下来，然后再修正成这种常量级别的空间。
### 代码

```c
#define MAX(a,b) (a>b?a:b)
int maxProfit(int* prices, int pricesSize){
    if(pricesSize<=1) return 0;
    int min = prices[0];
    int maxPro = 0;
    for(int i=1;i<pricesSize;i++){
        if(prices[i]>min) maxPro=MAX(maxPro,prices[i]-min);
        else min = prices[i]; 
    }
    return maxPro;
}
```
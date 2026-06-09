### 解题思路
* 定状态 dp[i]定为以第i天卖出股票的最大收益
* 转移方程  dp[i]=max((prices[i]-min_price),dp[i-1]);//其中min_price是前i-1天的最小价格
* 自上而下分析，自下而上求解
### 代码

```c
#define max(a,b) a>b?a:b
int maxProfit(int* prices, int pricesSize){
     if(prices==NULL||pricesSize==0)
        return 0;
    int dp[pricesSize];
    for(int i=0;i<pricesSize;i++)
       dp[i]=0;
    int min_price=prices[0];
    int max_dp=0;
    for(int i=1;i<pricesSize;i++)
    {
        dp[i]=max((prices[i]-min_price),dp[i-1]);
        if(dp[i]>max_dp)
           max_dp=dp[i];

        if(prices[i]<min_price)
            min_price=prices[i];   //更新当前最小价格
    }
    return max_dp;
}
```
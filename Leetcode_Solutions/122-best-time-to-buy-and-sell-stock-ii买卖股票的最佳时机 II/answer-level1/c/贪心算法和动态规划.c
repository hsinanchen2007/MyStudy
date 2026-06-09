### 解题思路
C语言实现贪心算法和动态规划

### 代码

/////////////////////////////贪心算法///////////////////////
/*int maxProfit(int* prices, int pricesSize)
{
    int i=0;
    int profit = 0;
    for(i = 0; i < pricesSize - 1; i++)
    {
        if( prices[i+1]-prices[i] > 0)
        {
            profit =profit + prices[i+1] - prices[i];
        }
    }
    return profit;
}*/
//动态规划算法
#define MAX(a,b)   (a)>(b)?a:b
#define INt_MAX 65535
int maxProfit(int* prices, int pricesSize)
{
        if(pricesSize == 0)return 0;
        int dp[INt_MAX][2];
        dp[0][0] = 0;                 //cash
        dp[0][1] = -prices[0];        //stack

        for (int i = 1; i < pricesSize; i++) 
        {
            dp[i][0] = MAX(dp[i - 1][0], dp[i - 1][1] + prices[i]);
            dp[i][1] = MAX(dp[i - 1][1], dp[i - 1][0] - prices[i]);
        }
        return dp[pricesSize - 1][0];
}

```
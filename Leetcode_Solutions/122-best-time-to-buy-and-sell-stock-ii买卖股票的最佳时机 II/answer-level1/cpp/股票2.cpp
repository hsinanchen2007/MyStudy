### 解题思路
不限制交易次数，和股票1不太一样
利用二维动态规划dp[i][j]

1:转移方程
i表示i之前的最大利润，这个和股票1是一样的
j表示到底是买入还是卖出
0表示持有现金，要买入股票，也可以不买
1表示持有股票，可以卖出，也可以不卖

dp[i][0] = max(dp[i-1][0], dp[i-1][1] + prices[i]);
dp[i][1] = max(dp[i-1][1], dp[i-1][0] - prices[i]);


2:初始化
dp[0][0] = 0  这个没有什么问题
dp[0][1] = - prices[0]   表示一开始要买入股票，那收益肯定是负数了

### 代码

```cpp
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        if(n == 0) return 0;
        vector<vector<int>> dp;
        vector<int> d(2);
        for(int i=0;i<n;i++){
            dp.push_back(d);
        }
        //初始化
        //0表示持有现金
        //1表示持有股票
        dp[0][0]=0;
        dp[0][1]=-prices[0];

        for(int i=1;i<n;i++){
            dp[i][0] = max(dp[i-1][0], dp[i-1][1] + prices[i]);
            dp[i][1] = max(dp[i-1][1], dp[i-1][0] - prices[i]);
        }
        return dp[n-1][0];
    }
};
```
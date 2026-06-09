### 解题思路
对k进行分化
如果k>n/2， 则等价于无限次交易，则是股票2的情况
否则进行三维动态规划

### 代码

```cpp
class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        int n = prices.size();
        if(n==0) return 0;

        //注意这里的次序，如果放在新建dp的后面，则会超过内存啊啊啊
        if(k >= n/2){
            return greedy(prices);
        }

        int dp[n][k+1][2];
        memset(dp,0,sizeof(dp));

        //初始化
        for(int j=1;j<=k;j++){
            dp[0][j][1]=-prices[0];
        }
        for(int i=1;i<n;i++){
            for(int j=1;j<=k;j++){
                dp[i][j][0] = max(dp[i-1][j][0], dp[i-1][j][1]+prices[i]);
                dp[i][j][1] = max(dp[i-1][j][1], dp[i-1][j-1][0]-prices[i]);
            }
        }
        return dp[n-1][k][0];
}
        
    
    int greedy(vector<int>& p) {
        int n = p.size();
        int dp[n][2];
        memset(dp,0,sizeof(dp));

        dp[0][0]=0;
        dp[0][1]=-p[0];
        for(int i=1;i<n;i++){
            dp[i][0] = max(dp[i-1][0], dp[i-1][1] + p[i]);
            dp[i][1] = max(dp[i-1][1], dp[i-1][0] - p[i]);
        }
        return dp[n-1][0];
    }
    
};
```
### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        int n = prices.size();
        if(n==0) return 0;

        //注意这里的次序，如果放在新建dp的后面，则会超过内存啊啊啊
        if(k >= n/2){
            return maxProfitUnlimit(prices);
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
        
    int maxProfitUnlimit(vector<int>& prices) {
        int res = 0;
        int n = prices.size();
        for(int i=0; i<n-1; i++)
        {
            if(prices[i+1] > prices[i])
                res += (prices[i+1] - prices[i]);
        }
        return res;
    }
    
};
```
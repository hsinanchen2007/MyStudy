### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if(prices.empty()) return 0;
        int s1=-prices[0],s2=INT_MIN,s3=INT_MIN,s4=INT_MIN;
        int n=prices.size();
        int dp[n][3][2]={0};  
        for(int k=2;k>=1;k--){
            dp[0][k][0]=0;
            dp[0][k][1]=-prices[0];
        }
        for(int i=1;i<prices.size();++i) {
            
            for(int k=2;k>=1;k--)  {
                dp[i][k][0] = max(dp[i-1][k][0], dp[i-1][k][1] + prices[i]);
                dp[i][k][1] = max(dp[i-1][k][1], dp[i-1][k-1][0] - prices[i]);
            }          
            
        }
        return dp[n-1][2][0];

    }
};
```
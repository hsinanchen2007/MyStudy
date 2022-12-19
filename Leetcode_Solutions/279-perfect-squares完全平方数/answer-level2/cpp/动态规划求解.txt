动态规划求解，因为一个元素可以由多个对应的子状态组成，类似于之前一次比较的状态转移方程，这儿转化为了多次比较，状态转移方程如下：
dp[i+j*j]=min(dp[i+j*j],dp[i]+1);
```
class Solution {
public:
    int numSquares(int n) {
        vector<int> dp(n+1,INT_MAX);
        dp[0]=0;
        for(int i=0;i<=n;i++){
            for(int j=1;i+j*j<=n;j++){
                dp[i+j*j]=min(dp[i+j*j],dp[i]+1);
            }
        }
        return dp.back();
    }
};
```
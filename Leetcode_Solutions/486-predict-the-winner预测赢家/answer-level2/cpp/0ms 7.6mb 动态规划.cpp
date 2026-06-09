### 解题思路

双百动态规划

### 代码

```cpp
class Solution {
public:
    int dp[21][21][2];
    bool PredictTheWinner(vector<int>& nums) {
        if(nums.empty())return false;
        int n=nums.size();
        for(int i=0;i<n;i++){
            dp[i][i+1][0]=nums[i];
            dp[i][i+1][1]=0;
        }
        for(int i=2;i<=n;i++){
            for(int j=0;j<=n-i;j++){
                int f1=nums[j]+dp[j+1][j+i][1],c1=dp[j+1][j+i][0];
                int f2=nums[j+i-1]+dp[j][j+i-1][1],c2=dp[j][j+i-1][0];
                if(f1-c1>f2-c2)dp[j][j+i][0]=f1,dp[j][j+i][1]=c1;
                else dp[j][j+i][0]=f2,dp[j][j+i][1]=c2;
            }
        }
        return dp[0][n][0]>=dp[0][n][1];
    }
};
```
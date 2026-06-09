### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
    int maxValue(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        vector<vector<int>> dp(m,vector(n,0));
        dp[0][0]=grid[0][0];
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(j>0){
                    dp[i][j]=max(dp[i][j],dp[i][j-1]+grid[i][j]);
                }
                if(i>0){
                    dp[i][j]=max(dp[i][j],dp[i-1][j]+grid[i][j]);
                }
            }
        }
        return dp[m-1][n-1];
    }
};
```
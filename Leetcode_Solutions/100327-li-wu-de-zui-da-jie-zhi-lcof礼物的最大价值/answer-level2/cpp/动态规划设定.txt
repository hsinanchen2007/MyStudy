### 解题思路
设定好初始值就行了
dp[i][j]=max(dp[i-1][j],dp[i][j-1])+grid[i][j];

### 代码

```cpp
class Solution {
public://dp就是设定初始值 然后迭代
    int maxValue(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        vector<vector<int>> dp(m,vector<int>(n));
    dp[0][0]=grid[0][0];
    for(int j=1;j<n;j++)
        dp[0][j]=grid[0][j]+dp[0][j-1];
    for(int i=1;i<m;i++)
        dp[i][0]=grid[i][0]+dp[i-1][0];    

        for(int i=1;i<m;i++)
        for(int j=1;j<n;j++)
        {   
            
            dp[i][j]=max(dp[i-1][j],dp[i][j-1])+grid[i][j];
        }
return dp[m-1][n-1];
    }
};
```
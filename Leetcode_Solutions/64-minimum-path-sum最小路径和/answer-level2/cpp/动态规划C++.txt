### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
    int min(int a,int b){return a<b?a:b;}
    int minPathSum(vector<vector<int>>& grid) {
     vector<vector<int>> dp(grid.size(),vector<int>(grid[0].size()));
     
     for(int i=0;i<dp.size();i++){
         for(int j=0;j<dp[0].size();j++){
             if(i==0&&j==0){dp[i][j]=grid[0][0];}
             else if(i==0&&j>=1){dp[i][j]=dp[i][j-1]+grid[i][j];}
             else if(i>=1&&j==0){dp[i][j]=dp[i-1][j]+grid[i][j];}
             else if(i>=1&&j>=1){dp[i][j]=min(dp[i-1][j]+grid[i][j],dp[i][j-1]+grid[i][j]);}
         }
     }
     return dp[dp.size()-1][dp[0].size()-1];

    }
};
```
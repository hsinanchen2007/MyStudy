### 解题思路
![image.png](https://pic.leetcode-cn.com/d8c932d6af53e192324fa0c3df9a9f9b60901e7debb4f4f8aeb6570e500bc6f1-image.png)


### 代码

```cpp
class Solution {
public:
    int maxValue(vector<vector<int>>& grid) {
        vector<vector<int>>dp;
        int w,h;
        h=grid.size();
        w=grid[0].size();
        for(int i=0;i<h;i++)
        {
            dp.push_back(vector<int>());
            for(int j=0;j<w;j++)
            if(i==0)
            {
                if(j==0)
                   dp[i].push_back(grid[0][0]);
                else dp[i].push_back(grid[0][j]+dp[i][j-1]);
            }
            else 
            {
                if(j==0)
                  dp[i].push_back(grid[i][j]+dp[i-1][j]);
                else dp[i].push_back(grid[i][j]+max(dp[i-1][j],dp[i][j-1]));
            }
        }
        return dp[h-1][w-1];
    }
};
```
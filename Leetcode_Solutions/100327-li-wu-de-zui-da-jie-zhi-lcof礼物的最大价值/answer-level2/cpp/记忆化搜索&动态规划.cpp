### 记忆化搜索

### 代码

```cpp
class Solution {
public:
    int m[205][205];
    int maxValue(vector<vector<int>>& grid) {
        return dfs(grid.size()-1,grid[0].size()-1,grid);
    }
    int dfs(int x,int y,vector<vector<int>>& gd){
        int maxl=0;
        if(m[x][y]!=0)return m[x][y];
        if(x==0&&y==0)return gd[0][0];
        if(x>0)maxl=max(maxl,dfs(x-1,y,gd));
        if(y>0)maxl=max(maxl,dfs(x,y-1,gd));
        m[x][y]=maxl+gd[x][y];
        return maxl+gd[x][y];
    }
};
```
### 动态规划
```
class Solution {
public:
    int maxValue(vector<vector<int>>& grid) {
        int x=grid.size(),y=grid[0].size();
        int dp[205][205];
        dp[0][0]=grid[0][0];
        for(int i=1;i<y;i++)
            dp[0][i]=dp[0][i-1]+grid[0][i];
        for(int i=1;i<x;i++)
            dp[i][0]=dp[i-1][0]+grid[i][0];
        for(int i=1;i<x;i++)
            for(int j=1;j<y;j++)
                dp[i][j]=max(dp[i-1][j],dp[i][j-1])+grid[i][j];
       return dp[x-1][y-1];
    }
};
```
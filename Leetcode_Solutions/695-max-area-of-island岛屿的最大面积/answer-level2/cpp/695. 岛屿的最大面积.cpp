### 解题思路
经典dfs，算是一题搜索裸题了

### 代码

```cpp
class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) 
    {
        int ans=0;
        for(int i=0;i<grid.size();i++)
        {
            for(int j=0;j<grid[i].size();j++)
            {
                if(grid[i][j]==1)
                {
                  ans=max(ans,dfs(i,j,grid));
                }
            }
        }
        return ans;
    }
    inline int dfs(int x,int y,vector<vector<int>>& grid)
    {
        if(x>grid.size()-1||y>grid[0].size()-1||x<0||y<0)return 0;
        int dx[4]={-1,1,0,0},dy[4]={0,0,1,-1};
        int ans=0;
        if(grid[x][y]==1)ans++,grid[x][y]=0;
        for(int i=0;i<4;i++)
        {
            int x1=dx[i]+x,y1=dy[i]+y;
            if(x1>grid.size()-1||y1>grid[0].size()-1||x1<0||y1<0)continue;
            if(grid[x1][y1]==1)
            {
                ans+=dfs(x1,y1,grid);
                
            }
        }
        return ans;
    }
};
```
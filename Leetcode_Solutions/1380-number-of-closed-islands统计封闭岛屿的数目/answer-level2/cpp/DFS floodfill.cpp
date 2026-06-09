### 解题思路
先从4条边出发，把0所能到达的连通块全部改为-1，然后遍历grid，仍未为0的是陆地，通过dfs，把被水域包围的陆地连通块改为-1，并++。

### 代码

```cpp
class Solution {
public:
    int n,m;
    int dir[4][2]={{0,-1},{0,1},{1,0},{-1,0}};
    bool isInArea(int x, int y)
    {
        if(x < 0 || x >= n || y < 0 || y >= m)
            return false;
        else
            return true;
    }
    void dfs(vector<vector<int>>& grid, int x, int y)
    {
        if(grid[x][y] != 0)
            return;
        if(grid[x][y] == 0)
            grid[x][y]=-1;
        for(int i =0;i<4;i++)
        {
            int nx=x+dir[i][0];
            int ny=y+dir[i][1];
            if(isInArea(nx,ny)&&grid[nx][ny]==0)
                dfs(grid,nx,ny);
        }
    }
    int closedIsland(vector<vector<int>>& grid) {
        if(!grid.size() || !grid[0].size())
            return 0;
        n = grid.size();
        m = grid[0].size();
        //从四条边出发，把所有能到达的陆地染成-1           
        for(int i = 0; i<n;i++)
        {
            for(int j = 0;j<m;j++)
            {
                if((i==0||i==n-1||j==0||j==m-1)&&grid[i][j]==0)
                {                    
                    dfs(grid,i,j);
                }
            }
        }
        int res = 0;
        for(int i = 0; i<n;i++)
        {
            for(int j = 0;j<m;j++)
            {
                if(grid[i][j]==0)
                {
                    res+=1;
                    dfs(grid,i,j);
                }
            }
        }
        return res;

    }
};
```
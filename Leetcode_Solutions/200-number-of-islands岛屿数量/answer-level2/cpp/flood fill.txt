### 解题思路
此处撰写解题思路

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
    void dfs(vector<vector<char>>& grid,int x,int y,vector<vector<bool>> &vis)
    {
        vis[x][y]=true;
        for(int i = 0; i<4;i++)
        {
            int nx = x + dir[i][0];
            int ny = y + dir[i][1];
            if(isInArea(nx,ny)&&!vis[nx][ny]&&grid[nx][ny]=='1')
            {
                dfs(grid, nx, ny, vis);
            }
        }

    }
    int numIslands(vector<vector<char>>& grid) {
        if(!grid.size() || !grid[0].size())
            return 0;
        n = grid.size();
        m = grid[0].size();
        int res = 0;
        vector<vector<bool>> vis(n,vector<bool>(m,false));
        for(int i =0;i<n;i++)
            for(int j = 0;j<m;j++)
            {
                if(grid[i][j]=='1'&&!vis[i][j])
                {
                    res++;
                    dfs(grid,i,j,vis);
                }
            }
        return res;

    }
};
```
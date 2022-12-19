### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        //深度优先搜索
        int m=grid.size();
        if(m==0) return 0;
        int n=grid[0].size();
        if(n==0) return 0;

        int max_area=0;
        for(int i=0; i<m; ++i)
        {
            for(int j=0; j<n; ++j)
            {
                if(grid[i][j]==1)
                {
                    int area=0;
                    dfs(i,j,grid,area);
                    max_area=max(max_area,area);
                }
            }
        }

        return max_area;
    }

    void dfs(int row, int col, vector<vector<int>>& grid, int& area)
    {
        area+=1;
        grid[row][col]=0;
        int m=grid.size(),  n=grid[0].size();
        
        if(row-1>=0 && grid[row-1][col]==1) dfs(row-1,col,grid,area);
        if(col+1<n && grid[row][col+1]==1) dfs(row,col+1,grid,area);
        if(row+1<m && grid[row+1][col]==1) dfs(row+1,col,grid,area);
        if(col-1>=0 && grid[row][col-1]==1) dfs(row,col-1,grid,area);
        return;
    }
};
```
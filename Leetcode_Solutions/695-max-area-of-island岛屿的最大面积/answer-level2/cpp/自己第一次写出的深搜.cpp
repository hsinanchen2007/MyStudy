### 解题思路


### 代码

```cpp
class Solution {
public:
    int max_island = 0;
    void dfs(int x,int y, int &count,vector<vector<int>> & grid)
    {  if(x<0||x>=grid.size()||y<0||y>=grid[0].size()||grid[x][y]==0) return;
       
       grid[x][y]=0;
       count++;
       dfs(x-1,y,count,grid);
       dfs(x+1,y,count,grid);
       dfs(x,y-1,count,grid);
       dfs(x,y+1,count,grid);

    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
       int n = grid.size();
       int m = grid[0].size();
       for(int i = 0;i<n;++i)
         for(int j = 0;j<m;++j)
         {
            if(grid[i][j]==1)
            {   
                int count = 0;
                dfs(i,j,count,grid);
                max_island = max(max_island,count);
            }
         }
         return max_island;

    }
    
};
```
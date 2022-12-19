### 解题思路
深度优先搜索

### 代码

```cpp
class Solution {
    int m;
    int n;
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        m=grid.size();
        n=grid[0].size();
        int maxArea=0;
        for(int i=0;i<m;++i)
        {
            for(int j=0;j<n;++j)
            {
                if(grid[i][j]==1)
                {
                    maxArea=max(maxArea,DFS(grid,i,j));
                }
            }
        }
        return maxArea;
    }
    int DFS(vector<vector<int>> & grid,int i,int j)
    {
        grid[i][j]=-1;
        int area=1;
        if(isOK(i,j+1)&&grid[i][j+1]==1)
        area+=DFS(grid,i,j+1);
        if(isOK(i,j-1)&&grid[i][j-1]==1)
        area+=DFS(grid,i,j-1);
        if(isOK(i-1,j)&&grid[i-1][j]==1)
        area+=DFS(grid,i-1,j);
        if(isOK(i+1,j)&&grid[i+1][j]==1)
        area+=DFS(grid,i+1,j);
        return area;
    }
    bool isOK(int i,int j)
    {
        if(i>=0&&i<m&&j>=0&&j<n)
        return true;
        return false;
    }
};
```
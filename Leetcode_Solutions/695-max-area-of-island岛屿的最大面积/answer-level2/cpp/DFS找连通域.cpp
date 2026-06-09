### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
    int result=0;
    vector<vector<int>> adj;
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        if(grid.size()<=0 || grid[0].size()<=0) return 0;
        adj=grid;
        int rows=grid.size();int cols=grid[0].size();
        for(int i=0;i<rows;i++)
            for(int j=0;j<cols;j++)
                if(adj[i][j]==1)
                {
                    int area=1;
                    dfs(i,j,area,rows,cols);
                }
                  
        return result;
            
    }
    void dfs(int x,int y,int &area,int rows,int cols)
    {
        result=max(result,area);
        adj[x][y]=0;
        if(x+1<rows && adj[x+1][y]==1) {area++;dfs(x+1,y,area,rows,cols);}
        if(x-1>=0 && adj[x-1][y]==1) {area++;dfs(x-1,y,area,rows,cols);}
        if(y+1<cols && adj[x][y+1]==1) {area++;dfs(x,y+1,area,rows,cols);}
        if(y-1>=0 && adj[x][y-1]==1) {area++;dfs(x,y-1,area,rows,cols);}
    }
};
```
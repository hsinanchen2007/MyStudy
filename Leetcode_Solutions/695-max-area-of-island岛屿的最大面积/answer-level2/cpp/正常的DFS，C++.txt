### 解题思路
DFS

### 代码

```cpp
class Solution {
public:
    int dirs[4][2] = {{0,1},{0,-1},{1,0},{-1,0}};
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int m=grid.size();
        if(m==0) return 0;
        int n=grid[0].size();
        int res=0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==1){
                    res = max(res, dfs(grid,i,j));
                }
            }
        }
        return res;
    }
    int dfs(vector<vector<int>>& grid, int i, int j){
        int count=1;
        grid[i][j]=-1;
        for(int k = 0; k < 4; k++){
            int x = i + dirs[k][0];
            int y = j + dirs[k][1];
            if(x >= 0 && x < grid.size() && y >= 0 && y < grid[0].size() && grid[x][y]==1){
                count+=dfs(grid,x,y);
            }
        }
        return count;
    }
};
```
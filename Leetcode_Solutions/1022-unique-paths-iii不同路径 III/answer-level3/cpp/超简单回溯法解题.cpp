### 解题思路
主函数先找到起点，再通过回溯法找到每个点都经过的路径

### 代码

```cpp
class Solution {
    public:
    int count = 0;
    int direction[4][2]{{1,0},{-1,0},{0,1},{0,-1}};
    void dfs(vector<vector<int>>& grid, int x, int y, int n){
        if(x<0 || x>=grid.size() || y<0 || y>=grid[x].size() || grid[x][y] == -1) return;
        if(grid[x][y]==2){
            if(n == 0){
                ++count;
            }
            return;
        }
        grid[x][y] = -1;
        for(int i = 0;i < 4;++i){
            int nx = x + direction[i][0];
            int ny = y + direction[i][1];
            dfs(grid,nx,ny,n-1);
        }
        grid[x][y] = 0;
        return;
    }
    int uniquePathsIII(vector<vector<int>>& grid) {
        int step = 1, x = 0, y = 0;
        for(int i=0; i<grid.size(); ++i)
            for(int j=0; j<grid[i].size(); ++j)
                if(grid[i][j]==1) x=i, y=j;
                else if(grid[i][j]==0) ++step;
        dfs(grid,x,y,step);
        return count;
    }
};

```
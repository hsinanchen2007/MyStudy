本题就是一个简单的深搜问题，唯一的障碍只有每个“块”之间是否是连通的。
这里设置dir数组表示各种管道up，right，down，left四个方向是否连通，是则为1，否则为0。
能否到达下一块，除了本块的管道能够连通之外，还需要下一块的管道能够接起来，再就是vis和范围等常规条件。
本题代码是还可以优化的，但是为了清晰直观，所以每一个方向都是分别写的代码。

```C++ []
class Solution {
private:
    bool flag = false;
    int vis[310][310] = {0};
    int dir[7][4] = {{0}, {0, 1, 0, 1}, {1, 0, 1, 0}, {0, 0, 1, 1}, {0, 1, 1, 0}, {1, 0, 0, 1}, {1, 1, 0, 0}};
public:
    void dfs(vector<vector<int>> &grid, int x, int y, int m, int n){
        vis[x][y] = 1;
        if(x == m - 1 && y == n - 1){
            flag = true;
            return;
        }
        //up
        if(dir[grid[x][y]][0] && x - 1 >= 0 && !vis[x - 1][y] && dir[grid[x - 1][y]][2]) dfs(grid, x - 1, y, m, n);
        //right
        if(dir[grid[x][y]][1] && y + 1 < n && !vis[x][y + 1] && dir[grid[x][y + 1]][3]) dfs(grid, x, y + 1, m, n);
        //down
        if(dir[grid[x][y]][2] && x + 1 < m && !vis[x + 1][y] && dir[grid[x + 1][y]][0]) dfs(grid, x + 1, y, m, n);
        //left
        if(dir[grid[x][y]][3] && y - 1 >= 0 && !vis[x][y - 1] && dir[grid[x][y - 1]][1]) dfs(grid, x, y - 1, m, n);
    }
    
    bool hasValidPath(vector<vector<int>>& grid) {
        const int m = grid.size();
        const int n = grid[0].size();
        dfs(grid, 0, 0, m, n);
        return flag;
    }
};
```



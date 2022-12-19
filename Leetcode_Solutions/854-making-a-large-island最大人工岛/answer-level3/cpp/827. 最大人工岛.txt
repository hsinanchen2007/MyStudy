
纯暴力DFS，枚举每个0，然后计算翻转它之后的面积，取最大值即可。

```c++ []
class Solution {
public:
    int largestIsland(vector<vector<int>>& grid) {
        bx = grid.size();
        by = grid[0].size();
        int ans = 0;
        int ones = 0;
        swap(maze, grid);
        for(int i = 0;i < bx;++i){
            for(int j = 0;j < by;++j){
                int area = 1;
                if(maze[i][j] == 0){
                    vector<vector<bool>> vis(bx, vector<bool>(by, false));
                    dfs(i, j, area, vis);
                }else ones++;
                if(ans < area) ans = area;
            }
        }
        return ones == bx * by ? ones : ans;
    }
private:
    int dir[4][2] = {{0,1},{-1,0},{0,-1},{1,0}};
    int bx, by;
    vector<vector<int>> maze;
    
    void dfs(int x, int y, int& area, vector<vector<bool>>& vis){
        for(int i = 0;i < 4;++i){
            int nx = x + dir[i][0];
            int ny = y + dir[i][1];
            if(nx < 0 || nx >= bx || ny < 0 || ny >= by || vis[nx][ny] || !maze[nx][ny])
                continue;
            area++;
            vis[nx][ny] = true;
            dfs(nx, ny, area, vis);
        }
        return ;
    }
};
```
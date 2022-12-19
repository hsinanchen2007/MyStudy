

```c++
class Solution {
public:
    bool hasValidPath(vector<vector<int>>& grid) {
	    int m = grid.size(), n = grid[0].size();
	    vector<vector<int>>visited(m, vector<int>(n, 0));
        //起点位置两个方向都要检查
	    return dfs(grid,visited, 0, 0, true) || dfs(grid,visited, 0, 0, false);
    }
    //根据街道的起点和终点坐标可以唯一确定一种街道{from.x,from.y,to.x,to.y}，此外还需要一个bool变量记录方向
    //dir true表示向着to走，false说明向着from走
    //6种街道
    vector<vector<int>>signs = { {0,-1,0,1},{-1,0,1,0},{0,-1,1,0},{1,0,0,1},{0,-1,-1,0},{-1,0,0,1} };
    bool dfs(vector<vector<int>>& grid, vector<vector<int>>& visited, int x, int y,bool dir) {
        visited[x][y] = 1;
        if (x == grid.size() - 1 && y == grid[0].size() - 1)return true;
        int sign = grid[x][y] - 1;
        //根据方向计算下一个位置
        int nx = x + signs[sign][dir * 2], ny = y + signs[sign][dir * 2 + 1]; 
        //下一个位置失效
        if (nx < 0 || nx >= grid.size() || ny < 0 || ny >= grid[0].size()||visited[nx][ny])
            return false;
        //下一个位置的地形
        int nsign = grid[nx][ny] - 1;
        //下一个位置from方向与前一个位置离开的方向匹配
        if (signs[sign][dir * 2] + signs[nsign][0]==0 && signs[sign][dir * 2 + 1] + signs[nsign][1]==0)
            return dfs(grid,visited, nx, ny, true);
        //下一个位置to方向与前一个位置离开的方向匹配
        if (signs[sign][dir * 2] + signs[nsign][2]==0 && signs[sign][dir * 2 + 1] + signs[nsign][3]==0)
            return dfs(grid,visited, nx, ny, false);
        return false;
    }
};
```


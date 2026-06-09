// ```
class Solution {
public:
    
    //1，2，3，4 ，顺时针对应四个方向，1->👆，2->👉，3->👇，4->👈
    int road[7][2] = { {},{1,3},{0,2},{2,3},{1,2},{0,3},{0,1} };//每条路具有的方向
    bool DFS(vector<vector<int>>& grid, int x, int y, int m, int n) {
        if (x == m - 1 && y == n - 1) return true;
        int v = grid[x][y];//road标号
        if (x > 0 && (road[v][0] == 0 || road[v][1] == 0)) {
            int w = grid[x - 1][y];//下一个节点
            if (w != -1 && (road[w][0] == 2 || road[w][1] == 2)) {
                grid[x][y] = -1;//标记已走过的节点
                return DFS(grid, x - 1, y, m, n);
            }
        }
        if (y < n - 1 && (road[v][0] == 1 || road[v][1] == 1)) {
            int w = grid[x][y + 1];
            if (w != -1&&(road[w][0] == 3 || road[w][1] == 3)) {
                grid[x][y] = -1;
                return DFS(grid, x, y + 1, m, n);
            }
        }
        if (x < m - 1 && (road[v][0] == 2 || road[v][1] == 2)) {
            int w = grid[x + 1][y];
            if (w != -1 && (road[w][0] == 0 || road[w][1] == 0)) {
                grid[x][y] = -1;
                return DFS(grid, x + 1, y, m, n);
            }
        }
        if (y > 0 && (road[v][0] == 3 || road[v][1] == 3)) {
            int w = grid[x][y - 1];
            if (w != -1 && (road[w][0] == 1 || road[w][1] == 1)) {
                grid[x][y] = -1;
                return DFS(grid, x, y - 1, m, n);
            }
        }
        return false;
    }
    bool hasValidPath(vector<vector<int>>& grid) {
        if(grid[0][0] == 4){//第一个节点为4时有两个方向
            int flag = false;
            grid[0][0] = -1;
            if(grid.size()>1){
                flag = flag || DFS(grid,1,0,grid.size(), grid[0].size());
            }
            if(grid[0].size()>1){
                flag = flag || DFS(grid,0,1,grid.size(), grid[0].size());
            }
            return flag;
        }
        else return DFS(grid, 0, 0, grid.size(), grid[0].size());
    }
};
// ```

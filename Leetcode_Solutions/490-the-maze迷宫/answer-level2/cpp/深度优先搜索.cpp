### 解题思路

Visited数组只需要标记起始点和撞墙/障碍物的反弹点，因为在其他位置小球根本不会停下来，所以不存在重复访问的问题。

### 代码

```cpp
class Solution {
private:
    int dir[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
    int m;
    int n;
public:
    bool hasPath(vector<vector<int>>& maze, vector<int>& start, vector<int>& destination) {
        m = maze.size();
        if(m == 0)
            return false;
        n = maze[0].size();
        vector<vector<bool>> visited(m, vector<bool>(n));
        
        return dfs(maze, visited, start, destination);
    }
    
    bool dfs(vector<vector<int>>& maze, vector<vector<bool>>& visited,
             vector<int>& cur, vector<int>& dest) {
        int x = cur[0];
        int y = cur[1];
        if(visited[x][y])
            return false;
        visited[x][y] = true;
        if(x == dest[0] && y == dest[1])
            return true;
        
        for(int i=0; i<4; i++) {
            int nx = x + dir[i][0];
            int ny = y + dir[i][1];
            
            while(true) {             
                if(nx < 0 || nx == m || ny < 0 || ny == n || maze[nx][ny] == 1) {
                    nx -= dir[i][0];
                    ny -= dir[i][1];
                    //cout << nx << "," << ny << endl;
                    break;
                }
                nx += dir[i][0];
                ny += dir[i][1];
            }
            vector<int> newPos = {nx, ny};
            bool res = dfs(maze, visited, newPos, dest);
            if(res)
                return true;
        }
        return false;
    }
};
```
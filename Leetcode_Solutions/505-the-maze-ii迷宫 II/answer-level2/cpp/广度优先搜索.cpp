### 解题思路

1. 每个反弹点有可能被两个相反的方向搜索到两次，最先到目标位置的那条路不一定就拥有最短距离，因此Visited并非常规BFS的记录是否访问过，而是上次访问过的最短路径长度，如果下一次有更短的路径，就更新这一长度。
2. 在BFS队列为空时才返回最小路径长度，否则不一定为最优解。

### 代码

```cpp
class Solution {
private:
    int dir[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
    vector<vector<int>> visited;
    int m;
    int n;
public:
    int shortestDistance(vector<vector<int>>& maze, vector<int>& start, vector<int>& destination) {
        m = maze.size();
        if(m == 0)
            return 0;
        n = maze[0].size();
        visited.assign(m, vector<int>(n, INT_MAX));
        return bfs(maze, start, destination);
    }
    
    int bfs(vector<vector<int>>& maze, vector<int>& start, vector<int>& dest) {
        queue<pair<int, int>> Q;
        Q.emplace(start[0], start[1]);
        
        int L = 0;
        visited[start[0]][start[1]] = 0;
        while(!Q.empty()) {
            auto pair = Q.front();
            Q.pop();
            int x = pair.first;
            int y = pair.second;
            // if(x == dest[0] && y == dest[1])
            //    return visited[x][y];
            for(int i=0; i<4; i++) {
                int dx = x + dir[i][0];
                int dy = y + dir[i][1];
                int L = 0;
                while(true) {
                    if(dx < 0 || dx == m || dy < 0 || dy == n || maze[dx][dy] == 1) {
                        dx -= dir[i][0];
                        dy -= dir[i][1];
                        break;
                    }
                    dx += dir[i][0];
                    dy += dir[i][1];
                    L++;
                }
               if(visited[x][y] + L < visited[dx][dy]) {
                    // cout << "Pushing: " << dx << "," << dy << endl;
                    visited[dx][dy] = visited[x][y] + L;
                    Q.emplace(dx, dy);
               }
            }
            L++;
        }
        return visited[dest[0]][dest[1]] == INT_MAX ? -1 : visited[dest[0]][dest[1]];
    }
};
```
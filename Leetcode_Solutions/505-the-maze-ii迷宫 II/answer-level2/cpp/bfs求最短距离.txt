### 解题思路

bfs求最短距离

### 代码

```cpp
class Solution {
public:
    int dirR[4] = {-1, 0, 1, 0};
    int dirC[4] = {0, 1, 0, -1};

    int shortestDistance(vector<vector<int>> &maze, vector<int> &start, vector<int> &destination) {
        // 加一层外墙省略边界判断
        int rowSize = maze.size();
        int colSize = maze[0].size();
        maze.insert(maze.begin(), vector<int>(colSize+ 2, 1));
        maze.push_back(vector<int>(colSize + 2, 1));
        for (int i = 1; i < maze.size() - 1; i++) {
            maze[i].insert(maze[i].begin(), 1);
            maze[i].push_back(1);
        }

        // start，destination移位
        start[0] = start[0] + 1;
        start[1] = start[1] + 1;
        destination[0] = destination[0] + 1;
        destination[1] = destination[1] + 1;

        // dp记录最短距离
        int MAX_DISTANCE = maze.size() * maze[0].size();
        vector<vector<int>> dp(maze.size(), vector<int>(maze[0].size(), MAX_DISTANCE));
        queue<pair<int, int>> q; // 宽搜
        q.push({start[0], start[1]});
        dp[start[0]][start[1]] = 0;

        while (!q.empty()) {
            int k = q.size();
            for (int m = 0; m < k; m++) {
                auto f = q.front();
                q.pop();
                for (int d = 0; d < 4; d++) {
                    int step = dp[f.first][f.second];
                    int r = dirR[d] + f.first;
                    int c = dirC[d] + f.second;
                    if (maze[r][c] == 1) continue;
                    while (maze[r][c] != 1) {
                        step++;
                        r += dirR[d];
                        c += dirC[d];
                    }
                    r -= dirR[d];
                    c -= dirC[d];
                    if (step < dp[r][c]) {
                        dp[r][c] = step;
                        q.push({r, c});
                    }
                }
            }
        }
        return dp[destination[0]][destination[1]] == MAX_DISTANCE ? -1 : dp[destination[0]][destination[1]];
    }
};
```
```
bool BFS(vector<vector<int>>& maze, vector<vector<bool>> &visit, vector<int> start, vector<int> end, int matrix_r, int matrix_c) {
        queue<pair<int, int>> q;
        // 队首元素入队
        q.push(make_pair(start[0], start[1]));
        visit[start[0]][start[1]] = true;
        while (!q.empty()) {
            pair<int, int> top = q.front();
            q.pop();
            // 取队列首元素，确定下是否到达终点
            if (top.first == end[0] && top.second == end[1]) {
                return true;
            }
            int x[4] = {0, 0, 1, -1};
            int y[4] = {1, -1, 0, 0};
            for (int i = 0; i < 4; i++) {
                int row = top.first;
                int col = top.second;
                // 球回沿着一个方向一直滚动， 除非遇到墙才会停下来选择别的方向
                while ((row + x[i]) >= 0 && (row + x[i]) < matrix_r && (col + y[i]) >= 0 && (col +y[i]) < matrix_c &&
                        maze[row + x[i]][col + y[i]] == 0) {
                    row += x[i];
                    col += y[i];
                }
                // 等到碰到墙壁，需要更换方向前，需要将此点入队，并标志已经访问
                // 队列中存放的是碰到墙壁的点或者边界点（可以理解为墙壁点）
                if (visit[row][col] == false) {
                    q.push(make_pair(row, col));
                    visit[row][col] = true;
                }
            }
        }
        return false;
    }
    bool hasPath(vector<vector<int>>& maze, vector<int>& start, vector<int>& destination) {
        int matrix_r = maze.size();
        int matrix_c = maze[0].size();
        vector<vector<bool>> visit(matrix_r, vector<bool>(matrix_c, false));
        bool res = BFS(maze, visit , start, destination, matrix_r, matrix_c);
        return res;
    }
```

// 终于理解题目的意思了， 在没有碰到墙壁之前，或者边界的时候， 这个球会沿着一个方向一直滚动！！！！！！！！！！！
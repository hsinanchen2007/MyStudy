先计算当前节点可以到达的下一个节点，再计算两个节点是否可以连接。


    bool canBeConnected(int a, int b, int dir) {
        // 2 表示任意方向可以连接， 
        //-1 表示所有方向无法连接， 
        //0，水平方向可以连接 
        //1, 竖直方向可以连接
        vector<<vector<int>> connect = {
            {2, -1, 1, 0, 1, 0},
            {-1, 2, 0, 0, 1, 1},
            {0, 1, -1, 0, 1, 2},
            {0, 2, 0, -1, 2, 1},
            {0, 1, 1, 2, -1, 0},
            {0, 1, 2, 1, 0, -1},
        }

        if (connect[a-1][b-1] == 2) {
            return true;
        }

        return (connect[a-1][b-1] == dir);
    }

    bool hasValidPath(vector<vector<int>>& grid) {
        map<int, vector<pair<int,int>>> posMap;
        posMap[1] = {{0, -1}, {0, 1}};
        posMap[2] = {{-1, 0}, {1, 0}};
        posMap[3] = {{0, -1}, {1, 0}};
        posMap[4] = {{0, 1}, {1, 0}};
        posMap[5] = {{0, -1}, {-1, 0}};
        posMap[6] = {{0, 1}, {-1, 0}};

        int n = grid.size();
        int m = grid[0].size();
        if (n == 1 && m == 1) {
            return true;
        }
        vector<vector<bool>> visited(n, vector<bool>(m, false));
        queue<pair<int,int>> q;
        q.push({0,0});
        visited[0][0] = true;
        while (!q.empty()) {
            int curX = q.front().first;
            int curY = q.front().second;
            for (int i = 0; i < posMap[grid[curX][curY]].size(); i++) {
                int nextX = curX + posMap[grid[curX][curY]].at(i).first;
                int nextY = curY + posMap[grid[curX][curY]].at(i).second;
                if (nextX >= 0 && nextX < n &&
                    nextY >= 0 && nextY < m &&
                    !visited[nextX][nextY] &&
                    canBeConnected(grid[curX][curY], grid[nextX][nextY], i)) {
                    if (nextX == n - 1 && nextY == m - 1) {
                        return true;
                    }
                    visited[nextX][nextY] = true;
                    q.push({nextX, nextY});
                            
                }
            }
            q.pop();
        }
        return false;
    }



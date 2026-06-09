### 解题思路

从多个建筑物多次BFS，统计均能覆盖的点中距离和最小值。

### 代码

```cpp
class Solution {
private:
    int dir[4][2] = { {0, -1}, {0, 1}, {-1, 0}, {1, 0}};
    int m;
    int n;
    int buildingCount = 0;
    vector<vector<int>> dis;
    vector<vector<int>> times;
public:
    int shortestDistance(vector<vector<int>>& grid) {
        m = grid.size();
        if(m == 0)
            return -1;
        n = grid[0].size();
        dis.assign(m, vector<int>(n));
        times.assign(m, vector<int>(n));
        
        vector<pair<int, int>> building;
        for(int i=0; i<m; i++)
            for(int j=0; j<n; j++) {
                if(grid[i][j] == 1) {
                    building.emplace_back(i, j);
                    buildingCount++;
                }
            }
        
        for(auto build: building) {
            // cout << build.first << build.second << endl;
            bfs(grid, build.first, build.second);
        }
        
        int minDist = INT_MAX;
        for(int i=0; i<m; i++)
            for(int j=0; j<n; j++)
                if(grid[i][j] == 0 && times[i][j] == buildingCount && dis[i][j] < minDist)
                    minDist = dis[i][j];
        
        return minDist > 0 && minDist != INT_MAX ? minDist : -1;
    }
    
    void bfs(vector<vector<int>>& grid, int i, int j) {
        queue<pair<int, int>> Q;
        vector<vector<bool>> visited(m, vector<bool>(n, false));
        int level = 0;
        
        Q.emplace(i, j);
        visited[i][j] = true;
        while(!Q.empty()) {
            int len = Q.size();
            level++;
            for(int i=0; i<len; i++) {
                auto cur = Q.front();
                Q.pop();
                int x = cur.first;
                int y = cur.second;
                
                for(int k=0; k<4; k++) {
                    int nx = x + dir[k][0];
                    if(nx < 0 || nx > m - 1)
                        continue;
                    int ny = y + dir[k][1];
                    if(ny < 0 || ny > n - 1)
                        continue;

                    if(grid[nx][ny] == 0 && !visited[nx][ny]) {
                        Q.emplace(nx, ny);
                        visited[nx][ny] = true;
                        times[nx][ny]++;
                        dis[nx][ny] += level;
                    }
                }
            }
        }
        
        /*
        for(int i=0; i<m; i++) {
            for(int j=0; j<n; j++)
                cout << dis[i][j] << " ";
            cout << endl;
        }
        cout << "===================" << endl;
        */
    }
};
```
```cpp
struct Position{
    int x, y, man;
    Position(int x_, int y_, int man_) : x(x_), y(y_), man(man_){};
    bool operator < (const Position &rhs) const {
        return man > rhs.man;
    }
};
class Solution {
public:
    int maxDistance(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = m ? grid[0].size() : 0;
        if (!m || !n) return 0;        
        priority_queue<Position> q;
        vector<vector<bool>> visited(m, vector<bool>(n, false));
        
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 1) {
                    q.push(Position(i, j, 0));
                    visited[i][j] = true;
                }
            }
        }
        int ans = -1;
        while (!q.empty()) {
            int sz = q.size();
            for (int i = 0; i < sz; i++) {
                auto p = q.top();
                ans = p.man ? max(ans, p.man) : -1;
                q.pop();
                for (int j = 0; j < 4; j++) {
                    int nx = p.x + dx[j];
                    int ny = p.y + dy[j];
                    if (nx < 0 || nx >= m || ny < 0 || ny >= m || grid[nx][ny] != 0 || visited[nx][ny]) continue;
                    visited[nx][ny] = true;
                    q.push(Position(nx, ny, p.man + 1));
                }
            }
        }
        return ans;
    }
private:
    int dx[4] = {-1, 1, 0, 0}, dy[4] = {0, 0, -1, 1};
    int manhattan(int x0, int y0, int x1, int y1) {
        return abs(x0 - x0) + abs(y0 - y1);
    }
};
```
``` C++
class Solution {
public:
    vector<vector<int>> dir = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        if (grid.size() == 0) return 0;
        int m = grid.size(), n = grid[0].size();
        vector<vector<bool>> visited(grid.size(), vector<bool>(grid[0].size(), false));        
        int ret = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 1 && (!visited[i][j])) {
                    visited[i][j] = true;
                    queue<pair<int, int>> A;
                    A.push({i, j});
                    int area = 1;
                    while (!A.empty()) {
                        pair<int, int> tmp = A.front();
                        A.pop();
                        for (int p = 0; p < dir.size(); p++) {
                            int x = tmp.first + dir[p][0];
                            int y = tmp.second + dir[p][1];
                            if (x >= 0 && x < m && y >= 0 && y < n && visited[x][y] == false) {
                                if (grid[x][y] == 1) {
                                    A.push({x, y});
                                    area++;
                                }
                                visited[x][y] = true;
                            }
                        }
                    }
                    ret = max(ret, area);
                }
            }
        }
        return ret;
    }   
};
```

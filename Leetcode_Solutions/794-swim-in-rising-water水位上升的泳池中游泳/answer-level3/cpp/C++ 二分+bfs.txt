思路：每次只确定一个水位，如果这个水位用dfs或bfs可以到达终点，那么就是可行的。用二分逼近求最小的水位。
问题在于：不能跳水！所以选择left就很重要了，left应该是选起点和终点的最大值。left大于等于起点就可以保证不跳水了；大于终点，可以排除掉一些无用的范围。
另外留意一下数值的范围，可以减少一些创建的代码。

```
class Solution {
public:
    int visited[55][55];
    int stepM[4] = {-1, 1, 0, 0};
    int stepN[4] = {0, 0, 1, -1};
    
    int swimInWater(vector<vector<int>>& grid) {
        int m = (int)grid.size();
        int n = (int)grid[0].size();
        int r = 50*50-1;
        int l = max(grid[0][0], grid[m-1][n-1]);
        
        while (l < r) {
            int mid = l + ((r-l)>>1);
            bool res = swimBfs(grid, mid);
            if (res) {
                r = mid;
            } else {
                l = mid + 1;
            }
        }
        return l;
    }
    
    bool swimBfs(vector<vector<int>>& grid, int threshold) {
        int m = (int)grid.size();
        int n = (int)grid[0].size();
        memset(visited, 0, sizeof visited);
        queue<pair<int, int>> q;
        q.push(pair<int, int>(0, 0));
        visited[0][0] = 1;

        while (!q.empty()) {
            auto cur = q.front();
            q.pop();
            for (int i=0; i<4; i++) {
                int nextM = cur.first + stepM[i];
                int nextN = cur.second + stepN[i];
                if (nextM < 0 || nextN < 0 || nextM >= m || nextN >= n) {
                    continue;
                }
                if (threshold < grid[nextM][nextN]) {
                    continue;
                }
                if (nextN == n - 1 && nextM == m-1) {
                    return true;
                }
                if (!visited[nextM][nextN]) {
                    visited[nextM][nextN] = 1;
                    auto p = pair<int, int>(nextM, nextN);
                    q.push(p);
                }
            }
        }

        return false;
    }
};
```
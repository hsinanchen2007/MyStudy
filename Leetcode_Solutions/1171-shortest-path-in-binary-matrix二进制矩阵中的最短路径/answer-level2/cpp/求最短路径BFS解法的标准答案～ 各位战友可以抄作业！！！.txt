### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        // breadth first search...
        if (grid[0][0]) return -1;

        const int N = grid.size();
        const vector<vector<int>> DIRS = { // 顺时针的8个direction
            {-1, 0}, {-1, 1}, {0, 1}, {1, 1}, {1, 0}, {1, -1}, {0, -1}, {1, -1}};

        grid[0][0] = 2; // 标记为 visited ...
        queue<pair<int, int>> q;
        q.emplace(0, 0);

        int ans = 1; // steps
        while (!q.empty()) {
            size_t size = q.size();
            while (size--) {
                int r = q.front().first, c = q.front().second;
                q.pop();

                if (r == N - 1 && c == N - 1) // 已经抵达右下角 ...
                    return ans;

                for (auto& d : DIRS) {
                    int r1 = r + d[0], c1 = c + d[1];
                    if (r1 < 0 || c1 < 0 || r1 >= N || c1 >= N || grid[r1][c1])
                        continue;
                    
                    grid[r1][c1] = 2; // visited ...
                    q.emplace(r1, c1);
                }
            }
            ans++;
        }

        return -1;
    }
};
```
### 解题思路

记忆化搜索 - 宽搜

待优化 TODO -> 动态规划

### 代码

```cpp

struct Node {
    int r, c, val;

    Node(int _r, int _c, int _v) : r(_r), c(_c), val(_v) {};

    bool friend operator<(const Node &n1, const Node &n2) {
        return n1.val > n2.val;
    }
};

class Solution {
public:
    int maxDistance = 1;
    int dirR[4] = {-1, 0, 1, 0};
    int dirC[4] = {0, 1, 0, -1};

    int longestIncreasingPath(vector<vector<int>> &matrix) {
        if (matrix.size() == 0 || matrix[0].size() == 0) return 0;
        vector<vector<int>> distances(matrix.size(), vector<int>(matrix[0].size(), 1));
        for (int i = 0; i < matrix.size(); i++) {
            for (int j = 0; j < matrix[0].size(); j++) {
                bfs(matrix, distances,i, j);
            }
        }
        return maxDistance;
    }

    void bfs(vector<vector<int>> &matrix, vector<vector<int>> &distances, int i, int j) {
        queue<pair<int, int>> q;
        q.push({i, j});
        while (!q.empty()) {
            int k = q.size();
            for (int m = 0; m < k; m++) {
                auto f = q.front();
                q.pop();
                int step = distances[f.first][f.second];
                for (int d = 0; d < 4; d++) {
                    int r = dirR[d] + f.first;
                    int c = dirC[d] + f.second;
                    if (r < 0 || r >= matrix.size() || c < 0 || c >= matrix[0].size())   continue;
                    if (matrix[f.first][f.second]>= matrix[r][c])continue;
                    if (step + 1 <= distances[r][c]) continue;
                    distances[r][c] = step + 1;
                    maxDistance = max(maxDistance, step + 1);
                    q.push({r, c});
                }
            }
        }
    }
};
```
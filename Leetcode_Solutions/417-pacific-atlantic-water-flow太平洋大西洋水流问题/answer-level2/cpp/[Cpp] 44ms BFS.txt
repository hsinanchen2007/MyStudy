### 解题思路
1. 从两个大洋开始倒着往陆地上蔓延，记录每个位置是否能被蔓延到
2. 如果一个位置既可以通过太平洋蔓延到也可以通过大西洋蔓延到，该位置即为一个结果

### 代码

```cpp
class Solution {
public:
    void helper1(vector<vector<int>>& matrix, vector<vector<bool>>& st1, int n, int m) {
        queue<pair<int, int>> q;
        vector<vector<bool>> flag(n, vector<bool>(m, false));
        for (int i = 0; i < n; i++) {
            q.push({i, 0});
            flag[i][0] = true;
            st1[i][0] = true;
        }
        for (int i = 0; i < m; i++) {
            q.push({0, i});
            flag[0][i] = true;
            st1[0][i] = true;
        }

        vector<int> dx = {-1, 1, 0, 0};
        vector<int> dy = {0, 0, -1, 1};
        while (!q.empty()) {
            pair<int, int> t = q.front(); q.pop();
            int ni = t.first, nj = t.second;
            for (int i = 0; i < 4; i++) {
                int pi = ni + dx[i], pj = nj + dy[i];
                if (pi >= 0 && pj >= 0 && pi < n && pj < m && matrix[pi][pj] >= matrix[ni][nj] && !flag[pi][pj]) {
                    q.push({pi, pj});
                    flag[pi][pj] = true;
                    st1[pi][pj] = true;
                }
            }
        }
    }

    void helper2(vector<vector<int>>& matrix, vector<vector<bool>>& st2, int n, int m) {
        queue<pair<int, int>> q;
        vector<vector<bool>> flag(n, vector<bool>(m, false));
        for (int i = 0; i < n; i++) {
            q.push({i, m - 1});
            flag[i][m- 1] = true;
            st2[i][m - 1] = true;
        }
        for (int i = 0; i < m; i++) {
            q.push({n - 1, i});
            flag[n - 1][i] = true;
            st2[n - 1][i] = true;
        }

        vector<int> dx = {-1, 1, 0, 0};
        vector<int> dy = {0, 0, -1, 1};
        while (!q.empty()) {
            pair<int, int> t = q.front(); q.pop();
            int ni = t.first, nj = t.second;
            for (int i = 0; i < 4; i++) {
                int pi = ni + dx[i], pj = nj + dy[i];
                if (pi >= 0 && pj >= 0 && pi < n && pj < m && matrix[pi][pj] >= matrix[ni][nj] && !flag[pi][pj]) {
                    q.push({pi, pj});
                    flag[pi][pj] = true;
                    st2[pi][pj] = true;
                }
            }
        }
    }

    vector<vector<int>> pacificAtlantic(vector<vector<int>>& matrix) {
        vector<vector<int>> res;
        int n = matrix.size();
        if (n < 1) return res;
        int m = matrix[0].size();
        vector<vector<bool>> st1(n, vector<bool>(m, false));
        vector<vector<bool>> st2(n, vector<bool>(m, false));

        helper1(matrix, st1, n, m);
        helper2(matrix, st2, n, m);
        
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (st1[i][j] && st2[i][j]) {
                    res.push_back({i, j});
                }
            }
        }

        return res;
    }
};
```
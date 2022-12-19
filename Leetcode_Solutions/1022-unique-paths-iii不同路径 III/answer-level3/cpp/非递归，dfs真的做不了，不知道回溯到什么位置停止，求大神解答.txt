### 解题思路

### 代码

```cpp
class Solution {
public:
    vector<vector<int>> direct = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
    int uniquePathsIII(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        int sum = 2;
        queue<vector<pair<int, int>>> q;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 0) {
                    sum++;
                }
                if (grid[i][j] == 1) {
                    pair<int, int> p({i, j});
                    vector<pair<int, int>> v;
                    v.push_back(p);
                    q.push(v);
                }
            }
        }
        int ans = 0;
        while (q.empty() == false) {
            vector<pair<int, int>> curr = q.front();
            pair<int, int> p = curr.back();
            q.pop();
            if (grid[p.first][p.second] == 2) {
                if (curr.size() == sum) {
                    ans++;
                }
                continue;
            }
            pair<int, int> tmp;
            for (int i = 0; i < 4; i++) {
                vector<pair<int, int>> v = curr;
                tmp.first = p.first + direct[i][0];
                tmp.second = p.second + direct[i][1];
                int x = tmp.first;
                int y = tmp.second;
                if (x < 0 || x >= m || y < 0 || y >= n) {
                    continue;
                }
                if (find(curr.begin(), curr.end(), tmp) != curr.end()) {
                    continue;
                }
                if (grid[x][y] == 0 || grid[x][y] == 2) {
                    v.push_back(tmp);
                    q.push(v);
                }
            }
        }
        return ans;
    }
};
```
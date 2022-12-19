### 解题思路
看起来简单，写起来好蛋疼

### 代码

```cpp
class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
            long m = matrix.size();
        if (m == 0) {
            return {};
        }
        long n = matrix[0].size();
        if (n == 0) {
            return {};
        }
        vector<vector<bool>> visit = vector<vector<bool>>(m, vector<bool>(n, false));
        vector<pair<int, int>> steps;
        steps.emplace_back(pair<int, int>(0, 1));
        steps.emplace_back(pair<int, int>(1, 0));
        steps.emplace_back(pair<int, int>(0, -1));
        steps.emplace_back(pair<int, int>(-1, 0));
        vector<int> res;
        int x=0, y=0;
        int i = 0;
        while (!visit[x][y]) {
            res.emplace_back(matrix[x][y]);
            visit[x][y] = true;
            x = x+steps[i].first;
            y = y+steps[i].second;
            if (res.size() == m*n) {
                return res;
            }
            while (x <0 || y < 0 || x >= m || y >= n || visit[x][y]) {
                x = x-steps[i].first;
                y = y-steps[i].second;
                i = (i+1)%4;
                x = x+steps[i].first;
                y = y+steps[i].second;
            }
        }
        return res;
    }
};
```
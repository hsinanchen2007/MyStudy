### 解题思路
深度优先搜索
写的有点长

### 代码

```cpp
class Solution {
    int ans;
    int m;
    int n;
    int k;
    vector<vector<int>> grid;
public:
    int movingCount(int _m, int _n, int _k) {
        if (_k < 0) return 0;
        if (_k == 0) return 1;
        ans = 0; m = _m; n = _n; k = _k;
        grid=vector<vector<int>>(m, vector<int>(n, 0));
        stack<pair<int, int>> s;
        s.push({ 0,0 });
        grid[0][0] = 1;
        while (!s.empty())
        {
            auto cur = s.top();
            s.pop();
            ans++;
            if (isOK(cur.first + 1, cur.second) && can(cur.first + 1, cur.second))
            {
                s.push({ cur.first + 1,cur.second });
                grid[cur.first + 1][cur.second] = 1;
            }
            if (isOK(cur.first - 1, cur.second) && can(cur.first - 1, cur.second))
            {
                s.push({ cur.first - 1,cur.second });
                grid[cur.first - 1][cur.second] = 1;
            }
            if (isOK(cur.first, cur.second + 1) && can(cur.first, cur.second + 1))
            {
                s.push({ cur.first,cur.second + 1 });
                grid[cur.first][cur.second + 1] = 1;
            }
            if (isOK(cur.first, cur.second - 1) && can(cur.first, cur.second - 1))
            {
                s.push({ cur.first,cur.second - 1 });
                grid[cur.first][cur.second - 1] = 1;
            }
        }
        return ans;
    }
    bool isOK(int i, int j)
    {
        if (i >= 0 && i < m && j >= 0 && j < n && grid[i][j] == 0)
            return true;
        return false;
    }
    bool can(int i, int j)
    {
        int sum = 0;
        while (i != 0)
        {
            sum += i % 10;
            i /= 10;
        }
        while (j != 0)
        {
            sum += j % 10;
            j /= 10;
        }
        if (sum <= k)
            return true;
        return false;
    }
};
```
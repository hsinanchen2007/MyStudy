### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
    map<int,int> mp;
    int movingCount(int m, int n, int k) {
        for (int i = 0; i < 100; ++i) {
            mp[i] = digitSum(i);
        }
        int direcs[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
        vector<vector<int>> grid(m, vector<int>(n, 0));
        int res = 0;
        dfs(grid, direcs, 0, 0, k, res);
        return res;
    }
    int digitSum(int n) {
        int sum = 0;
        while (n) {
            sum += n % 10;
            n /= 10;
        }
        return sum;
    }
    void dfs(vector<vector<int>>& grid, int direcs[4][2], int r, int c, int k, int& res) {
        if (r < 0 || r >= grid.size() || c < 0 || c >= grid[0].size() || grid[r][c]) {
            return;
        }
        grid[r][c] = 1;
        if (mp[r] + mp[c] > k) {
            return;
        }
        ++res;
        for (int i = 0; i < 4; ++i) {
            int x = r + direcs[i][0];
            int y = c + direcs[i][1];
            dfs(grid, direcs, x, y, k, res);
        }
    }
};
```
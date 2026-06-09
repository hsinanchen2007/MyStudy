**解法一：**
```
class Solution {
public:
    int countCornerRectangles(vector<vector<int>>& grid) {
        if (grid.empty()) return 0;
        int R = grid.size();
        int C = grid[0].size();
        int res = 0;
        for (int r = 0; r < R; ++r) {
            for (int i = 0; i < C; ++i) {
                if (grid[r][i] == 0) continue;
                for (int j = i + 1; j < C; ++j) {
                    if (grid[r][j] == 0) continue;
                    for (int r1 = r + 1; r1 < R; ++r1) {
                        if (grid[r1][i] != 1 || grid[r1][j] != 1) continue;
                        ++res;
                    }
                }
            }
        }
        return res;
    }
};
```
![image.png](https://pic.leetcode-cn.com/c8a4bb793df30095352ae3387e1829efe50f4cd2adb76aabcc0d8f705abe9efe-image.png)

**解法二：**
```
class Solution {
public:
    int countCornerRectangles(vector<vector<int>>& grid) {
        if (grid.empty()) return 0;
        int R = grid.size();
        int C = grid[0].size();
        int res = 0;
        if (C < R) {
            for (int i = 0; i < C; ++i) {
                for (int j = i + 1; j < C; ++j) {
                    int count = 0;
                    for (int r = 0; r < R; ++r) {
                        count += grid[r][i] + grid[r][j] == 2;
                    }
                    res += count * (count - 1) / 2;
                }
            }
        } else {
            for (int i = 0; i < R; ++i) {
                for (int j = i + 1; j < R; ++j) {
                    int count = 0;
                    for (int c = 0; c < C; ++c) {
                        count += grid[i][c] + grid[j][c] == 2;
                    }
                    res += count * (count - 1) / 2;
                }
            }
        }
        return res;
    }
};
```
![image.png](https://pic.leetcode-cn.com/6f2006082bf7ee16f38a687f99f57abc2d3c68874ac1b9ef7315412efd0cc722-image.png)


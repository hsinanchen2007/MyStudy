稍微注意一下，条件判断四个方向循环就好了，无技术

```
/*
 * @lc app=leetcode.cn id=59 lang=cpp
 *
 * [59] 螺旋矩阵 II
 */
class Solution {
 public:
  vector<vector<int>> generateMatrix(int n) {
    vector<vector<int>> result(n, vector<int>(n));
    int d = 1;  // d表方向，1右边，2下边，3左边，4上边
    for (int i = 1, r = 0, c = 0; i <= n * n; ++i) {
      switch (d) {
        case 1:
          if (c < n - 1 && !result[r][c]) {
            result[r][c++] = i;
          } else if (c == n - 1 && !result[r][c]) {
            result[r++][c] = i;
            d = 2;
          } else {
            result[++r][--c] = i;
            ++r;
            d = 2;
          }
          break;
        case 2:
          if (r < n - 1 && !result[r][c]) {
            result[r++][c] = i;
          } else if (r == n - 1 && !result[r][c]) {
            result[r][c--] = i;
            d = 3;
          } else {
            result[--r][--c] = i;
            --c;
            d = 3;
          }
          break;
        case 3:
          if (c > 0 && !result[r][c]) {
            result[r][c--] = i;
          } else if (c == 0 && !result[r][c]) {
            result[r--][c] = i;
            d = 4;
          } else {
            result[--r][++c] = i;
            --r;
            d = 4;
          }
          break;
        case 4:
          if (r > 0 && !result[r][c]) {
            result[r--][c] = i;
          } else if (r == 0 && !result[r][c]) {
            result[r][c++] = i;
            d = 1;
          } else {
            result[++r][++c] = i;
            ++c;
            d = 1;
          }
          break;
      }
    }
    return result;
  }
};
```
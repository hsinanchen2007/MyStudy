1，由于给定矩阵中的整数范围为 [0, 255]。因此可以用8个bit位来存储像素原始值
2，由于周围的矩阵个数最多为8，因此可以用4个bit位来存储周围点个数
3，由于255 * 8 < 2^12，因此可以用12个bit来存储周围点的加和
以上一共可以用到24个bit，int类型完全满足需求。
```
class Solution {
public:
    int dirs[8][2] = {
        {1, 0}, {0, 1},
        {-1, 0}, {0, -1},
        {1, 1}, {-1, -1},
        {1, -1}, {-1, 1}};
    bool valid(int r, int c, int R, int C) {
        return r >= 0 && r < R && c >= 0 && c < C;
    }
    vector<vector<int>> imageSmoother(vector<vector<int>>& M) {
        if (M.empty()) return M;
        int R = M.size();
        int C = M[0].size();
        int MASK = 255;
        for (int i = 0; i < R; ++i) {
            for (int j = 0; j < C; ++j) {
                for (int k = 0; k < 8; ++k) {
                    int r = i + dirs[k][0];
                    int c = j + dirs[k][1];
                    if (valid(r, c, R, C)) {
                        M[i][j] += (M[r][c] & MASK) << 12; // 用12位以上bit位记录周围像素数
                        M[i][j] += 1 << 8; // 记录周围点数
                    }
                }
            }
        }
        for (int i = 0; i < R; ++i) {
            for (int j = 0; j < C; ++j) {
                int count = ((M[i][j] >> 8) & 15) + 1;
                M[i][j] = ((M[i][j] & MASK) + (M[i][j] >> 12)) / count;
            }
        }
        return M;
    }
};
```
![image.png](https://pic.leetcode-cn.com/e8d8b708be2035efeeaa47ba7d5cef7a99e8a96a69d79f18304e5d7f9c036a60-image.png)

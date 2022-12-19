对矩形的边上的点按照可行的方向进行逐一遍历找最大连续1线段即可
代码如下：
```C++ []
class Solution {
public:
    int helper(const vector<vector<int> >& M, int i, int j, int dx, int dy, int R, int C) {
        int res = 0;
        int lx = -1;
        int ly = -1;
        while (i >= 0 && i < R && j >= 0 && j < C) {
            if (M[i][j] == 1) {
                if (lx == -1) {
                    lx = i;
                    ly = j;
                }
                res = max(res, abs(i - lx) + 1);
                res = max(res, abs(j - ly) + 1);
            } else {
                lx = i + dx;
                ly = j + dy;
            }
            i += dx;
            j += dy;
        }
        return res;
    }

    int longestLine(vector<vector<int>>& M) {
        if (M.empty()) return 0;
        int R = M.size();
        int C = M[0].size();
        int res = 0;
        for (int i = 0; i < R; ++i) {
            res = max(res, helper(M, i, 0, 0, 1, R, C));
            res = max(res, helper(M, i, 0, 1, 1, R, C));
            res = max(res, helper(M, i, C - 1, 1, -1, R, C));
            if (res == max(R, C)) return res;
        }
        for (int j = 0; j < C; ++j) {
            res = max(res, helper(M, 0, j, 1, 0, R, C));
            res = max(res, helper(M, 0, j, 1, 1, R, C));
            res = max(res, helper(M, 0, j, 1, -1, R, C));
            if (res == max(R, C)) return res;
        }
        return res;
    }
};
```
![image.png](https://pic.leetcode-cn.com/8d45741f1bf783b8648a8886e8c76e92914c86af9cd93b6296301564ea5107d9-image.png)


# 思路：
构建一个状态矩阵：
用第一个bit存储太平洋是否能达到此点
用第二个bit存储大西洋是否能达到此点
最终查询点状态为3（二进制为11）的点即可。
代码如下：
```C++ []
class Solution {
public:
    int dirs[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
    bool valid(int r, int c, int R, int C) {
        return r >= 0 && r < R && c >= 0 && c < C;
    }
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& matrix) {
        vector<vector<int> > res;
        if (matrix.empty()) return res;
        int R = matrix.size();
        int C = matrix[0].size();
        vector<vector<int> > status(R, vector<int>(C, 0));
        queue<pair<int, int> > q;
        for (int i = 0; i < R; ++i) {
            q.push({i, 0});
            status[i][0] |= 1;
            q.push({i, C - 1});
            status[i][C - 1] |= 2;
        }
        for (int i = 0; i < C; ++i) {
            q.push({0, i});
            status[0][i] |= 1;
            q.push({R - 1, i});
            status[R - 1][i] |= 2;
        }
        while (!q.empty()) {
            auto p = q.front();
            q.pop();
            for (int i = 0; i < 4; ++i) {
                int r = p.first + dirs[i][0];
                int c = p.second + dirs[i][1];
                if (valid(r, c, R, C) && matrix[r][c] >= matrix[p.first][p.second]) {
                    if (status[r][c] != status[p.first][p.second]) {
                        status[r][c] |= status[p.first][p.second];
                        q.push({r, c});
                    }
                }
            }
        }
        for (int i = 0; i < R; ++i) {
            for (int j = 0; j < C; ++j) {
                if (status[i][j] == 3) {
                    res.push_back({i, j});
                }
            }
        }
        return res;
    }
};
```
![image.png](https://pic.leetcode-cn.com/e044dd88a80ae68e0fe4db9b497a3f72cb282e5015d07641f5f5cbefb485c022-image.png)

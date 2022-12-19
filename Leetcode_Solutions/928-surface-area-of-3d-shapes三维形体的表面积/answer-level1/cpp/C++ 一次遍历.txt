一次遍历，每次都扣除新加入的部分与相邻的左前方的方块的重合部分面积即可
详见代码如下：
```
class Solution {
public:
    int dirs[2][2] = {{-1, 0}, {0, -1}}; // 相邻的左前方方块的方向
    bool valid(int r, int c, int R, int C) {
        return r >= 0 && r < R && c >= 0 && c < C;
    }
    int surface(int height) {
        return 2 + 4 * height;
    }
    int surfaceArea(vector<vector<int>>& grid) {
        if (grid.empty()) return 0;
        int R = grid.size();
        int C = grid[0].size();
        int res = 0;
        for (int i = 0; i < R; ++i) {
            for (int j = 0; j < C; ++j) {
                if (grid[i][j] == 0) continue;
                res += surface(grid[i][j]);
                for (int k = 0; k < 2; ++k) {
                    int r = i + dirs[k][0];
                    int c = j + dirs[k][1];
                    if (!valid(r, c, R, C)) continue;
                    res -= 2 * min(grid[i][j], grid[r][c]); // 扣除与之前的重合部分面积
                }
            }
        }
        return res;
    }
};
```
![image.png](https://pic.leetcode-cn.com/2482823f5040432020acad75ad5d2dd55f5be261aee90251b1219f8ba2e2ecc1-image.png)

# 思路：
1，定义数组`arm[N][N][4]`为点在四方向上延伸的最大长度
`arm[i][j][0]`代表点`[i, j]`向上最长延伸的1的最大长度
`arm[i][j][1]`代表点`[i, j]`向左最长延伸的1的最大长度
`arm[i][j][2]`代表点`[i, j]`向下最长延伸的1的最大长度
`arm[i][j][3]`代表点`[i, j]`向右最长延伸的1的最大长度
2，遍历所有点四方向延伸手臂最小值的最大值即可
找到`max{min{arm[i][j][0], arm[i][j][1], arm[i][j][2], arm[i][j][3]}}`即是答案
```C++ []
class Solution {
public:
    int orderOfLargestPlusSign(int N, vector<vector<int>>& mines) {
        if (mines.size() == N * N) return 0;
        if (mines.size() > N * N - 5) return 1;
        int grid[N][N];
        int arm[N][N][4];
        // set all the value of grid to be "1", this is a trick to use "-1"
        memset(grid, -1, sizeof(grid));
        // set all the value of arm to be "0"
        memset(arm, 0, sizeof(arm));
        for (auto& v : mines) {
            grid[v[0]][v[1]] = 0;
        }
        for (int i = 0; i < N; ++i) {
            for (int j = 0; j < N; ++j) {
                if (grid[i][j] == 0) continue;
                arm[i][j][0] = 1 + ((i > 0) ? arm[i - 1][j][0] : 0);
                arm[i][j][1] = 1 + ((j > 0) ? arm[i][j - 1][1] : 0);
            }
        }
        for (int i = N - 1; i >= 0; --i) {
            for (int j = N - 1; j >= 0; --j) {
                if (grid[i][j] == 0) continue;
                arm[i][j][2] = 1 + ((i < N - 1) ? arm[i + 1][j][2] : 0);
                arm[i][j][3] = 1 + ((j < N - 1) ? arm[i][j + 1][3] : 0);
            }
        }
        int res = 0;
        for (int i = 0; i < N; ++i) {
            for (int j = 0; j < N; ++j) {
                if (grid[i][j] == 0) continue;
                int s = min(min(arm[i][j][0], arm[i][j][1]), min(arm[i][j][2], arm[i][j][3]));
                res = max(res, s);
            }
        }
        return res;
    }
};
```

![image.png](https://pic.leetcode-cn.com/4e8d438630f48fe8399815eab5da1d66406e55dc2dae4cde35f6b8a80dc4dfc8-image.png)

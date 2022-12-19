```
class Solution {
public:
    bool valid(const vector<vector<int>>& grid, int r, int c) {
        if (grid[r + 1][c + 1] != 5) return false;
        unordered_set<int> s;
        for (int i = 0; i < 3; ++i) {
            for (int j = 0; j < 3; ++j) {
                int t = grid[r + i][c + j];
                if (t < 1 || t > 9 || s.count(t)) return false;
                s.insert(t);
            }
        }
        for (int i = 0; i < 3; ++i) {
            int s1 = 0;
            int s2 = 0;
            for (int j = 0; j < 3; ++j) {
                s1 += grid[r + i][c + j];
                s2 += grid[r + j][c + i];
            }
            if (s1 != 15 || s2 != 15) return false;
        }
        // 以上判断已经足够断定幻方是否存在
        return true;
    }
    int numMagicSquaresInside(vector<vector<int>>& grid) {
        if (grid.empty()) return 0;
        int R = grid.size();
        int C = grid[0].size();
        int res = 0;
        for (int i = 0; i < R - 2; ++i) {
            for (int j = 0; j < C - 2; ++j) {
                res += valid(grid, i, j);
            }
        }
        return res;
    }
};
```

![image.png](https://pic.leetcode-cn.com/c7263c405bb35cd15538905966c7c4ec75c032d52406a927280fe8644a7ca45f-image.png)

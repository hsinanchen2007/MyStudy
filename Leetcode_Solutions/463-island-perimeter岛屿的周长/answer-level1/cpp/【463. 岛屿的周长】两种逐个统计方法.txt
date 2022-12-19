### 思路一：逐个增加
对于每个为1的方格，统计四条边是否包括在周长中。

### 代码

```cpp
class Solution {
public:
    int islandPerimeter(vector<vector<int>>& grid) {
        if (grid.empty()) return 0;
        int res = 0, row = grid.size(), col = grid[0].size();
        for (int i = 0; i < row; ++i) {
            for (int j = 0; j < col; ++j) {
                if (grid[i][j] == 0) continue;
                if (i == 0 || grid[i - 1][j] == 0) ++res; //上
                if (i == row - 1 || grid[i + 1][j] == 0) ++res; //下
                if (j == 0 || grid[i][j - 1] == 0) ++res; //左
                if (j == col - 1 || grid[i][j + 1] == 0) ++res; //右
            }
        }
        return res;
    }
};
```

### 思路二：逆向思维
对于每个格子，先加上四个边，如果左边和上边有格子，则减去2个边。

```c++
class Solution {
public:
    int islandPerimeter(vector<vector<int>>& grid) {
        if (grid.empty()) return 0;
        int res = 0, row = grid.size(), col = grid[0].size();
        for (int i = 0; i < row; ++i) {
            for (int j = 0; j < col; ++j) {
                if (grid[i][j] == 0) continue;
                res += 4;
                if (j > 0 && grid[i][j - 1] == 1) res -= 2; //左面有格子
                if (i > 0 && grid[i - 1][j] == 1) res -= 2; //上面有格子
            }
        }
        return res;
    }
};
```

基本记录就是，看到一个1，就把它上下左右的1，都变成0，接着把它上下左右的1也变成0，直到1的附近的1都变成0.

也就是

11000
11000
00100
00011
最终会变成

10000
00000
00100
00010

链接：https://leetcode-cn.com/problems/number-of-islands/solution/cpp-shi-jian-wei-8msde-dfsfang-fa-by-xu-zhou-geng/

```
class Solution {
public:
    void backTrace(vector<vector<char>>& grid, int i, int j)
    {
        if (!(i >= 0 && i < grid.size() && j >= 0 && j < grid[0].size())) {
            return;
        }

        if (grid[i][j] == '1') {
            grid[i][j] = '0';
            backTrace(grid, i + 1, j);
            backTrace(grid, i - 1, j);
            backTrace(grid, i, j + 1);
            backTrace(grid, i, j - 1);
        }

    }

    int numIslands(vector<vector<char>>& grid) {
        int row = grid.size();
        if (row == 0) {
            return 0;
        }
        int clou = grid[0].size();

        int islandNum = 0;
        int i, j;
        for (i = 0; i < row; i++) {
            for (j = 0; j < clou; j++) {
                if (grid[i][j] == '1') {
                    islandNum++;
                    backTrace(grid, i, j);
                }
            }
        }

        return islandNum;
    }
};
```

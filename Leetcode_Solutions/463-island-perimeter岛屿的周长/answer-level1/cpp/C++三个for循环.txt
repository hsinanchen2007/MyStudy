### 解题思路
遍历每一个陆地的四个邻块，若是水或者边界，则边长+1
![image.png](https://pic.leetcode-cn.com/c2216feefb7c2055e481b850b7d6c89ddfb689a133c6f2e621b74f4c78fa8b7c-image.png)

### 代码

```cpp
class Solution {
private:
    int dir[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
    int col;
    int row;
public:

    int getNeighberNum(vector<vector<int>>& grid, int x, int y) {
        int ret = 0;
        for (int i = 0; i < 4; i++) {
            int xx = x + dir[i][0];
            int yy = y + dir[i][1];
            if (xx >= 0 && xx < col && yy >= 0 && yy < row) {
                if (grid[yy][xx] == 0) { //旁边是水地，边长++
                    ret++;
                }
            } else { //旁边是边界，边长++
                ret++;
            }
        }
        return ret;
    }
    int islandPerimeter(vector<vector<int>>& grid) {
        if (grid.size() == 0) {
            return 0;
        }
        row = grid.size();
        col = grid[0].size();
        int ret = 0;
        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {
                if (grid[i][j] == 1) {
                    ret += getNeighberNum(grid, j, i);
                }
            }
        }

        return ret;
    }
};
```
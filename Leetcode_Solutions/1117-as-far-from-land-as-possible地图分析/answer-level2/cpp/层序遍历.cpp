### 解题思路
1.先找出所有的岛屿放到一个queue；
2.在取出距离为1的海，把距离为2的海洋（4个方向）回到queue中;
3.在取出距离为2的海，把距离为3的海洋（4个方向）回到queue中;
....
一直遍历完所有的海洋。

### 代码

```cpp
class Solution {
public:
    int maxDistance(vector<vector<int>>& grid) {
        int directions[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
        int len  =  grid.size();
        int Q[10000];
        int start = 0, end = 0;

        for (int i = 0; i < len; ++i)
            for (int j = 0; j < len; ++j)
                if (grid[i][j] == 1)
                    Q[end++] = (i << 8) + j;

        if (end == len * len|| !end) return -1;

        int value;
        while (start != end) {
            int valueQ = Q[start++];
            int x = (valueQ & 0xff00) >> 8;
            int y = valueQ & 0xff;
            value = ((valueQ & 0xff0000) >> 16) + 1;
            
            for (int i = 0; i < 4; ++i) {
                int x1 = x + directions[i][0];
                int y1 = y + directions[i][1];

                if (x1 >= 0 && x1 < len && y1 >= 0 && y1 < len && !grid[x1][y1]) {
                    Q[end++] = (value << 16) + (x1 << 8) + y1;
                    grid[x1][y1] = value;
                }
            }
        }

        return --value;
    }
};
```
### 解题思路
此处撰写解题思路
1. 原地算法，用复合状态来解决
2. if (A && B) 如果 A 为 false ，整个表达式就为 false，不再计算 B 的值了。
3. if (A & B) 如果 A 为 false ，整个表达式就为 false，但还要计算 B 的值。

### 代码

```cpp
class Solution {
public:
    void gameOfLife(vector<vector<int>>& board) {
        // 原地算法，用复合状态来解决
        // 用-1表示原来是活的后来死了
        // 用1表示原来是活的现在还是活的
        // 用2表示原来是死的后来活了
        // 用0表示原来是死的现在还是死的
        int m = board.size();
        int n = board[0].size();
        int offset[3] = {-1, 0, 1};

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                int num = 0;

                // 遍历8个方向
                for (int p = 0; p < sizeof(offset) / sizeof(offset[0]); p++) {
                    for (int q = 0; q < sizeof(offset) / sizeof(offset[0]); q++) {
                        int dx = offset[p], dy = offset[q];
                        if (dx == 0 && dy == 0) continue;
                        int x = i + dx, y = j + dy;
                        if (x >= 0 && x < m && y >= 0 && y < n && abs(board[x][y]) == 1) num++;
                    }
                }

                // 根据原始状态给当下一个状态赋值
                if (board[i][j] == 1 && (!(num == 2 || num == 3))) board[i][j] = -1;

                if (board[i][j] == 0 && num == 3) board[i][j] = 2;
            }
        }

        // 把复合状态改为最终状态
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (board[i][j] > 0) {
                    board[i][j] = 1;
                } else {
                    board[i][j] = 0;
                }
            }
        }
    }
};
```
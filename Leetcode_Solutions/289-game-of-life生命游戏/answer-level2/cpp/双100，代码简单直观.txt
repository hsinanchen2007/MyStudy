![image.png](https://pic.leetcode-cn.com/3ddfc15a66f66d4699a6187dca560503ed11e36c1c902dcfd83876430f692e3d-image.png)

### 解题思路
1.用一个bit表示原始的dead or alive, 用另外一个bit表示现在是dead or alive，避免占用太大的空间；
2.最后在做一次清理（除以2，用当前的状态代替老的状态）。

### 代码

```cpp
class Solution {
    int directions[8][2] = {{-1, -1}, {-1, 0}, {-1, 1},
                            {0, -1},           {0, 1},
                            {1, -1},  {1, 0},  {1, 1}};
    int row;
    int col;
    int _isAlive(const vector<vector<int>> &board, const int &rowPos, const int &colPos) {
        int aroundAlive = 0;
        for (int i = 0; i < 8; ++i) {
            int x = rowPos + directions[i][0];
            int y = colPos + directions[i][1];

            if (x >= 0 && x < row && y >= 0 && y < col) {
                if (board[x][y] & 1) aroundAlive++;
            }
        }
        return aroundAlive;
    }
public:
    void gameOfLife(vector<vector<int>>& board) {
        row = board.size();
        if (!row) return;
        col = board[0].size();

        for (int i = 0; i < row; ++i)
            for (int j = 0; j < col; ++j) {
                int numAlive = _isAlive(board,  i, j);
                int &alive = board[i][j];
                if (alive) {
                    if (numAlive == 2 || numAlive == 3)
                        alive += 2;
                } else {
                    if (numAlive == 3)
                        alive += 2;
                }
            }
        
        for (int i = 0; i < row; ++i)
            for (int j = 0; j < col; ++j)
                board[i][j] /=  2;
    }
};
```
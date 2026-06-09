### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
    void gameOfLife(vector<vector<int>>& board) {
        if (board.empty()) return;
        int row = board.size();
        int col = board[0].size();

        vector<int> temp(col, 0);
        vector<vector<int>> result(row, temp);
        vector<vector<int>> dirs = {
            {-1, 0},
            {1, 0},
            {0, -1},
            {0, 1},
            {-1, -1},
            {-1, 1},
            {1, 1},
            {1, -1}
        };

        for (int i = 0; i < row; ++i) {
            for (int j = 0; j < col; ++j) {
                int alive_cell = 0;
                for (auto dir : dirs) {
                    int new_r = dir[0] + i, new_c = dir[1] + j;
                    if (new_r >= 0 && new_r < row && new_c >= 0 && new_c < col) {
                        alive_cell += board[new_r][new_c];
                    }
                }
                if (board[i][j] && alive_cell >= 2 && alive_cell <= 3) {
                    result[i][j] = 1;
                }

                if (!board[i][j] && alive_cell == 3) {
                    result[i][j] = 1;
                }
            }
        }
        for (int i = 0; i < row; ++i) {
            for (int j = 0; j < col; ++j) {
                board[i][j] = result[i][j];
            }
        }

        return;
    }
};
```
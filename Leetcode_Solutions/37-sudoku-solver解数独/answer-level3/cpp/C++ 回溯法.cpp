### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
    vector<vector<bool>> row = vector<vector<bool>>(9, vector<bool>(10, false));
    vector<vector<bool>> col = vector<vector<bool>>(9, vector<bool>(10, false));
    vector<vector<bool>> block = vector<vector<bool>>(9, vector<bool>(10, false));
    bool solved = false;

    void solveSudoku(vector<vector<char>>& board) {
        // 初始化 行/列/块 已使用的数字
        for (int i = 0; i < 9; ++i) {
            for (int j = 0; j < 9; ++j) {
                if (board[i][j] != '.') 
                    placeNum(board, i, j, board[i][j] - '0');
            }
        }
        // 从 (0,0) 位置开始按行搜索
        dfs(board, 0, 0);
    }

    void dfs(vector<vector<char>>& board, int x, int y) {
        // 已解决则可立即返回
        if (solved) return;
        // 因为是按行搜索，所以当行号越界时说明已经填完，即解决
        if (x == 9) {
            solved = true;
            return;
        }

        // 如果当前位置已有数字则搜索下一个位置
        // 列未越界，则 col + 1
        // 否则从下一行起始位置开始
        if (board[x][y] != '.') {
            if (y < 8) dfs(board, x, y + 1);
            else dfs(board, x + 1, 0);
        }
        // 如果无数字，则尝试填入数字
        else {
            for (int i = 1; i <= 9; ++i) {
                if (canPlace(x, y, i)) {
                    // 若数字符合要求，则尝试填入
                    placeNum(board, x, y, i);
                    // 然后尝试填下一位置
                    if (y < 8) dfs(board, x, y + 1);
                    else dfs(board, x + 1, 0);
                    // 如果返回时，问题仍未解决，说明该数字不符合要求，重置该位置
                    if (!solved) removeNum(board, x, y);
                }
            }
        }
    }

    bool canPlace(int i, int j, int x) {
        int b = (i / 3) * 3 + j / 3;
        return !row[i][x] && !col[j][x] && !block[b][x]; 
    }

    void placeNum(vector<vector<char>>& board, int i, int j, int x) {
        int b = (i / 3) * 3 + j / 3;
        row[i][x] = true;
        col[j][x] = true;
        block[b][x] = true;
        board[i][j] = x + '0';
    }

    void removeNum(vector<vector<char>>& board, int i, int j) {
        int b = (i / 3) * 3 + j / 3;
        int x = board[i][j] - '0';
        row[i][x] = false;
        col[j][x] = false;
        block[b][x] = false;
        board[i][j] = '.';
    }
};
```
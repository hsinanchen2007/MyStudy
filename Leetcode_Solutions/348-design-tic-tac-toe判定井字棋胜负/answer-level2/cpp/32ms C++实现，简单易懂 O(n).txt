### 解题思路
**核心思路：** 在玩家每次移动后，判断该位置所在的行和列是否达到获胜条件；如果该元素在主或副对角线上，判断对角线上是否达到获胜条件。

**优化：** 避免重复判断显然无法达到获胜条件的情况。

这里用到了6个成员变量：

```cpp
vector<vector<char>> board; // 记录n x n的网格
vector<char> symbols; // player 1 使用'X'，player 2使用'O'
vector<bool> row_state; // 记录每行的状态，如果'X'和'O'同时出现在某一行，则后续无需核验该行
vector<bool> col_state; // 记录每行的状态，如果'X'和'O'同时出现在某一列，则后续无需核验该列
bool d1; // 记录主对角线的状态，如果'X'和'O'同时出现，则后续无需核验主对角线
bool d2; // 记录副对角线的状态，如果'X'和'O'同时出现，则后续无需核验主副角线
```

初始化：

```cpp
explicit TicTacToe(int n)
            : board(vector<vector<char>>(n, vector<char>(n, ' '))),
              symbols({'X', 'O'}),
              row_state(vector<bool>(n, true)),
              col_state(vector<bool>(n, true)),
              d1{true},
              d2{true} {}
```

网格的每个cell均为空（使用`' '`表示），所有行、所有列、主对角线以及副对角线都有可能达到获胜条件，所以都为`true`。

### 代码

```cpp
class TicTacToe {
public:
    /** Initialize your data structure here. */
    explicit TicTacToe(int n)
            : board(vector<vector<char>>(n, vector<char>(n, ' '))),
              symbols({'X', 'O'}),
              row_state(vector<bool>(n, true)),
              col_state(vector<bool>(n, true)),
              d1{true},
              d2{true} {}

    /** Player {player} makes a move at ({row}, {col}).
        @param row The row of the board.
        @param col The column of the board.
        @param player The player, can be either 1 or 2.
        @return The current winning condition, can be either:
                0: No one wins.
                1: Player 1 wins.
                2: Player 2 wins. */
    int move(int row, int col, int player) {
        int n = board.size();
        char ch = symbols[player - 1];
        board[row][col] = ch;
        int i = 0;
        // check row {row}
        while (row_state[row] && i < n) {
            if (board[row][i] == ch) ++i;
            else {
                if (board[row][i] != ' ') {
                    row_state[row] = false;
                }
                break;
            }
        }
        if (i == n) return player;

        // check column {col}
        i = 0;
        while (col_state[col] && i < n) {
            if (board[i][col] == ch) i++;
            else {
                if (board[i][col] != ' ') {
                    col_state[col] = false;
                }
                break;
            }
        }
        if (i == n) return player;

        // check diagonal direction
        if (d1 && row == col) {
            i = 0;
            while (i < n) {
                if (board[i][i] == ch) {
                    i++;
                } else {
                    if (board[i][i] != ' ') {
                        d1 = false;
                    }
                    break;
                }
            }
            if (i == n) return player;
        }
        if (d2 && row + col == n - 1) {
            i = 0;
            while (i < n) {
                if (board[i][n - 1 - i] == ch) {
                    i++;
                } else {
                    if (board[i][n - 1 - i] != ' ') {
                        d2 = false;
                    }
                    break;
                }
            }
            if (i == n) return player;
        }

        return 0;
    }

private:
    vector<vector<char>> board;
    vector<char> symbols;
    vector<bool> row_state;
    vector<bool> col_state;
    bool d1;
    bool d2;
};
```

### 时间复杂度

`move`的时间复杂度为`O(n)`。
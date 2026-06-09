### 解题思路
思路详见代码前序注释

8ms 9.2M
--- wangtao HW-2020/2/29

### 代码

```cpp
class Solution {
public:
    /*
    思路：回溯法
    1、九宫格，其实可以看成9_row，9_col，9_box，每行每列以及每个格子内的数字不重复
    2、可以借用数组row[i][k]标识第i行的数字k是否存在，col[j][k]标识第j列数字k是否存在，box[n][k]标识第n的小9宫格中数字k是否存在
    3、按行遍历，每次检查列位能放置的数字，当列位放置失败时进行回溯重新放置，总是能成功的
    4、列位放置结束后进行下一行的处理，直到全部放完为止
    */

    bool sudokuDFS(vector<vector<char>>& board, vector<vector<int>>& row, vector<vector<int>>& col, vector<vector<int>>& box, int r, int c)
    {
        if (c == board[0].size()) {
            r++;
            c = 0;
            if (r == row.size()) {                
                return true;
            }
        }
        if (board[r][c] == '.') {
            for (int k = 1; k <= 9; k++) {
                // 检查i值是否能放在[r][c]位置
                int bi = (r / 3) * 3 + c / 3;
                if (row[r][k] == 0 && col[c][k] == 0 && box[bi][k] == 0) {
                    row[r][k] = 1;
                    col[c][k] = 1;
                    box[bi][k] = 1;
                    board[r][c] = (char)('0' + k);
                    if (true == sudokuDFS(board, row, col, box, r, c + 1)) {
                        return true;
                    } else {
                        row[r][k] = 0;
                        col[c][k] = 0;
                        box[bi][k] = 0;
                        board[r][c] = '.';
                    }
                }
            }
        } else {
            return sudokuDFS(board, row, col, box, r, c + 1);
        }
        return false;
    }

    void solveSudoku(vector<vector<char>>& board) {
        vector<vector<int>> row(9, vector<int>(10, 0));
        vector<vector<int>> col(9, vector<int>(10, 0));
        vector<vector<int>> box(9, vector<int>(10, 0));

        for (int i = 0; i < board.size(); i++) {
            for (int j = 0; j < board[0].size(); j++) {
                if (board[i][j] != '.') {
                    int k = board[i][j] - '0';
                    int bi = i / 3 * 3 + j / 3;
                    row[i][k] = 1;
                    col[j][k] = 1;
                    box[bi][k] = 1;
                }
            }
        }
        sudokuDFS(board, row, col, box, 0, 0);
    }
};
```
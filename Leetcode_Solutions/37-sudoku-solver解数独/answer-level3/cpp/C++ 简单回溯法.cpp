```
class Solution {
public:
    void backtrace(vector<vector<char>>& board,
            vector<vector<int> >& rows,
            vector<vector<int> >& cols,
            vector<vector<int> >& cells,
            int i, int j, bool& done,
            vector<vector<char>>& res) {
        if (done) return;
        if (i * 9 + j == 81) {
            done = true;
            res = board;
            return;
        }
        int k = i / 3 * 3 + j / 3;
        int t = i * 9 + j + 1;
        int r = t / 9;
        int c = t % 9;
        if (board[i][j] != '.') {
            backtrace(board, rows, cols, cells, r, c, done, res);
            return;
        }
        for (int u = 1; u <= 9; ++u) {
            if (rows[i][u] != 1 && cols[j][u] != 1 && cells[k][u] != 1) {
                rows[i][u] = cols[j][u] = cells[k][u] = 1;
                board[i][j] = u + '0';
                backtrace(board, rows, cols, cells, r, c, done, res);
                rows[i][u] = cols[j][u] = cells[k][u] = 0;
                board[i][j] = '.';
            }
        }
    }
    void solveSudoku(vector<vector<char>>& board) {
        const int N = 10;
        vector<vector<int> > rows(N, vector<int>(N, 0));
        vector<vector<int> > cols(N, vector<int>(N, 0));
        vector<vector<int> > cells(N, vector<int>(N, 0));
        for (int i = 0; i < 9; ++i) {
            for (int j = 0; j < 9; ++j) {
                if (board[i][j] == '.') continue;
                int n = board[i][j] - '0';
                int k = i / 3 * 3 + j / 3;
                cells[k][n] = 1;
                rows[i][n] = 1;
                cols[j][n] = 1;
            }
        }
        vector<vector<char> > res(board);
        bool done = false;
        backtrace(board, rows, cols, cells, 0, 0, done, res);
        swap(res, board);
    }
};
```


![image.png](https://pic.leetcode-cn.com/4ddc5d5836a3093b2c59a0122b937d215a02fbadb89b75f3ec37428397b55d15-image.png)

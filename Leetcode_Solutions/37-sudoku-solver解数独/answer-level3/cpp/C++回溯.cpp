***Talk is cheap. Show me the code.***

```cpp
class Solution {
public:
    void solveSudoku(vector<vector<char>>& board) {
        // 每行每列每块都不能有重复数字，用三个表哈希
        vector<vector<bool>> RowHash(9, vector<bool>(10, false));
        vector<vector<bool>> ColHash(9, vector<bool>(10, false));
        vector<vector<bool>> BoxHash(9, vector<bool>(10, false));
        vector<pair<int, int>> pos;    // 记录需要填数字的位置
        bool isFinished = false;

        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                if (board[i][j] != '.') {
                    int num = board[i][j] - '0';
                    RowHash[i][num] = true;
                    ColHash[j][num] = true;
                    BoxHash[i / 3 * 3 + j / 3][num] = true;
                } else {
                    pos.emplace_back(i, j);
                }
            }
        }

        backtrack(board, RowHash, ColHash, BoxHash, pos, isFinished, 0);
    }

    void backtrack(vector<vector<char>>& board,
                   vector<vector<bool>>& RowHash,
                   vector<vector<bool>>& ColHash,
                   vector<vector<bool>>& BoxHash,
                   vector<pair<int, int>>& pos, bool &isFinished, int round) {
        if (round == pos.size()) {
            isFinished = true;
            return;
        }
        int row = pos[round].first;
        int col = pos[round].second;
        int box = row / 3 * 3 + col / 3;
        for (int i = 1; i <= 9; i++) {
            if (!RowHash[row][i] && !ColHash[col][i] &&
                !BoxHash[box][i]) {
                RowHash[row][i] = true;
                ColHash[col][i] = true;
                BoxHash[box][i] = true;
                board[row][col] = '0' + i;
                backtrack(board, RowHash, ColHash, BoxHash, pos, isFinished, round + 1);
                if (isFinished) return;    // 找到一个解就行了
                RowHash[row][i] = false;
                ColHash[col][i] = false;
                BoxHash[box][i] = false;
            }
        }
    }
};

```
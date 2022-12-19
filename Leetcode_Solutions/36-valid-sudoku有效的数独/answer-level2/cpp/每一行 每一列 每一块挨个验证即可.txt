class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        if (board.size() != 9 || board[0].size() != 9) return false;
        vector<bool> visited(9, false);
        for (int i = 0; i < size; ++i) {  // 验证每一行
            fill(visited.begin(), visited.end(), false);
            for (int j = 0; j < size; ++j) {
                if (board[i][j] == '.') continue;
                if (!visited[board[i][j] - '1']) visited[board[i][j] - '1'] = true;
                else return false;
            }
        }
        for (int j = 0; j < size; ++j) {  // 验证每一列
            fill(visited.begin(), visited.end(), false);
            for (int i = 0; i < size; ++i) {
                if (board[i][j] == '.') continue;
                if (!visited[board[i][j] - '1']) visited[board[i][j] - '1'] = true;
                else return false;
            }
        }
        for (int i = 0; i < size / 3; ++i) {  // 验证每一块
            for (int j = 0; j < size / 3; ++j) {
                fill(visited.begin(), visited.end(), false);
                for (int ii = 0; ii < 3; ++ii) {
                    for (int jj = 0; jj < 3; ++jj) {
                        if (board[i * 3 + ii][j * 3 + jj] == '.') continue;
                        if (!visited[board[i * 3 + ii][j * 3 + jj] - '1']) visited[board[i * 3 + ii][j * 3 + jj] - '1'] = true;
                        else return false;
                    }
                }
            }
        }
        return true;
    }
private:
    int size = 9;
};
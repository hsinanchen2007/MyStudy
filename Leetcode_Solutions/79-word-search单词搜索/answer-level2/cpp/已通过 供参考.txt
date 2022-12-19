class Solution {
    void existHelper(vector<vector<char>>& board, const std::string& word, int cur, int i, int j, bool& r) {
        if (cur >= word.size()) r = true;
        else {
            if (i < 0 || i >= board.size() || j < 0 || j >= board.back().size() || word[cur] != board[i][j]) return;
            int tmp = board[i][j];
            board[i][j] = '#';
            existHelper(board, word, 1+cur, i-1, j, r);
            if (r) return;  // 这里不减 会超时 以下同理
            existHelper(board, word, 1+cur, i+1, j, r);
            if (r) return;
            existHelper(board, word, 1+cur, i, j-1, r);
            if (r) return;
            existHelper(board, word, 1+cur, i, j+1, r);
            board[i][j] = tmp;
        }
    }
    bool exist(vector<vector<char>>& board, string word) {
        for (int i = 0; i < board.size(); ++i) {
            for (int j = 0; j < board.back().size(); ++j) {
                if (board[i][j] != word[0]) continue; // 这里也减以下 影响不大
                bool r = false;
                existHelper(board, word, 0, i, j, r);
                if (r) return true;
            }
        }
        return false;
    }
}


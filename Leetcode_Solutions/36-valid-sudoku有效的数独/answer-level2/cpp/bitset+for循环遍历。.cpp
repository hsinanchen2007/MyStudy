```
class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        int n = board.size();
        vector<bitset<9>> rows(n);
        vector<bitset<9>> cols(n);
        vector<bitset<9>> sb(n);
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                int value = board[i][j] - '1';
                if (value < 0 || value > 8) {
                    continue;
                }
                
                int sbIndex = i / 3 * 3 + j / 3;
                if (!rows[i][value] && !cols[j][value] && !sb[sbIndex][value]) {
                    rows[i][value] = true;
                    cols[j][value] = true;;
                    sb[sbIndex][value] = true;;
                } else {
                    return false;
                }
            }
        }
        return true;
    }
}; 

```

代码简单易懂

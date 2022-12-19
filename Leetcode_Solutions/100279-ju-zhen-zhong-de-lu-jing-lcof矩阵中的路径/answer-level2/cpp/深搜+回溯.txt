```cpp
int x[] = {-1,0,0,1};
int y[] = {0,-1,1,0};
class Solution {
public:
    int row,col;
    bool dfs(vector<vector<char>>& board,string word,int i,int j,int idx) {
        if (idx == word.size()) return true;
        char tmp = board[i][j];
        board[i][j] = '.';
        for (int k = 0; k < 4; k++) {
            int d_x = x[k] + i;
            int d_y = y[k] + j;
            if (d_x >= 0 && d_x < row && d_y >= 0 && d_y < col && word[idx] == board[d_x][d_y]) {
                if (dfs(board,word,d_x,d_y,idx + 1)) return true;
            }
        }
        board[i][j] = tmp;
        return false;
    }
    bool exist(vector<vector<char>>& board, string word) {
        row = board.size();
        col = board[0].size();
        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {
                if (board[i][j] == word[0]) {
                    if (dfs(board,word,i,j,1)) return true;
                }
            }
        }
        return false;
    }
};

```
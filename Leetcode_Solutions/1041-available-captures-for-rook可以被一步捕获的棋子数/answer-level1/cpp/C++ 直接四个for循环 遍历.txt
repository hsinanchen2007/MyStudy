```
class Solution {
    int cnt = 0;
public:
    int numRookCaptures(vector<vector<char>>& board) {
        int row, col;
        for(int i=0; i<8; i++)
            for(int j=0; j<8; j++)
                if(board[i][j] == 'R')
                {
                    row = i, col = j;
                }
        // dfs(board, row, col);
        for(int i=row; i>=0;)
        {
            if(board[i][col] != 'B')
            {
                if(board[i][col] == 'p')
                {
                    cnt++;
                    break;
                }
                else{
                    i--;
                }
            }
            else break;
        }
        for(int i=row; i<8;)
        {
            if(board[i][col] != 'B')
            {
                if(board[i][col] == 'p')
                {
                    cnt++;
                    break;
                }
                else{
                    i++;
                }
            }
            else break;
        }
        for(int i=col; i>=0;)
        {
            if(board[row][i] != 'B')
            {
                if(board[row][i] == 'p')
                {
                    cnt++;
                    break;
                }
                else{
                    i--;
                }
            }
            else break;
        }
        for(int i=col; i<8;)
        {
            if(board[row][i] != 'B')
            {
                if(board[row][i] == 'p')
                {
                    cnt++;
                    break;
                }
                else{
                    i++;
                }
            }
            else break;
        }
        return cnt;
    }
};
```

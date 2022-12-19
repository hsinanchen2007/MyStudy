注意题目的p是小写...找了半天
```
class Solution {
public:
    int numRookCaptures(vector<vector<char>>& board) {
        int size = board.size();
        int r = -1, c = -1;
        for(int i = 0; i < size; i++)
        {
            for(int j = 0; j < size; j++)
            {
                if(board[i][j] == 'R')
                {
                    r = i;
                    c = j;
                    break;
                }
            }
            if(r != -1)
                break;
        }
        int count = 0;
        int flag = 0;
        for(int i = r; i >= 0; i--)
        {
            if(board[i][c] == 'p')
            {
                count++;
                break;
            }
            if(board[i][c] == 'B')
                break;
        }
        for(int i = r; i < size; i++)
        {
            if(board[i][c] == 'p')
            {
                count++;
                break;
            }
            else if(board[i][c] == 'B')
                break;
        }
        for(int i = c; i >= 0; i--)
        {
            if(board[r][i] == 'p')
            {
                count++;
                break;
            }
            else if(board[r][i] == 'B')
                break;
        }
        for(int i = c; i < size; i++)
        {
            if(board[r][i] == 'p')
            {
                count++;
                break;
            }
            else if(board[r][i] == 'B')
                break;
        }
        return count;
    }
};
```
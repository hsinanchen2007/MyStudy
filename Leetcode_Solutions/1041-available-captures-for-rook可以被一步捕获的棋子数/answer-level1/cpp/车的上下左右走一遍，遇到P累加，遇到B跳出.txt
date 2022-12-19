### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
    int numRookCaptures(vector<vector<char>>& board) {
        int row = board.size();
        int col = board[0].size();
        int ri,rj;
        int cnt = 0;
        char x;
        for(int i = 0;i<row;i++)
        {
            for(int j=0;j<col;j++)
            {  
                x = board[i][i];
                if(board[i][j] == 'R')
                {
                    ri = i;
                    rj = j;
                }
            }
        }
        for(int i = ri;i>=0;i--)
        {
            if(board[i][rj] == 'p')
            {
                cnt++;
                break;
            }
            else if(board[i][rj] == 'B')
            {
                break;
            }
        }

        for(int i = ri;i<row;i++)
        {
            if(board[i][rj] == 'p')
            {
                cnt++;
                break;
            }
            else if(board[i][rj] == 'B')
            {
                break;
            }

        }
        for(int j=rj;j>=0;j--)
        {
            if(board[ri][j] == 'p')
            {
                cnt++;
                break;
            }
            else if(board[ri][j] == 'B')
            {
                break;
            }
        }
        for(int j=rj;j<col;j++)
        {
            if(board[ri][j] == 'p')
            {
                cnt++;
                break;
            }
            else if(board[ri][j] == 'B')
            {
                break;
            }
        }
        return cnt;
    }
};
```
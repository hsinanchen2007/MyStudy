### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
    int numRookCaptures(vector<vector<char>>& board) {
        int m=board.size();
        if(m==0) return 0;
        int n=board[0].size();
        if(n==0) return 0;

        for(int i=0; i<m;  ++i)
        {
            for(int j=0; j<n; ++j)
            {
                if(board[i][j]=='R')  return capture(i,j,board);
            }
        }

        return 0;
    }

    int capture(int row, int col, vector<vector<char>>& board)
    {
        int m=board.size(), n=board[0].size();
        int capture_count=0;
        for(int i=row; i>=0; --i)
        {
            if(board[i][col]=='B') break;
            if(board[i][col]=='p')
            {
                capture_count++;
                break;
            }
        }
        for(int i=row; i<m; ++i)
        {
            if(board[i][col]=='B') break;
            if(board[i][col]=='p')
            {
                capture_count++;
                break;
            }
        }
        for(int j=col; j>=0; --j)
        {
            if(board[row][j]=='B') break;
            if(board[row][j]=='p')
            {
                capture_count++;
                break;
            }
        }
        for(int j=col; j<n; ++j)
        {
            if(board[row][j]=='B') break;
            if(board[row][j]=='p')
            {
                capture_count++;
                break;
            }
        }

        return capture_count;
    }
};
```
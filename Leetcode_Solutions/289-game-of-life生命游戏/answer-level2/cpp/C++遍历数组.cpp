### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
    int m;
    int n;
    int dir_x[8]={-1,-1,0,1,1,1,0,-1};
    int dir_y[8]={0,1,1,1,0,-1,-1,-1};

    void gameOfLife(vector<vector<int>>& board) {
        m=board.size();
        if(m==0) return;
        n=board[0].size();
        if(n==0) return;

        vector<vector<int>> board_next(m,vector<int>(n,0));

        for(int i=0; i<m; ++i)
        {
            for(int j=0; j<n; ++j)
            {
                int count_live=0;
                for(int k=0; k<8; ++k)
                {
                    int row=i+dir_x[k], col=j+dir_y[k];
                    if(inScope(row,col))
                    {
                        if(board[row][col]==1) count_live++;
                    }
                }
                if(count_live<2) board_next[i][j]=0;
                else if(count_live==2)
                {
                    board_next[i][j]=board[i][j];
                }
                else if(count_live==3)
                {
                    board_next[i][j]=1;
                }
                else
                {
                    board_next[i][j]=0;
                }
            }
        }

        for(int i=0; i<m; ++i)
        {
            for(int j=0; j<n; ++j)
            {
                board[i][j]=board_next[i][j];
            }
        }

        return;

    }

    bool inScope(int row, int col)
    {
        return (row>=0 && row<m && col>=0 && col<n);
    }
};
```
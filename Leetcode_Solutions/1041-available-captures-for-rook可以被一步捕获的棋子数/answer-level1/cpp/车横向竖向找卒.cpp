### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
    int numRookCaptures(vector<vector<char>>& board) {
        int R_x = -1;
        int R_y = -1;
        for(int i=0;i<board.size();i++)
        {
            for(int j=0;j<board[i].size();j++)
            {
                if(board[i][j] == 'R')
                {
                    R_x = j;
                    R_y = i;
                    break;
                }
            }
        }

        if(R_x == -1)
            return 0;
        
        int count = 0;
        for(int x=R_x;x>=0;x--)
        {
            if(board[R_y][x] == 'p')
            {
                count ++;
                break;
            }
            else if(board[R_y][x] == 'B')
            {
                break;
            }
            
        }
        for(int x=R_x;x<8;x++)
        {
            if(board[R_y][x] == 'p')
            {
                count ++;
                break;
            }
            else if(board[R_y][x] == 'B')
            {
                break;
            }
            
        }
        for(int y=R_y;y>=0;y--)
        {
            if(board[y][R_x] == 'p')
            {
                count ++;
                break;
            }
            else if(board[y][R_x] == 'B')
            {
                break;
            }
            
        }
        for(int y=R_y;y<8;y++)
        {
            if(board[y][R_x] == 'p')
            {
                count ++;
                break;
            }
            else if(board[y][R_x] == 'B')
            {
                break;
            }
            
        }

        return count;
    }
};
```
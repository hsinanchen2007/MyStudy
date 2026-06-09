### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
    void search4Director(vector<vector<char>>& board, int x, int y, int& count, int exclude)
    {
        //四个方向
        int tempX = x;
        int tempY = y;
        while(exclude!= 0 && --tempX >= 0)
        {
            if(board[tempX][y] == 'p')
            {
                ++count;
                board[tempX][y] = '.';
                // search4Director(board, tempX, y, count, 1);
                break;
            }
            else if (tempX == 0)
            {
                // search4Director(board, tempX, y, count, 1);
            }
            else if(board[tempX][y] == 'B')
            {
                break;
            }
        }

        tempX = x;
        while(exclude!= 1 && ++tempX < 8)
        {
            if(board[tempX][y] == 'p')
            {
                ++count;
                board[tempX][y] = '.';
                // search4Director(board, tempX, y, count, 0);
                break;
            }
            else if (tempX == 7)
            {
                // search4Director(board, tempX, y, count, 0);
            }
            else if(board[tempX][y] == 'B')
            {
                break;
            }
        }

        while(exclude!= 2 && --tempY >= 0)
        {
            if(board[x][tempY] == 'p')
            {
                ++count;
                board[x][tempY] = '.';
                // search4Director(board, x, tempY, count, 3);
                break;
            }
            else if (tempY == 0)
            {
                // search4Director(board, x, tempY, count, 3);
            }
            else if(board[x][tempY] == 'B')
            {
                break;
            }
        }

        tempY = y;
        while(exclude!= 3 && ++tempY < 8)
        {
            if(board[x][tempY] == 'p')
            {
                ++count;
                board[x][tempY] = '.';
                // search4Director(board, x, tempY, count, 2);
                break;
            }
            else if (tempY == 7)
            {
                // search4Director(board, x, tempY, count, 2);
            }
            else if(board[x][tempY] == 'B')
            {
                break;
            }
        }
    }

    int numRookCaptures(vector<vector<char>>& board) {
        int count = 0;
        for(int i = 0; i < 8; i++)
        {
            for(int j = 0; j < 8; j++)
            {
                if(board[i][j] == 'R')
                {
                    search4Director(board, i, j, count, -1);
                    break;
                }
            }
        }
        return count;
    }

};
```
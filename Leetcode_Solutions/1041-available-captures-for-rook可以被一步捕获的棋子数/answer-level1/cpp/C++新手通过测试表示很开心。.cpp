### 解题思路
在vs调试初始化的时候，学习了二维的vector，以及各种debug。

思路就是 找到车R，然后用R的横纵坐标从4个方向扫描，满足条件count变量加一，跳出。 撞墙上或者撞象上了就直接跳出。

### 代码

```cpp
class Solution {
public:
    int numRookCaptures(vector<vector<char>>& board) {
        int count = 0;
        int x,y,i,j;
        for(int i = 0;i < board.size();i++ )
        {
            for(int j = 0;j < board[i].size();j++ )
            {
                if(board.at(i).at(j) == 'R')
                { 
				   x = i;
                   y = j;
				}
            }
        }

        j = y;
        while(j > 0)
        {
            j --;
            if(board[x][j] == 'B' )
                break;
            else if(board[x][j] == 'p')
            {
               count++;
                break;
            }
        }
       
        j = y;
        while(j < 7)
        {
            j ++;
            if(board[x][j] == 'B' )
                break;
            else if(board[x][j] == 'p')
            {
                count++;
                break;
            }
        }

        i = x;
        while(i > 0)
        {
            i --;
            if(board[i][y] == 'B' )
                break;
            else if(board[i][y] == 'p')
            {
               count++;
                break;
            }
        }

        i = x;
        while(i < 7)
        {
            i ++;
            if(board[i][y] == 'B' )
                break;
            else if(board[i][y] == 'p')
            {
                count++;
                break;
            }
        }
        return count;
    }
};
```
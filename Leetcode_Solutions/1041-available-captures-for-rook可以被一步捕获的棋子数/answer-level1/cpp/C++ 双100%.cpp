
### 代码

```cpp
class Solution {
public:
    int numRookCaptures(vector<vector<char>>& board) {
        int count = 0;
        int x,y;
        //先找到车，分别在四个方向上找颜色相反的卒，
        //如果找到反色的卒，计数加一；如果到达边界或者碰到象，停止寻找；
        for(int i = 0;i < board.size();++i)
        {
            auto pos = find(board[i].begin(),board[i].end(),'R');
            if(pos != board[i].end())
            {
                x = i;
                y = pos-board[i].begin();
            }
        }
        //上       
        for(int i = y;i>=0;--i)
        {
            if(board[x][i]=='B')
                break;
            else if(board[x][i] == 'p')
            {
                count++;
                break;
            }
        }
        //下
        for(int i = y;i<board.size();++i)
        {
            if(board[x][i]=='B')
                break;
            else if(board[x][i] == 'p')
            {
                count++;
                break;
            }
        }
        //左
        for(int i = x;i>=0;--i)
        {
            if(board[i][y]=='B')
                break;
            else if(board[i][y] == 'p')
            {
                count++;
                break;
            }
        }
        //右
        for(int i = x;i < board[x].size();++i)
        {
            if(board[i][y]=='B')
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
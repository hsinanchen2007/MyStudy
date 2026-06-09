### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
    bool validTicTacToe(vector<string>& board) {
        int c = 0;
        int x = 0;
        int cc = 0;
        int xx = 0;
        for (int i=0; i<board.size(); i++)
        {
             if (board[i]=="XXX")
               xx = xx + 1;
             if (board[i] == "OOO")
               cc = cc + 1;
             if (board[0][i] == 'O' && board[1][i] == 'O' && board[2][i] == 'O')
                cc = cc + 1;
             if (board[0][i]== 'X' && board[1][i] == 'X' && board[2][i] == 'X')
                xx = xx + 1;
             for (int j=0; j<board[i].length(); j++)
             {
               if (board[i][j] == 'X')
                  x++;
               if (board[i][j] == 'O')
                  c++;
             }
        }
        if (board[0][0] == 'X' && board[1][1] == 'X' && board[2][2] == 'X')
            xx =  xx + 1;
        if (board[0][0] == 'O' && board[1][1] == 'O' && board[2][2] == 'O')
            cc =  cc + 1;
        if (board[0][2] == 'O' && board[1][1] == 'O' && board[2][0] == 'O')
            cc =  cc + 1;
        if (board[0][2] == 'X' && board[1][1] == 'X' && board[2][0] == 'X')
            xx =  xx + 1;
        if (c-x<=-2 || c-x>2 || (c>0 && x==0) || (cc > 0 && xx > 0) || (xx>0 && c == x)||(cc>0 && x>c) || (xx>0 && c>x) || c>x)
            return false; 
        return true;
    }
};
```
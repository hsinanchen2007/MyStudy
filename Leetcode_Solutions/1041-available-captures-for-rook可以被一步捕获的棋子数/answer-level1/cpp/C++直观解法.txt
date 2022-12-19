执行用时 :
0 ms
, 在所有 C++ 提交中击败了
100.00%
的用户
内存消耗 :
8.3 MB
, 在所有 C++ 提交中击败了
85.17%
的用户
```
class Solution {
public:
    int numRookCaptures(vector<vector<char>>& board) {
        //找出R的位置
        int x,y;
        for(int i=0;i<board.size();i++)
            for(int j=0;j<board[i].size();j++)
                if(board[i][j]=='R')
                {
                    x=i;y=j;
                }
        int sum=0;
        //向北遍历
        for(int i=x;i<8;i++)
        {
            if(board[i][y]=='B')break;
            if(board[i][y]=='p'){
                sum++;break;
            }
        }
        //向南遍历
        for(int i=x;i>=0;i--)
        {
            if(board[i][y]=='B')break;
            if(board[i][y]=='p'){
                sum++;break;
            }
        }
        //向东遍历
        for(int j=y;j<8;j++)
        {
           if(board[x][j]=='B')break;
            if(board[x][j]=='p')
            {
                sum++;break;
            }
        }
        //向西遍历
        for(int j=y;j>=0;j--)
        {
           if(board[x][j]=='B')break;
            if(board[x][j]=='p')
            {
                sum++;break;
            }
        }
         return sum;   
    }
};
```


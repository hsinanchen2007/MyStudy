### 解题思路
思路：题目意思可以理解为，将四周的'O'及其连通的'O'不变（将这种情况的'O'标记为一个其他的字符,下面用的是'-'），其余的'O'变成'X'，接着扫描完后，遍历二维数组，判断其是什么字符，再将其修改成对应的情况，代码如下
### 代码

```cpp
class Solution {
public:
    int row,col;
    void solve(vector<vector<char>>& board) {
        if(board.size()==0) return;
        row=board.size();
        col=board[0].size();
        for(int i=0;i<row;i++){        //遍历第一列和最后一列
            dfs(board,i,0);
            dfs(board,i,col-1);
        }
        for(int j=0;j<col;j++){         //遍历第一行和最后一行
            dfs(board,0,j);
            dfs(board,row-1,j);
        }
        //经过上面的处理后，不符合的'O'全部会变为'-'
        for(int i=0;i<row;i++){
            for(int j=0;j<col;j++){
                if(board[i][j]=='O'){
                    board[i][j]='X';
                }
                if(board[i][j]=='-'){
                    board[i][j]='O';
                }
            }
        }
    }
    void dfs(vector<vector<char>>& board,int x,int y){
        if(x>=0 && y>=0 && x<row && y<col &&board[x][y]=='O'){
            board[x][y]='-';
            //上右下左
            dfs(board,x-1,y);
            dfs(board,x,y+1);
            dfs(board,x+1,y);
            dfs(board,x,y-1);
        }
    }
};
```
### 解题思路
对边界上所有为'O'的进行dfs ，把所有与之相邻的也是O的先改成其他字符，
再对 board进行遍历 则所有的O即需要保留的
再次遍历把其他字符改成X即可

时间50 空间100 这种是最容易想到的方法，还可以优化，偷个懒
 
RE两次 ，第一次没判空，第二次判空放错了位置，太菜了
### 代码

```cpp
class Solution {
public:
   int line,col;
   int mov[4][2]={0,1,1,0,0,-1,-1,0};
    void solve(vector<vector<char>>& board) {
       col=board.size();
             if(col==0) return ;
        line=board[0].size();

      for(int i=0;i<line;i++){
             if(board[0][i]=='O') dfs(board,0,i);
             if(board[col-1][i]=='O') dfs(board,col-1,i);
      }
       for(int i=0;i<col;i++){
             if(board[i][0]=='O') dfs(board,i,0);
             if(board[i][line-1]=='O') dfs(board,i,line-1);
      }
      for(int i=0;i<col;i++){
          for(int j=0;j<line;j++){
              if(board[i][j]=='O') board[i][j]='X';
          }
      }
        for(int i=0;i<col;i++){
          for(int j=0;j<line;j++){
              if(board[i][j]=='m') board[i][j]='O';
          }
      }
      return ;
    }
    void dfs(vector<vector<char>>& board,int x,int y){
        board[x][y]='m';
        for(int i=0;i<4;i++){
            int sx=x+mov[i][0];
            int sy=y+mov[i][1];
            if(sx>=0&&sx<col&&sy>=0&&sy<line&&board[sx][sy]=='O'){
                board[sx][sy]='m';
                dfs(board,sx,sy); 
            }
        }
        return ;
    }
};
```
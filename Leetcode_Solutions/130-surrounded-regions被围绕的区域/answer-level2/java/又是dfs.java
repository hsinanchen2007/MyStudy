### 解题思路
此处撰写解题思路
读懂题目很关键
找到这题的出口，就是找不能变为x的o；
只要从四个边边开始深度搜索，将搜索到的o全部置为t,搜索完成后，再遍历一遍整个矩阵，根据是o还是t，来判断是否要变成x;
### 代码

```java
class Solution {
    private int m,n;
    private int[][]move={{0,1},{0,-1},{1,0},{-1,0}};
    public void solve(char[][] board) {
        if(board==null||board.length==0) return;
         m=board.length;
         n=board[0].length;
         for(int i=0;i<m;i++){
             dfs(board,i,0);
             dfs(board,i,n-1);
         }
         for(int i=0;i<n;i++){
             dfs(board,0,i);
             dfs(board,m-1,i);
         }
         for(int i=0;i<m;i++){
             for(int j=0;j<n;j++){
                 if(board[i][j]=='T')
                 board[i][j]='O';
                 else if(board[i][j]=='O')
                 board[i][j]='X';
             }
         }
    }
    private void dfs(char[][]board,int a,int b){
        if(a<0||a>=m||b<0||b>=n||board[a][b]!='O') return;
        board[a][b]='T';
        for(int i=0;i<4;i++){
            dfs(board,a+move[i][0],b+move[i][1]);
        }
    }
}
```
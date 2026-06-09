### 解题思路
此处撰写解题思路
注意坐标变化的书写
### 代码

```java
class Solution {
    public int numRookCaptures(char[][] board) {
        int length=board.length;
        if(length==0) return 0;
        for(int i=0;i<length;i++){
            for(int j=0;j<board[0].length;j++){
                if(board[i][j]=='R'){
                    return cat(board,i,j,1,0)+cat(board,i,j,-1,0)+cat(board,i,j,0,1)+cat(board,i,j,0,-1);
                }
            }
        }
        return 0;

    }
    public int cat(char[][]board,int x,int y,int dx,int dy){
        while(inBoard(board,x,y)&&board[x][y]!='B'){
            if(board[x][y]=='p') return 1;//找到了就返回1.
            x+=dx;
            y+=dy;
        }
        return 0;
    }
    public boolean inBoard(char[][] board, int x, int y){
        return x>=0&&x<board.length&&y>=0&&y<board[x].length;
    }
}
```
### 解题思路
先找到 “R” 的位置
然后分别探索 “R” 的上下左右能吃掉多少个 “p”。


### 代码

```java
class Solution {
    public int numRookCaptures(char[][] board) {

        if(board.length<=0 || board[0].length<=0){
            return 0;
        }

        int x=0;
        int y=0;

        // 先找到 rook
        for(int i=0;i<board.length;i++){
            for(int j=0;j<board[i].length;j++){
                if(board[i][j]=='R'){
                    x=i;
                    y=j;
                    break;
                }
            }
        }

        int countLeft = left(board,x,y);
        int countRight = right(board,x,y);
        int countTop = top(board,x,y);
        int countBottom = bottom(board,x,y);

        return countLeft + countRight + countTop + countBottom;

    }

    public int left(char[][] board,int x,int y){
        // 左，y--
        while(y>=0){
            if(board[x][y] == 'B'){
                return 0;
            }
            if(board[x][y] == 'p'){
                return 1;
            }
            y--;
        }
        return 0;
    }

    public int right(char[][] board,int x,int y){
        // 右，y++
        while(y<board[x].length){
            if(board[x][y] == 'B'){
                return 0;
            }
            if(board[x][y] == 'p'){
                return 1;
            }
            y++;
        }
        return 0;
    }

    public int top(char[][] board,int x,int y){
        // 上，x--
        while(x>=0){
            if(board[x][y] == 'B'){
                return 0;
            }
            if(board[x][y] == 'p'){
                return 1;
            }
            x--;
        }
        return 0;
    }

    public int bottom(char[][] board,int x,int y){
        // 下，x++
        while(x<board.length){
            if(board[x][y] == 'B'){
                return 0;
            }
            if(board[x][y] == 'p'){
                return 1;
            }
            x++;
        }
        return 0;
    }
}
```
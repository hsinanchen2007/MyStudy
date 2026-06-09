### 解题思路
题目的解法并不难，主要的问题是需要读懂题目。看似是需要国际象棋的知识，其实并不难懂，整个棋盘中只有三个棋子，而我们需要知道的仅仅是“白色车”这个棋子的运动方式。
仔细研究即可知道，白方车遇到白方象，停下来，不能再捕获黑卒。白方车遇到黑房卒，停下来，并进行捕获，简单的是只有四个方向可以运动，简单分析可得以下代码

### 代码

```java
class Solution {
    public int numRookCaptures(char[][] board) {
        int sum=0;
        int x=0,y=0;
//定位白车位置
        for(int i=0;i<board.length;i++){
            for(int j=0;j<board[i].length;j++){
                if(board[i][j]=='R') {
                    x=i;
                    y=j;
                }
            }
        }
//北方向运动
        for(int i=x;i<8;i++){
            if(board[i][y]=='B') break;
            if(board[i][y]=='p'){
                sum++;
                break;
            }
        }
//南方向运动
        for(int i=x;i>=0;i--){
            if(board[i][y]=='B') break;
            if(board[i][y]=='p'){
                sum++;
                break;
            }
        }
//东方向运动
        for(int j=y;j<8;j++){
            if(board[x][j]=='B') break;
            if(board[x][j]=='p'){
                sum++;
                break;
            }
        }
//西方向运动
        for(int j=y;j>=0;j--){
            if(board[x][j]=='B') break;
            if(board[x][j]=='p'){
                sum++;
                break;
            }
        }
        return sum;
    }
}
```
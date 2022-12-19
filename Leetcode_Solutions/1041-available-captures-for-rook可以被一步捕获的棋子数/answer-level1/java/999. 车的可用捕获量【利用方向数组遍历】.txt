### 解题思路
    （1）先遍历找到白色车；
    （2）再以白色车所在位置，分别向四个方向移动：
        a、如果遇到 . （表示空格）就可以继续朝同一个方向前进，直到不能再走为止（到达边缘）；
        b、如果遇到 B (白色的象）就停止找，因为车不能与其他友方（白色）象进入同一个方格；
        c、如果遇到 p（黑色的卒） 说明找到了，停止，计数加一。

### 代码

```java
class Solution {
    public int numRookCaptures(char[][] board) {
        int row = board.length;
        int col = board[0].length;
        int m=0,n=0;
        int count = 0;
        int[] dx = {0,1,0,-1};
        int[] dy = {1,0,-1,0};
        for(int i=0;i<row;i++){
            for(int j=0;j<col;j++){
                if(board[i][j] == 'R'){
                    m = i;
                    n = j;
                }
            }
        }
        //分别从四个方向遍历判断
        for(int i=0;i<4;i++){
            int tx = m,ty = n;
            while(true){
                tx += dx[i];
                ty += dy[i];
                if(tx < 0 || tx >= 8 || ty < 0 || ty >= 8 || board[tx][ty] == 'B'){
                    break;
                }
                if(board[tx][ty] == 'p'){
                    count++;
                    break;
                }
            }
        }
        return count;
    }
}
```
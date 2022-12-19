### 解题思路
根据题意，棋盘中只有一个车,先找出它的位置，并在该位置的东南西北四个方向上搜索，若先遇到白象则该方向搜索结束，若先遇到小卒，则记录个数，根据题意可知小卒的个数在每个方向上只用记录一次。

### 代码

```java
class Solution {
    public int numRookCaptures(char[][] board) {
        int m = 8, i = 0, j = 0 ,count = 0;
        int[][] direction = {{-1,0},{1,0},{0,1},{0,-1}};
        boolean flag = false;
        for (i = 0; i < m; i++) {
            for (j = 0; j < m; j++) {
                if(board[i][j] == 'R') {
                    flag = true;
                    break;
                }
            }
            if(flag == true) break;
        }
        for (int k = 0; k < 4; k++) {
            int x = i, y = j;
            while(true) {
                x += direction[k][0];
                y += direction[k][1];
                if(!judge(x,y,m)) break;
                if(board[x][y]=='B') {
                    break;
                } else if(board[x][y] == 'p') {
                    count++;
                    break;
                }
            }
        }
        return count;
    }

    public boolean judge(int x, int y, int m) {
        return x>=0 && x<m && y>=0 && y<m;
    }
}
```
### 解题思路
这题没有弯弯绕，个人认为主要在考察使用循环语句和条件语句的熟练度（狗头
1. 先找到车的位置
2. 以车为中心，沿上下左右四个方向寻找
- 如果出界或遇到友方棋子，则退出
- 如果遇到反方卒，则总数+1，退出
3. 返回总数

### 代码

```java
class Solution {
    public int numRookCaptures(char[][] board) {
        for(int i=0; i<8; i++) {
            for(int j=0; j<8; j++) {
                if(board[i][j] == 'R') {
                    return capture(board, i, j);
                }
            }
        }
        return 0;
    }

    public int capture(char[][] board, int x, int y) {
        int sum = 0;
        int[] dx = {0, 0, 1, -1};
        int[] dy = {1, -1, 0, 0};
        for(int i=0; i<4; i++) {
            int xx = x;
            int yy = y;
            while(true) {
                xx += dx[i];
                yy += dy[i];
                if(xx<0 || xx>=8 || yy<0 || yy>=8 || board[xx][yy] == 'B') {
                    break;
                } else if(board[xx][yy] == 'p') {
                    sum += 1;
                    break;
                }
            }
        }
        return sum;
    }
}
```
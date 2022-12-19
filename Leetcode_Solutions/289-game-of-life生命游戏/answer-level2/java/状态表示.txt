### 解题思路
看到原地解决就想用原数据保存状态，2表示死变活，3表示活变死，这样对2取模就能知道原来的状态（从机器码来看有点位运算的意思）

### 代码

```java
class Solution {
    public void gameOfLife(int[][] board) {
        int[] d1 = new int []{1,1,1,-1,-1,-1,0,0};
        int[] d2 = new int []{-1,0,1,0,1,-1,1,-1};
        for(int i = 0; i < board.length; i++)
        {
            for(int j = 0; j < board[0].length; j++)
            {
                int alive = 0;
                for(int k = 0; k < 8; k++)
                {
                    int xx = i + d1[k], yy = j + d2[k];
                    if(xx >= 0 && yy >= 0 && xx < board.length && yy < board[0].length && board[xx][yy] % 2 == 1)
                        ++alive;
                }
                // 死变活
                if(board[i][j] == 0 && alive == 3)
                    board[i][j] = 2;
                // 活变死
                else if(board[i][j] == 1 && (alive < 2 || alive > 3))
                    board[i][j] = 3;
            }
        }
        for(int i = 0; i < board.length; i++)
            for(int j = 0; j < board[0].length; j++)
            {
                if(board[i][j] == 2)
                    board[i][j] = 1;
                else if(board[i][j] == 3)
                    board[i][j] = 0;
            }
    }
}
```
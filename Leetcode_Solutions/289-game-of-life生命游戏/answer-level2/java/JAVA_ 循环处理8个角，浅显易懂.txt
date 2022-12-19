### 解题思路
循环计算8角，重新生成board然后在赋值过去。
如果不需要新的数组, 可以通过位运算来处理。因为格子不是0就是1, 即一个bit, 通过2个bit的数先预存到格子里，最后位运算处理

### 代码

```java
class Solution {
    public void gameOfLife(int[][] board) {
        int n, m;
        if(board == null || (n = board.length) == 0) return;
        if((m = board[0].length) == 0) return;

        int[][] nb = new int[n][m];
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                isLive(nb, board, i, j, n, m);
            }
        }

        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                board[i][j] = nb[i][j];
            }
        }
    }

    private void isLive(int[][] nb, int[][] board, int i, int j, int n, int m) {
        int sum = 0;
        // 计算周围的数值
        // 左边
        if(j > 0) {
            sum += board[i][j-1];
        }
        // 右边
        if(j < m - 1) {
            sum += board[i][j+1];
        } 

        // 上边
        if(i > 0) {
            sum += board[i -1][j];
        }
        // 下边
        if(i < n - 1) {
            sum += board[i + 1][j];
        }

        // 左上
        if(i > 0 && j > 0) {
            sum += board[i - 1][j - 1];
        }
        // 右下
        if(i < n -1 && j < m -1) {
            sum += board[i + 1][j + 1];
        } 
        
        // 右上
        if(i > 0 && j < m - 1) {
            sum += board[i - 1][j + 1];
        }
        // 坐下
        if(i < n - 1 && j > 0) {
            sum += board[i + 1][ j - 1];
        }

        if(board[i][j] == 1) {
            int isLive = 0;
            if(sum == 2 || sum == 3) {
                isLive = 1;
            }

            nb[i][j] = isLive;
        } else {
            nb[i][j] = sum == 3 ? 1 : 0;
        }
    }
}
```
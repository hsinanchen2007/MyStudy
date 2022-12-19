### 解题思路
原地算法：既要保存当前状态也要保存下一状态，那么用int 的各位和十位分别保存，最后再更新

### 代码

```Java []
class Solution {
    public void gameOfLife(int[][] board) {
        // 死亡和复活是同时进行
        // 原地算法：那么多一位来表示，十位表示下一秒状态，个位当前状态
        int[][] directs = {{-1, 0}, {-1, 1}, {0, 1}, {1, 1}, {1, 0}, {1, -1}, {0, -1}, {-1, -1}};
        int m = board.length, n = board[0].length;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                // 统计周围的存活数
                int lifeAround = 0;
                for (int[] direct : directs) {
                    int curi = i + direct[0], curj = j + direct[1];
                    if (curi < 0 || curj < 0 || curi == m || curj == n) continue;
                    if (board[curi][curj] % 10 == 1) ++lifeAround;
                }
                
                // 两种情况下下一秒细胞会变为1；（变为0的可以不用计算，因为原本十位就是0）
                if (board[i][j] == 1 && (lifeAround == 2 || lifeAround == 3))  board[i][j] += 10;
                if (board[i][j] == 0 && lifeAround == 3) board[i][j] += 10;
            }
        }

        // 更新board
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                board[i][j] /= 10;
            }
        }
    }
}
```
### 解题思路
根据题意，需要原地算法解决，故复制了原数组的一个二维数组temp用于判断，遍历temp每个元素，统计其周围八个位置的细胞存活数survive，当该位置为活细胞时，survice大于3或者小于2时该细胞死亡，当该位置为死细胞时，survice为3时该细胞存活。

### 代码

```java
class Solution {
      public void gameOfLife(int[][] board) {
        int n = board.length; // 行
        int m = board[0].length; //列
        int[][] direction = {{-1,-1},{-1,0},{-1,1},{0,-1},{0,1},{1,-1},{1,0},{1,1}};
        int[][] temp = new int[n][m];
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                temp[i][j] = board[i][j];
            }
        }
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                int survive = 0; // 记录该位置周围活细胞的个数
                for (int k = 0; k < 8; k++) {
                    int x = i + direction[k][0];
                    int y = j + direction[k][1];
                    if(x >= 0 && x < n && y >= 0 && y < m && temp[x][y] == 1) survive++; else continue;
                }
                if(temp[i][j] == 0 && survive == 3) board[i][j] = 1;
                if(temp[i][j] == 1 && (survive > 3 || survive <2)) board[i][j] = 0;
            }
        }
    }
}
```
### 解题思路
本题的思路是比之前岛屿的最大面积是要简单的, 只需要找到一个 1 之后, 对和其连接在一起的 1, 都做置 0, 处理;

### 代码

```java
class Solution {
    public int numIslands(char[][] grid) {
        // 取数组的行数
        int r = grid.length;
        // 一定要先判断, 再取数组的列数
        if (r == 0 || grid == null)     return 0;
        int c = grid[0].length;
        // 为了不改变输入, 自己 copy 一份原数组
        // 想问问大佬 有没有更简单的 copy 方案吗?
        char[][] ch = new char[r][c];
        for(int i = 0; i < r; i++) {
            for(int j = 0; j < c; j++) {
                ch[i][j] = grid[i][j];
            }
        }
        int ans = 0;
        for(int i = 0; i < r; i++) {
            for(int j = 0; j < c; j++) {
                // 遇到一个 1, 那么就表示遇到一个独立的岛屿.
                if (ch[i][j] == '1') {
                    ans ++;
                    dps(i, j, ch);
                }
            }
        }
        return ans;
    }
    // 这个 dps 只需要将找的一个 1, 周围连接的 1 都重新赋值为 0 即可.
    public void dps(int i, int j, char[][] ch) {
        if (i < 0 || j <0 || i >= ch.length || j >= ch[0].length || ch[i][j] == '0') {
            return;
        }
        ch[i][j] = '0';
        // 上下左右四个方向
        dps(i - 1, j, ch);
        dps(i + 1, j, ch);
        dps(i, j - 1, ch);
        dps(i, j + 1, ch);
    }
}
```
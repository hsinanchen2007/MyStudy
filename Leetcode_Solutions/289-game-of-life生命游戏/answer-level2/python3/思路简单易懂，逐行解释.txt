### 解题思路
**分析**：$1$ 代表细胞活的， $0$ 代表细胞死的，那么这个位置就四种状态，用【下一个状态，当前状态】表示，最后需要用右移操作更新结果
- 状态 $0$： $00$ ，死的，下一轮还是死的
- 状态 $1$： $01$，活的，下一轮死了
- 状态 $2$： $10$，死的，下一轮活了
- 状态 $3$： $11$，活的，下一轮继续活着

**进一步**：下一轮活的可能有两种，也就是要把单元格变为 $1$
1. 这个活细胞周围八个位置有两个或三个活细胞，下一轮继续活，属于 $11$
2. 这个细胞本来死的，周围有三个活着的，下一轮复活了，属于 $10$
    

那遍历下每个格子看他周围细胞有多少个活细胞就行了，然后更改为状态，那么对于第一种可能，把 $board[i][j]$ 设置为 $3$，对于第二种可能状态设置为 $2$，设置个高位flag，遍历后面的格子，拿到与他相邻的格子中有多少个 $alive$ 的，和 $1$ 与一下即可，最后我们把 $board[i][j]$ 右移 $1$位，更新结果

具体代码，我写了注释～

有错误麻烦大家指正，我会及时修改，谢谢您的观看！



### 代码

```java []
class Solution {
    int[] dx = {-1, 1, 0, 0, -1, -1, 1, 1};
    int[] dy = {0, 0, -1, 1, -1, 1, -1, 1};
    int[][] board;
    int m, n;

    public void gameOfLife(int[][] board) {
        this.board = board;
        // 特判
        if (board == null || board.length == 0 || board[0] == null || board[0].length == 0) return;
        this.m = board.length;
        this.n = board[0].length;
        // 遍历
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                // 拿到当前位置周围活细胞数量
                int cnt = countAlive(i, j);
                // 1. 活细胞周围八个位置有两个或三个活细胞，下一轮继续活 
                if (board[i][j] == 1 && (cnt == 2 || cnt == 3)) board[i][j] = 3;
                // 2. 死细胞周围有三个活细胞，下一轮复活了
                if (board[i][j] == 0 && cnt == 3) board[i][j] = 2;
            }
        }

        // 更新结果
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                board[i][j] >>= 1;
            }
        }
    }

    private int countAlive(int x, int y) {
        int cnt = 0;
        for (int k = 0; k < 8; k++) {
            int nx = x + dx[k];
            int ny = y + dy[k];
            if (nx < 0 || nx >= m || ny < 0 || ny >= n) continue;
            // 如果这个位置为 0，代表当前轮是死的，不需要算进去
            // 如果这个位置为 1，代表当前轮是活得，需要算进去
            // 如果这个位置为 2，代表当前轮是死的（状态10，下一轮是活的），不需要算进去
            // 如果这个位置为 3，代表是当前轮是活的（状态11，下一轮也是活的），需要算进去
            cnt += (board[nx][ny] & 1);
        }
        return cnt;
    }
}
```
```python []
class Solution:
    def gameOfLife(self, board: List[List[int]]) -> None:
        """
        Do not return anything, modify board in-place instead.
        """
        if not board or not board[0]:
            return
        
        m, n = len(board), len(board[0])
        for i in range(m):
            for j in range(n):
                cnt = self.count_alive(board, i, j)
                if board[i][j] and cnt in [2, 3]:
                    board[i][j] = 3
                if not board[i][j] and cnt == 3:
                    board[i][j] = 2
        
        for i in range(m):
            for j in range(n):
                board[i][j] >>= 1
    
    def count_alive(self, board, i, j):
        m, n = len(board), len(board[0])
        cnt = 0
        directions = [(0, 1), (0, -1), (-1, 0), (1, 0),
                      (1, 1), (1, -1), (-1, 1), (-1, -1)]
        
        for dx, dy in directions:
            x, y = i + dx, j + dy
            if x < 0 or y < 0 or x == m or y == n:
                continue
            cnt += board[x][y] & 1
        
        return cnt
```

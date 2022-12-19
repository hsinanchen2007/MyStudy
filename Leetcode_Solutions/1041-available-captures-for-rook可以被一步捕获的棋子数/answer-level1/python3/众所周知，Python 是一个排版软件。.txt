### 解题思路

rx, ry 找到 R 的坐标。

findp 利用递归检查 R 往 x_step, y_step 的方向走会不会遇到 p

将四个方向的结果相加返回

### 代码

```python3
class Solution:
    def numRookCaptures(self, board: List[List[str]]) -> int:
        rx, ry = [(i, j) for i in range(8) for j in range(8) if board[i][j] == 'R'][0]
        def findp(x, y, x_step, y_step):
            return False if x < 0 or x > 7 or y < 0 or y > 7 or board[x][y] == 'B' \
                else board[x][y] == 'p' or findp(x + x_step, y + y_step, x_step, y_step)
        return findp(rx, ry, -1, 0) + \
                findp(rx, ry, 1, 0) + \
               findp(rx, ry, 0, -1) + \
                findp(rx, ry, 0, 1)
```
### 解题思路
仿照大神思路

### 代码

```python3
class Solution:
    def gameOfLife(self, board: List[List[int]]) -> None:
        """
        Do not return anything, modify board in-place instead.
        """

        dx = [-1, -1, -1, 0, 1, 1, 1, 0]
        dy = [-1, 0, 1, 1, 1, 0, -1, -1]
        n, m = len(board), len(board[0])
        for i, j in itertools.product(range(n), range(m)):
            count = 0
            for d in range(8):
                nx, ny = i + dx[d], j + dy[d]
                if 0 <= nx < n and 0 <= ny < m and (board[nx][ny]&1):
                    count += 1
            if board[i][j] == 1:
                board[i][j] += (count == 2 or count == 3) << 1
            else:
                board[i][j] += (count == 3) << 1
            
        for i, j in itertools.product(range(n), range(m)):
            board[i][j] >>= 1



```
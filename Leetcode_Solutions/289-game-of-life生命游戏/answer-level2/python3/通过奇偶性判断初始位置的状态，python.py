### 解题思路
对于每一个格子，遍历周围的八个格子，每有一个格子为奇数，当前格子就加2，这样就不会破坏奇偶性。最后在遍历完所有格子之后通过查看每个格子的值，得出格子最终状态是0还是1。

### 代码

```python3
class Solution:
    def gameOfLife(self, board: List[List[int]]) -> None:
        """
        Do not return anything, modify board in-place instead.
        """
        if not board or not board[0]: pass
        M, N = len(board), len(board[0])
        def neighbour(i, j):
            res = []
            for l in range(i-1, i+2):
                for r in range(j-1, j+2):
                    if l >= 0 and l < M and r >= 0 and r < N and (l != i or j != r):
                        res.append([l,r])
            return res
        for i in range(M):
            for j in range(N):
                for coor in neighbour(i,j):
                    if board[coor[0]][coor[1]] % 2 == 1:
                        board[i][j] += 2
        for i in range(M):
            for j in range(N):
                if board[i][j] > 4 and board[i][j] < 8:
                    board[i][j] = 1
                else:
                    board[i][j] = 0
```
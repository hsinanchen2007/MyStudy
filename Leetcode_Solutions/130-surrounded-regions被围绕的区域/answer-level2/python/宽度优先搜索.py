### 解题思路
1. 首先找到边界上的所有 O
1. 然后从它们出发，遍历所有挨着的 O，并标记为外界O
1. 遍历整个矩阵，如果不是边界O，则变为 X

### 代码

```python3
class Solution:
    def solve(self, board: List[List[str]]) -> None:
        """
        Do not return anything, modify board in-place instead.
        """
        """
        思路：
            首先找到边界上的所有 O
            然后从它们出发，遍历所有挨着的 O，并标记为外界O
            遍历整个矩阵，如果不是边界O，则变为 X
        """
        if board == []:
            return
        n, m = len(board), len(board[0])
        isOut = [[False] * m for i in range(n)]
        q = []
        x = [0, 0, 1, -1]
        y = [1, -1, 0, 0]
        # 看第一行和最后一行，将里边的边界 0 入队
        for i in range(m):
            if board[0][i] == 'O' and not isOut[0][i]: 
                isOut[0][i] = True
                q.append((0,i))
            if board[n-1][i] == 'O' and not isOut[n-1][i]:
                isOut[n-1][i] = True
                q.append((n-1,i))
        # 看第一列和最后一列
        for i in range(n):
            if board[i][0] == 'O' and not isOut[i][0]: 
                isOut[i][0] = True
                q.append((i,0))
            if board[i][m-1] == 'O' and not isOut[i][m-1]:
                isOut[i][m-1] = True
                q.append((i,m-1))



        # 队不空的时候，宽度优先搜索
        while len(q):
            c = q.pop(0)
            for i in range(4):
                v_x = c[0] + x[i]
                v_y = c[1] + y[i]
                if v_x >= 0 and v_x < n and v_y >= 0 and v_y < m:
                    if board[v_x][v_y] == 'O' and not isOut[v_x][v_y]:
                        q.append((v_x,v_y))
                        isOut[v_x][v_y] = True
        for i in range(n):
            for j in range(m):
                if not isOut[i][j]:
                    board[i][j] = 'X'

```
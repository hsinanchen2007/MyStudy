### 解题思路
先找到车，再各个方向遍历

### 代码

```python3
class Solution:
    def numRookCaptures(self, board: List[List[str]]) -> int:
        i, j = [(i,j) for i in range(8) for j in range(8) if board[i][j] == 'R'][0]
        acc = 0
        NEWS = ((0,1), (0,-1), (1,0), (-1,0))
        for dx,dy in NEWS:
            x, y = i + dx, j + dy
            while 0<=x<=7 and 0<=y<=7:
                if board[x][y] == 'B':
                    break
                if board[x][y] == 'p':
                    acc += 1
                    break
                x, y = x + dx, y + dy 
        return acc
```
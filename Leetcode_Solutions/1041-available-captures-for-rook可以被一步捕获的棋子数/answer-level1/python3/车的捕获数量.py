### 解题思路
沿各个方向判断是否存在对应棋子，如果一个方向存在则加一

### 代码

```python3
class Solution:
    def numRookCaptures(self, board: List[List[str]]) -> int:
        x, y = 0, 0
        temp1, temp2 = [], []
        for i in range(len(board)):
            for j in range(len(board[0])):
                if board[i][j] == 'R':
                    x, y = i, j
                elif board[i][j] == 'B':
                    temp1.append((i, j))
                elif board[i][j] == 'p':
                    temp2.append((i, j))
        count, axis = 0, [[1, 0], [0, -1], [-1, 0], [0, 1]]
        for temp in axis:
            i, j = x, y
            while 0 <= i < len(board) and 0 <= j < len(board[0]):
                i, j = i + temp[0], j + temp[1]
                if (i, j) in temp2:
                    count += 1
                    break
                elif (i, j) in temp1:
                    break
        return count
        
```
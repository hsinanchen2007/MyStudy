### 解题思路
先把'R'找出来
然后以'R'为起点，往四个方向上找

### 代码

```python3
class Solution:
    def numRookCaptures(self, board: List[List[str]]) -> int:
        count = 0
        #  找到'R'的位置
        for i in range(8):
            for j in range(8):
                if board[i][j] == 'R':
                    vertical = j
                    horizon = i
                    break
        
        #  往右找
        for i in range(vertical+1, 8):
            if board[horizon][i] == '.':
                continue
            else:
                if board[horizon][i] == 'p':
                    count += 1
                    break
                elif board[horizon][i] == 'B':
                    break
        
        #  往左找
        for i in range(vertical, -1, -1):
            if board[horizon][i] == '.':
                continue
            else:
                if board[horizon][i] == 'p':
                    count += 1
                    break
                elif board[horizon][i] == 'B':
                    break
        
        #  往下找
        for i in range(horizon+1, 8):
            if board[i][vertical] == '.':
                continue
            else:
                if board[i][vertical] == 'p':
                    count += 1
                    break
                elif board[i][vertical] == 'B':
                    break
        
        #  往上找
        for i in range(horizon, -1, -1):
            if board[i][vertical] == '.':
                continue
            else:
                if board[i][vertical] == 'p':
                    count += 1
                    break
                elif board[i][vertical] == 'B':
                    break
        
        return count
```
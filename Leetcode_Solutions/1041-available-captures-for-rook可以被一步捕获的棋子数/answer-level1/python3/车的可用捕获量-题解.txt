### 解题思路
很暴力
- 先找到车的位置，
- 然后在其上下左右四个方向分别向外遍历，
- 只要碰到象或者卒，都会停止该方向的遍历；
- 碰到卒则将计数加1

### 代码

```python3
class Solution:
    def numRookCaptures(self, board: List[List[str]]) -> int:
        rows = len(board)
        if rows <= 0:
            return 0
        cols = len(board[0])

        # 找到白色车的位置
        rx = ry = -1
        for i in range(rows):
            for j in range(cols):
                if board[i][j] == 'R':
                    ry = j 
                    break    
            if ry > -1:
                rx = i
                break
        if rx == ry == -1:
            return 0

        cnt = 0
        # 往上找
        for i in range(rx-1, -1, -1):
            if board[i][ry] == 'B':
                break
            elif board[i][ry] == 'p':
                cnt += 1
                break
        # 往下找
        for i in range(rx+1, rows):
            if board[i][ry] == 'B':
                break
            elif board[i][ry] == 'p':
                cnt += 1
                break

        # 往左找
        for j in range(ry-1, -1, -1):
            if board[rx][j] == 'B':
                break
            elif board[rx][j] == 'p':
                cnt += 1
                break

        # 往右找
        for j in range(ry+1, cols):
            if board[rx][j] == 'B':
                break
            elif board[rx][j] == 'p':
                cnt += 1
                break

        return cnt
        
```
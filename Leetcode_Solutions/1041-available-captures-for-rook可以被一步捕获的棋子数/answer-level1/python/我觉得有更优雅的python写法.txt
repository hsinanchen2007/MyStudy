### 解题思路
此处撰写解题思路

### 代码

```python3
class Solution:
    def numRookCaptures(self, board: List[List[str]]) -> int:
        for r in board:
            if 'R' in r:
                break
        x = board.index(r)
        y = r.index('R')
        ans = 0
        for dirt in [(-1,0),(1,0),(0,1),(0,-1)]:
            tx = x + dirt[0]
            ty = y + dirt[1]
            while 0<=tx<8 and 0<=ty<8 and board[tx][ty] == '.':
                tx = tx + dirt[0]
                ty = ty + dirt[1]
            if 0<=tx<8 and 0<=ty<8 and board[tx][ty] == 'p':
                ans = ans + 1
        return ans
```
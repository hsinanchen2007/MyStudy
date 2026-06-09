### 解题思路
暴力

### 代码

```python
class Solution(object):
    def numRookCaptures(self, board):
        """
        :type board: List[List[str]]
        :rtype: int
        """

        def find(board):
            for i in range(8):
                for j in range(8):
                    if board[i][j] == 'R':
                        return (i,j)
        ret=0
        pos = find(board)
        for dx,dy in [(1,0),(-1,0),(0,1),(0,-1)]:
            t = pos
            while True:
                t = (t[0]+dx,t[1]+dy)
                if t[0]>7 or t[0]<0 or t[1] >7 or t[1]<0:
                    break
                if board[t[0]][t[1]]=='p':
                    ret+=1
                    break
                elif board[t[0]][t[1]]!='.':
                    break

        return ret
        
```
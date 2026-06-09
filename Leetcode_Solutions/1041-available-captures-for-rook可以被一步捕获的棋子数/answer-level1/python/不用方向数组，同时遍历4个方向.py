```python3
class Solution:
    def numRookCaptures(self, board: List[List[str]]) -> int:
        '''
        找到R
        访问其上下左右的元素，直到找到p、遇到B、到达边界
        时间复杂度：O(n^2 + n)
        空间复杂度：O(1)
        '''
        blen = len(board)
        res = 0
        x,y = blen,blen
        for i in range(blen):
            for j in range(blen):
                if board[i][j] == 'R':
                    x , y = i, j
                    break
        step = 1
        # 找到p、遇到B、到达边界时将对应方向设为false
        up, down, left, right = True, True, True, True  
        while up or down or left or right:
            if up:
                u = y-step
                if u < 0 or board[x][u] == 'B':  # 到达边界或遇到B
                    up = False
                elif board[x][u] == 'p':
                    res += 1
                    up = False
            if down:
                u = y+step
                if u >= blen or board[x][u] == 'B':
                    down = False
                elif board[x][u] == 'p':
                    res += 1
                    down = False
            if left:
                u = x-step
                if u < 0 or board[u][y] == 'B':
                    left = False
                elif board[u][y] == 'p':
                    res += 1
                    left = False
            if right:
                u = x+step
                if u >= blen or board[u][y] == 'B':
                    right = False
                elif board[u][y] == 'p':
                    res += 1
                    right = False
            
            step += 1
        
        return res
```

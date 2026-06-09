### 解题思路
此处撰写解题思路

### 代码

```python3
class Solution:
    def numRookCaptures(self, board: List[List[str]]) -> int:
        R_x = [x for x in range(8) if 'R' in board[x]][0]
        R_y = board[R_x].index('R')

        res = 0
        # Solution 1: 4个for if循环
        # for i in range(R_x,-1,-1):
        #     if board[i][R_y] == 'B':
        #         break
        #     elif board[i][R_y] == 'p':
        #         res += 1
        #         break
        # for i in range(R_x,8):
        #     if board[i][R_y] == 'B':
        #         break
        #     elif board[i][R_y] == 'p':
        #         res += 1
        #         break
        # for i in range(R_y,-1,-1):
        #     if board[R_x][i] == 'B':
        #         break
        #     elif board[R_x][i] == 'p':
        #         res += 1
        #         break
        # for i in range(R_y,8):        
        #     if board[R_x][i] == 'B':
        #         break
        #     elif board[R_x][i] == 'p':
        #         res += 1
        #         break
        # return res

        # Soultion 2: 方向数组
        directions = [[0,1], [1,0], [0,-1], [-1,0]]
        for d in directions:
            tx, ty = R_x, R_y
            while True:
                tx += d[0]
                ty += d[1]
                if  tx >= 8 or tx < 0 or ty >= 8 or ty < 0 or board[tx][ty] == 'B': 
                    break
                elif board[tx][ty] == 'p':
                    res += 1
                    break
        return res
                
```
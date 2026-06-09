先暴力枚举发现`白车`的位置，然后从此位置出发，上下左右四个方向开始搜索

```python
class Solution:
    def numRookCaptures(self, board: List[List[str]]) -> int:
        # 定义上下左右四个方向
        dx = [-1,1,0,0]
        dy = [0,0,-1,1] 

        for i in range(8):
            for j in range(8):
                if board[i][j] == 'R':  # 发现了白车
                    cnt = 0
                    for k in range(4):
                        x,y = i,j
                        while(1): # 从白车所在位置 延一个方向（上/下/左/右）一直搜索直到退出
                            x += dx[k]
                            y += dy[k]
                            if (x<0 or x>7 or y<0 or y>7 or board[x][y]=='B'): # 到达边界或者遇到白象
                                break
                            if (board[x][y]=='p'):
                                cnt += 1
                                break
                    return cnt
        return 0
```
### 解题思路
对于矩阵的九宫格，先用数组存储各个方向的增量，然后判断当前坐标的增量之和后的坐标是否合法。
对于不使用额外内存来说，可以将当前需要变化的细胞改为其他数字，在考虑其他位置时把其他数字也考虑进去即可。

### 代码

```python3
class Solution:
    def gameOfLife(self, board: List[List[int]]) -> None:
        """
        Do not return anything, modify board in-place instead.
        """
        m = len(board)
        n = len(board[0])
        delta = [[-1,-1],[-1,0],[-1,1],[0,-1],[0,1],[1,-1],[1,0],[1,1]]
        pos = []
        for i in range(m):
            for j in range(n):
                cnt = 0
                for x, y in delta:
                    if i+x < 0 or i+x >=m or j+y<0 or j+y >=n:
                        continue
                    cnt += (board[i+x][j+y]==1)
                #print(cnt)
                if board[i][j] == 1:
                    if cnt < 2 or cnt > 3:
                        pos.append([i,j])
                else:
                    if cnt == 3:
                        pos.append([i,j])
        #print(pos)
        for x,y in pos:
            if board[x][y] == 1:
                board[x][y] = 0
            else:
                board[x][y] = 1



                      





```
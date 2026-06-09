### 解题思路
新增两个状态码代表改变后的状态，以此记录改变前的特征，最后根据状态表更新改版后的特征。

### 代码

```python3
class Solution:
    def gameOfLife(self, board: List[List[int]]) -> None:
        """
        Do not return anything, modify board in-place instead.
        """
        m=len(board)
        n=len(board[0])
        directions=[(1,0),(-1,0),(0,1),(0,-1),(1,1),(-1,-1),(1,-1),(-1,1)]
        #改变情况下的状态码说明：
        #2：原本活现在死
        #-1：原本死现在活
        for i in range(m):
            for j in range(n):
                total=0
                for dx,dy in directions:
                    if 0<=i+dx<m and 0<=j+dy<n:
                        if board[i+dx][j+dy]>=1:
                            total+=1
                if board[i][j]==1:
                    if total<2 or total>3:
                        board[i][j]=2
                else:
                    if total==3:
                        board[i][j]=-1
        for i in range(m):
            for j in range(n):
                if board[i][j]==-1:
                    board[i][j]=1
                elif board[i][j]==2:
                    board[i][j]=0


                    

```
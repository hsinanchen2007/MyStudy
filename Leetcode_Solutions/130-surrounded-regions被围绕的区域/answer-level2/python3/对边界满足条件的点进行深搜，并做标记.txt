![image.png](https://pic.leetcode-cn.com/d065bbf3fd2d62788ec825798f5dde195ee15f0e01b522df122da71739ee6dda-image.png)

边界出现'O'就深搜，改成标记，这里用的是空字符，然后再需要一个集合去标记访问过的点，避免重复访问。

最后按标记变更矩阵。

```
class Solution:
    def solve(self, board: List[List[str]]) -> None:
        if board:
            m,n=len(board),len(board[0])
        
            c=set()
        
            def f(x,y):#对传入坐标深搜
                if (x,y) not in c and board[x][y]=='O':
                    board[x][y]=''#边界标记
                    for i,j in [(-1,0),(1,0),(0,-1),(0,1)]:
                        if 0<=x+i<m and 0<=y+j<n:
                            f(x+i,y+j)
                c.add((x,y))
            
            for i in range(m):#访问左右边界
                f(i,0)
                f(i,n-1)
        
            for j in range(1,n):#访问上下边界
                f(0,j)
                f(m-1,j)
        
            for i in range(m):
                for j in range(n):
                    if board[i][j]=='':
                        board[i][j]='O'
                    elif board[i][j]=='O':
                        board[i][j]='X'
```

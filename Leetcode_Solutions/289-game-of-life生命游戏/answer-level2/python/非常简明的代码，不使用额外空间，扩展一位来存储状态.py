### 解题思路
当下一轮状态是活状态的时候，和数值0b10(十进制的2)或运算，相当于扩展了1位表示下一轮是活，下一轮是死状态的时候无需做任何操作
表格的数值和1与运算，仍然可以取到当前状态
状态标记完毕后，每个数值右移1位，更新状态

### 代码

```python3
class Solution:
    def gameOfLife(self, board: List[List[int]]) -> None:
        """
        Do not return anything, modify board in-place instead.
        """
        r=len(board)
        c=len(board[0])        
        direct=[(-1,-1),(0,-1),(1,-1),(1,0),(1,1),(0,1),(-1,1),(-1,0)]
        for i in range(0,r):
            for j in range(0,c):
                n=sum(board[i+d[0]][j+d[1]]&1 for d in direct if 0<=i+d[0]<r and 0<=j+d[1]<c)
                if board[i][j]&1==1:
                    if n==2 or n==3:
                        board[i][j]|=2
                elif n==3:
                    board[i][j]|=2
        for i in range(0,r):
            for j in range(0,c):
                board[i][j]>>=1

```
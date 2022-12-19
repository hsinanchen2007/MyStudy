### 解题思路
寻找与边界相连的所有o(从边缘的o出发，dfs遍历)，再将其他o置为x

### 代码

```python3
class Solution:
    def solve(self, board: List[List[str]]) -> None:
        """
        Do not return anything, modify board in-place instead.
        """
        def dfs(i,j,m,n,board):
            global flag
            #print(flag)
            if i<0 or i>=m or j<0 or j >=n:   
                return 
            if board[i][j] == 'X':
                return
            if [i,j] in flag:
                return
            flag.append([i,j])
            dfs(i-1,j,m,n,board)
            dfs(i,j-1,m,n,board)
            dfs(i+1,j,m,n,board)
            dfs(i,j+1,m,n,board)
        if board != []:
            m = len(board)
            n = len(board[0])
            border = []
            for i in range(m):
                for j in range(n):
                    if board[i][j] == 'O':
                        if i==0 or i==m-1 or j==0 or j==n-1:
                            border.append([i,j])
            #print(border)
            global flag
            flag = []
            for i,j in border:
                dfs(i,j,m,n,board)
            for i in range(m):
                for j in range(n):
                    if board[i][j] == 'O' and [i,j] not in flag:
                        board[i][j] = 'X'

```
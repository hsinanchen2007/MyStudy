    首先二维矩阵只包含'X'与'O'，只有处于边界和与边界相连的'O'最终会保留下来，其余的都将变为'X'。
定义一个全为0的temp数组
1.首先遍历一次board数组，当到边界的时候，则进入递归函数core，这个函数将会把与之相邻的'O'中对应temp数组的值变为1，并且继续递归
2.再次遍历board数组，对于对应temp数组值为0，并且值为'O'的点，修改为'X'。因为他们不处于边界或与边界'O'相邻。
（vis数组用于剪枝)

```python []
class Solution:
    def solve(self, board: List[List[str]]) -> None:
        """
        Do not return anything, modify board in-place instead.
        """
        if board==[]:
            return []
        temp=[[0]*len(board[0]) for i in range(len(board))]
        vis=[[0]*len(board[0]) for i in range(len(board))]
        def core(i,j):
            temp[i][j]=1
            vis[i][j]=1
            if i!=0 and board[i-1][j]=='O':
                temp[i-1][j]=1
                if vis[i-1][j]==0:
                    core(i-1,j)
            if j!=0 and board[i][j-1]=='O':
                temp[i][j-1]=1
                if vis[i][j-1]==0:
                    core(i,j-1)
            if i!=len(board)-1 and board[i+1][j]=='O':
                temp[i+1][j]=1
                if vis[i+1][j]==0:
                    core(i+1,j)
            if j!=len(board[0])-1 and board[i][j+1]=='O':
                temp[i][j+1]=1
                if vis[i][j+1]==0:
                    core(i,j+1)
        for i in range(len(board)):
            for j in range(len(board[0])):
                if (i==0 or i==len(board)-1 or j==0 or j==len(board[0])-1) and board[i][j]=='O':
                    core(i,j)
        for i in range(len(board)):
            for j in range(len(board[0])):
                if temp[i][j]==0 and board[i][j]=='O':
                    board[i][j]='X'
```

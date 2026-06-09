因为我比较菜所以这道题就硬做. 首先遍历所有棋盘上的元素，将其周围所有数取mod(2)相加得出周围存活的细胞数量。如果从活到死，那么则将这个位置的数字改为3作为标记,如果从死到活则将数字改为2作为标记。因为3%2=1，2%2=0，所以并不影响其它的计算。 最后再次遍历将3改为0，2改为1
```
class Solution:
    def gameOfLife(self, board: List[List[int]]) -> None:
        """
        Do not return anything, modify board in-place instead.
        """
        m=len(board)
        n=len(board[0])
        

        for i in range(m):
            for j in range(n):
                total=0
                if i<m-1:
                    total=total+board[i+1][j]%2
                if i>0:
                    total=total+board[i-1][j]%2
                if j<n-1:
                    total=total+board[i][j+1]%2
                if j>0:
                    total=total+board[i][j-1]%2
                if i<m-1 and j<n-1:
                    total=total+board[i+1][j+1]%2
                if i<m-1 and j>0:
                    total=total+board[i+1][j-1]%2
                if i>0 and j<n-1:
                    total=total+board[i-1][j+1]%2
                if i>0 and j>0:
                    total=total+board[i-1][j-1]%2
                
                if board[i][j]==1 and total<2 or board[i][j]==1 and total>3:
                    board[i][j]=3
                if board[i][j]==0 and total==3:
                    board[i][j]=2


        for i in range(m):
            for j in range(n):
                if board[i][j]==3:
                    board[i][j]=0
                if board[i][j]==2:
                    board[i][j]=1
```

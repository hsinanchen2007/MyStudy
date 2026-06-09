```
class Solution:
    def __init__(self):
        self.directions=[(0,1),(0,-1),(1,0),(-1,0)]
    def solve(self, board: List[List[str]]) -> None:
        """
        Do not return anything, modify board in-place instead.
        """
        m = len(board)
        if m==0:
            return board
        n = len(board[0])
        board_copy=[[1 for _ in range(n) ] for _ in range(m)]
        def mask(i,j,board,board_copy):
            # print(i,j)
            board_copy[i][j]=2
            for direct in self.directions:
                
                new_i=i+direct[0]
                new_j= j + direct[1]
                
                if 0<=new_i<m and 0<=new_j<n :
                    # print(board[new_i][new_j])
                    # print(board_copy[new_i][new_j])
                    if board[new_i][new_j]=='O' and board_copy[new_i][new_j]==1:
                        mask(new_i,new_j,board,board_copy)
                        # print('1')

        for  i in range(n):
            
            if board[0][i]=='O' and board_copy[0][i]==1:
                mask(0,i,board,board_copy)
            if board[m-1][i]=='O' and board_copy[m-1][i]==1:
                mask(m-1,i,board,board_copy)    
        for j in range(m):
            if board[j][0]=='O' and board_copy[j][0]==1:
                mask(j,0,board,board_copy)
            if board[j][n-1]=='O' and board_copy[j][n-1]==1:
                mask(j,n-1,board,board_copy)
        # print(board_copy)
        for i in range(m):
            for j in range(n):
                if board[i][j]=='O' and board_copy[i][j]==1:
                    board[i][j]='X'
        
```

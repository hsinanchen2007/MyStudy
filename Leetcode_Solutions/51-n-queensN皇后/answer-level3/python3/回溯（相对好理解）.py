我这边用列表tmp记录坐标，abs函数搞定对角线

    
    
class Solution:


    def solveNQueens(self, n: int) -> List[List[str]]:
        tmp, res = [],[]  
        board = [["." for _ in range(n)] for _ in range(n)]     
        self.dfs(tmp, board, 0, res, n)
        
        return res
   
    def valid(self, tmp, point):
        x, y = point[0], point[1]
        for (a,b) in tmp:
            if a == x or b ==y or abs(a-x) == abs(b-y):
                return False
        return True 
  
    def dfs(self, tmp, board, row,res, n): #坐标数组, "."数组, 当前行数,  记录容器,  总行数

        if row == len(board):
            arr = []
            for _ in board:
                arr.append(''.join(_))
            res.append(arr)
            return
               
        for y in range(n):
            if not self.valid(tmp, (row,y)):
                continue
                       
            tmp.append((row,y)) 
            board[row][y] = "Q"        
            self.dfs(tmp, board, row+1,  res ,n)
            board[row][y] = "."
            tmp.pop()
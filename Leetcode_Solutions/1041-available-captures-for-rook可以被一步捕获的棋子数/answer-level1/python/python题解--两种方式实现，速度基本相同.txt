```
class Solution(object):
    def numRookCaptures(self, board):
        """
        :type board: List[List[str]]
        :rtype: int
        """
        #第一种上下左右匹配，for循环解题
        
        for i in range(len(board)):
            if 'R' in board[i]:
                raw = i
                break
        colum = board[raw].index('R')
        
        result = 0
        #第一种上下左右匹配，for循环解题
        
        #计算上面
        for i in range(raw-1,-1,-1):
            if board[i][colum] !='.' and board[i][colum] == 'p':
                result += 1
                break
            elif board[i][colum] !='.' and board[i][colum] == 'B':
                break
        
         #计算下面
        for i in range(raw+1,8):
            if board[i][colum] !='.' and board[i][colum] == 'p':
                result += 1
                break
            elif board[i][colum] !='.' and board[i][colum] == 'B':
                break
        
        #计算左面
        for i in range(colum-1,-1,-1):
            if board[raw][i] !='.' and board[raw][i] == 'p':
                result += 1
                break
            elif board[raw][i] !='.' and board[raw][i] == 'B':
                break        
                
        #计算右面
        for i in range(colum+1,8):
            if board[raw][i] !='.' and board[raw][i] == 'p':
                result += 1
                break
            elif board[raw][i] !='.' and board[raw][i] == 'B':
                break        
        
        return result
        
        #第二种解法
        s = ''.join(board[raw])
        s = s.replace('.','')
        if 'pR' in s:
            result += 1
        if 'Rp' in s:
            result += 1
        s = ''.join(i[colum] for i in board)
        s = s.replace('.','')
        if 'pR' in s:
            result += 1
        if 'Rp' in s:
            result += 1
        return result
```

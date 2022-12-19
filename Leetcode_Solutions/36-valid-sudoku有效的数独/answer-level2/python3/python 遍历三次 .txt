方法简单但是提交多次才过 
```
class Solution:
    def isValidSudoku(self, board: List[List[str]]) -> bool:
        flag = True
        s = set()
        for i in range(9):  #行
            s.clear()
            for j in range(9):     
                if board[i][j] != '.':
                    if board[i][j] in s  :
                        flag = False
                        break
                    else:
                        s.add(board[i][j])
            if flag == False:
                break
                
        if flag:
            for i in range(9):  #列
                s.clear()
                for j in range(9):   
                    if board[j][i] != '.':
                        if board[j][i] in s:
                            flag = False
                            break
                        else:
                            s.add(board[j][i])
                if flag == False:
                    break
        if flag:  
            for k in range(3):     #正方形
                count = 0
                while count < 3:
                    s.clear()
                    for i in range(3*k,3*k+3):
                        for j in range(3*count,3*count+3):
                            if board[i][j] != '.':
                                if board[i][j] in s:
                                    flag = False
                                    break
                                else:
                                    s.add(board[i][j])
                    if flag == False:
                        break            
                    count += 1
                if flag == False:
                    break
        return flag
                    
```

```
class Solution(object):
    def validTicTacToe(self, board):
        """
        :type board: List[str]
        :rtype: bool
        """
        xn, on = 0, 0
        
        for i in range(3):
            for j in range(3):
                if board[i][j] == 'X':
                    xn += 1
                elif board[i][j] == 'O':
                    on += 1
        flag = [False, False] 
        for i in range(3):
            if board[i][0] == board[i][1] and board[i][0] == board[i][2] and board[i][0] != ' ':
                if board[i][0] == 'X':
                    flag[0] = True
                else:
                    flag[1] = True
        for j in range(3):
            if board[0][j] == board[1][j] and board[0][j] == board[2][j] and board[0][j] != ' ':
                if board[0][j] == 'X':
                    flag[0] = True
                else:
                    flag[1] = True
        if board[0][0] == board[1][1] and board[0][0] == board[2][2] and  board[1][1] != ' ':
                if board[1][1] == 'X':
                    flag[0] = True
                else:
                    flag[1] = True
        if board[0][2] == board[1][1] and board[1][1] == board[2][0] and  board[1][1] != ' ':
                if board[1][1] == 'X':
                    flag[0] = True
                else:
                    flag[1] = True
        print(flag, xn, on)
        if on>xn:
            return False
        if xn-on>1:
            return False
        
        if flag[0] and flag[1]:
            return False
        
        if flag[0] and on==xn:
            return False
        if flag[1] and xn>on:
            return False
        return True
```

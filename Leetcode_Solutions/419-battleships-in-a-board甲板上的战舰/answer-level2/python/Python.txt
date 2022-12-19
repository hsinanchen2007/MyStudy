```
class Solution(object):
    def countBattleships(self, board):
        """
        :type board: List[List[str]]
        :rtype: int
        """
        count = 0
        for i in range(len(board)):
            for j in range(len(board[0])):
                if board[i][j] == 'X':
                    if (j == 0 or board[i][j-1] != 'X') and (i == 0 or board[i-1][j] != 'X'):
                        count += 1
        return count
```

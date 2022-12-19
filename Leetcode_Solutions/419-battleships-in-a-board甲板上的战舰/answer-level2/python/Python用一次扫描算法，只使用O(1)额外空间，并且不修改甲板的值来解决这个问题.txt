```
由于不存在无效夹板，因此对于同一艘战舰的X都是相连的，对于坐标为[i, j]值如果为X
[i-1, j]和[i, j-1]都不是X,判断[i, j]为一个战舰的起始
[i-1, j]或[i, j-1]如果为X,说明是同一艘战舰
```

```
class Solution(object):
    def countBattleships(self, board):
        """
        :type board: List[List[str]]
        :rtype: int
        """
        row = len(board)
        col = len(board[0])
        count = 0
        for row_index in range(row):
            for col_index in range(col):
                f1 = False
                f2 = False
                if board[row_index][col_index] == 'X':
                    if row_index-1 >= 0:
                         if board[row_index-1][col_index] != 'X':
                                f1 = True
                    else:
                        f1 = True
                    
                    if col_index-1 >= 0:
                         if board[row_index][col_index-1] != 'X':
                                f2 = True
                    else:
                        f2 = True
                    
                    if f1 and f2:
                        count += 1
        return count
```
- ### 解题思路
建立visitmap数组
首先找到边缘为‘O’的元素 然后对visitmap数组染色

### 代码

```python3
class Solution:
    def DealComp(self, board,visitmap, Row , Col, RowMax, ColMax):
        if board[Row][Col] == 'O':
            for [RowSearch, ColSearch] in [[Row, Col-1], [Row+1, Col], [Row-1, Col], [Row, Col + 1]]:
                if  (1<= RowSearch <= (RowMax - 1))  and (1<= ColSearch <= (ColMax - 1)):
                    if(board[RowSearch][ColSearch] == 'O') and (visitmap[RowSearch][ColSearch] == 0):
                        visitmap[RowSearch][ColSearch] = 2
                        self.DealComp(board, visitmap, RowSearch, ColSearch, RowMax, ColMax)


    def solve(self, board):
        if board == []:
            return []
        BoardRow = len(board)
        BoardCol = len(board[0])
        visitmap = [[0 for i in range(BoardCol)] for i in range(BoardRow)]
        for IdxRow in range(0, BoardRow):
             for IdxCol in range(0, BoardCol):
                 if(IdxRow == 0) or (IdxRow == BoardRow - 1) or (IdxCol == 0) or (IdxCol == BoardCol - 1):
                     visitmap[IdxRow][IdxCol] = 1
                     self.DealComp(board, visitmap, IdxRow, IdxCol, BoardRow - 1, BoardCol - 1)
        for IdxRow in range(0, BoardRow):
            for IdxCol in range(0, BoardCol):
                if(visitmap[IdxRow][IdxCol] == 0):
                    board[IdxRow][IdxCol] = "X"
        return board
```
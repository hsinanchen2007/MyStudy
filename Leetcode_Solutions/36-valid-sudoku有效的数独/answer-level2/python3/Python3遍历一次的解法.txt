遍历一次，构造行列表、列列表、块列表，如果有列表不满足数独要求，即返回False.
```
class Solution:
    def sudokuRule(self,array):
        flagList={'1':0,'2':0,'3':0,'4':0,'5':0,'6':0,'7':0,'8':0,'9':0}
        for elem in array:
            if elem!='.':
                flagList[elem]+=1
                if flagList[elem]>1:
                    return False
        return True

    def isValidSudoku(self, board):
        noteLine=[[] for i in range(9)]
        noteColumn=[[] for i in range(9)]
        noteGrid=[[] for i in range(9)]
        for x in range(9):
            for y in range(9):
                gridIndex=int(x/3)+int(y/3)*3
                noteLine[x].append(board[x][y])
                noteColumn[y].append(board[x][y])
                noteGrid[gridIndex].append(board[x][y])
                if y==8:
                    if not self.sudokuRule(noteLine[x]):
                        return False
                if x==8:
                    if not self.sudokuRule(noteColumn[y]):
                        return False
                if x%3==2 and y%3==2:
                    if not self.sudokuRule(noteGrid[gridIndex]):
                        return False
        return True
```

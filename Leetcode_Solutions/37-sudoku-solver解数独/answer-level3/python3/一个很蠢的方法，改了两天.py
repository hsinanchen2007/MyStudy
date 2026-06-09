非递归回溯，改了两天都心态快崩了，还是递归的方法好
```
class Solution:
    def solveSudoku(self, board: List[List[str]]) -> None:
        """
        Do not return anything, modify board in-place instead.
        """
        stack1 = []
        row = []
        col = []
        Sudoku = []
        a = []
        for i in range(9):
            temprow = {'1','2','3','4','5','6','7','8','9'}
            row.append(temprow)
            tempcol = {'1','2','3','4','5','6','7','8','9'}
            col.append(tempcol)
            tempSudoku = {'1','2','3','4','5','6','7','8','9'}
            Sudoku.append(tempSudoku)
        for i in range(9):
            a.append([])
            for j in range(9):
                a[i].append([])
                if board[i][j]=='.':
                    continue
                else:
                    row[i].remove(board[i][j])
                    col[j].remove(board[i][j])
                    Sudoku[i//3*3+j//3].remove(board[i][j])
        i, j = 0, 0
        tempbool = False
        while i<9:
            while j<9:
                if i==9:
                    return None
                if board[i][j]=='.':
                    tempset = row[i]&col[j]&Sudoku[i//3*3+j//3]
                    if not a[i][j] and tempset and not tempbool:
                        a[i][j] = list(tempset)
                        tempindex = a[i][j][0]
                        a[i][j] = a[i][j][1:]
                        row[i].remove(tempindex)
                        col[j].remove(tempindex)
                        Sudoku[i//3*3+j//3].remove(tempindex)
                        temp = [tempindex,i,j]
                        stack1.append(temp)
                        board[i][j] = tempindex
                        tempbool = False
                        j = j+1
                        if j==9:
                            i = i+1
                            j = 0
                    elif not a[i][j]:
                        tempbool = True
                        if stack1:
                            templist = stack1.pop()
                            tempindex = templist[0]
                            tempi = templist[1]
                            tempj = templist[2]
                            board[tempi][tempj] = '.'
                            i = tempi
                            j = tempj
                            row[i].add(tempindex)
                            col[j].add(tempindex)
                            Sudoku[i//3*3+j//3].add(tempindex)
                    else:
                        tempindex = a[i][j][0]
                        a[i][j] = a[i][j][1:]
                        tempbool = False
                        row[i].remove(tempindex)
                        col[j].remove(tempindex)
                        Sudoku[i//3*3+j//3].remove(tempindex)
                        temp = [tempindex,i,j]
                        stack1.append(temp)
                        board[i][j] = tempindex
                        j = j+1
                        if j==9:
                            i = i+1
                            j = 0
                else:
                    j = j+1
                    if j==9:
                        i = i+1
                        j = 0
```

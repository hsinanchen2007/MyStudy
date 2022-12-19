# 基本思路：
遍历点，寻找解
# 约束条件：
行约束，列约束，块约束。board对应行约束，对应生成列约束和块约束的List

```python []
class Solution:
    def solveSudoku(self, board: List[List[str]]) -> None:
        def sudoku(DotIndex):
            if DotIndex==len(Dot):  return True
            for ii in range(9):
                s = str(ii+1)
                block_index_row = 3*(Dot[DotIndex][0]//3)+Dot[DotIndex][1]//3
                block_index_col = Dot[DotIndex][0]%3*3+Dot[DotIndex][1]%3
                if (s not in board[Dot[DotIndex][0]]) and (s not in boardT[Dot[DotIndex][1]]) and (s not in block[block_index_row]):
                    board[Dot[DotIndex][0]][Dot[DotIndex][1]] = s
                    boardT[Dot[DotIndex][1]][Dot[DotIndex][0]] = s
                    block[block_index_row][block_index_col] = s
                    if sudoku(DotIndex+1):  return True
                    board[Dot[DotIndex][0]][Dot[DotIndex][1]] = '.'
                    boardT[Dot[DotIndex][1]][Dot[DotIndex][0]] = '.'
                    block[block_index_row][block_index_col] = '.'
            return False

        boardT = [[j[i] for j in board] for i in range(9)]
        block = [board[3*i][3*j:3*j+3] + board[3*i+1][3*j:3*j+3] + board[3*i+2][3*j:3*j+3] for i in range(3) for j in range(3)]
        Dot = [[i,j] for i in range(9) for j in range(9) if board[i][j]=='.']
        sudoku(0)
```

### 解题思路
row[i] 第 i 行有哪些数字
col[j] 第 j 列有哪些数字
sqr[i][j] 第 i 行 j 列的 9 宫格里有哪些数字


### 代码

```python
class Solution:
    def solveSudoku(self, board: List[List[str]]) -> None:
        """
        Do not return anything, modify board in-place instead.
        """
        col = [set() for i in range(9)]
        row = [set() for i in range(9)]
        sqr = [[set() for i in range(3)] for i in range(3)]
        for i in range(9):
            for j in range(9):
                if board[i][j] != '.':
                    col[j].add(board[i][j])
                    row[i].add(board[i][j])
                    sqr[i//3][j//3].add(board[i][j])
        
        def dfs(i, j):
            if board[i][j] != '.':
                if i == 8 and j == 8:
                    self.flag = True
                    return
                if j < 8:
                    dfs(i, j+1)
                else:
                    dfs(i+1, 0)
                return
            #print(row[i])
            #print(col[j])
            #print(sqr[i//3][j//3])
            #print(board)
            #for l in board:print(l)
            #input()
            for ch in range(1, 10):
                ch = str(ch)
                if ch not in col[j] and ch not in row[i] and ch not in sqr[i//3][j//3]:
                    #print(i, j, ch)
                    col[j].add(ch)
                    row[i].add(ch)
                    sqr[i//3][j//3].add(ch)
                    board[i][j] = ch
                    if i == 8 and j == 8:
                        self.flag = True
                        return
                    if j < 8:
                        dfs(i, j+1)
                    else:
                        dfs(i+1, 0)
                    if self.flag: return
                    board[i][j] = '.'
                    col[j].remove(ch)
                    row[i].remove(ch)
                    sqr[i//3][j//3].remove(ch)
        self.flag = False
        dfs(0, 0)
```
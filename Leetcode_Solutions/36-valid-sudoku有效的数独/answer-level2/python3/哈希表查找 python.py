### 解题思路
题目转化为，1-9是否已经存在在横列表，竖列表，方形列表中，
如果已经存在，那么就说明重复了。

一想到是查找，那就是哈希表了，即python中的字典

### 代码

```python3
class Solution:
    def isValidSudoku(self, board: List[List[str]]) -> bool:
        row = len(board)
        col = len(board[0])
        rowtable = {i:[] for i in range(row)}
        coltable = {i:[] for i in range(col)}
        squaretable = {(i,j):[] for i in range(3) for j in range(3)}
        for r in range(row):
            for c in range(col):
                if board[r][c] == '.':
                    continue
                if board[r][c] in rowtable[r]:
                    return False
                else:
                    rowtable[r].append(board[r][c])
                if board[r][c] in coltable[c]:
                    return False
                else:
                    coltable[c].append(board[r][c])
                if board[r][c] in squaretable[(r//3,c//3)]:
                    return False
                else:
                    squaretable[(r//3,c//3)].append(board[r][c])
        return True

```
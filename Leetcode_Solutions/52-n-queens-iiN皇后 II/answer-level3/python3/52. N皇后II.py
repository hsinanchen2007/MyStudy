### 解题思路
修改上题的代码，修改添加方案这个函数即可。

### 代码

```python3
class Solution:
    def totalNQueens(self, n: int) -> int:
        def could_place(row, col):
            return not (cols[col] + hill_diagonals[row - col] + dale_diagonals[row + col])
        
        def place_queen(row, col):
            queens.add((row, col))
            cols[col] = 1
            hill_diagonals[row - col] = 1
            dale_diagonals[row + col] = 1
        
        def remove_queen(row, col):
            queens.remove((row, col))
            cols[col] = 0
            hill_diagonals[row - col] = 0
            dale_diagonals[row + col] = 0
        
        def add_solution():
            nonlocal output
            output+=1
        
        def backtrack(row = 0):
            for col in range(n):
                if could_place(row, col):
                    place_queen(row, col) #放置皇后
                    if row + 1 == n:  #最后一行的皇后也安排好了，添加方案
                        add_solution()
                    else:
                        backtrack(row + 1)  #安排下一行的皇后
                    remove_queen(row, col) #清除皇后
        
        cols = [0] * n
        hill_diagonals = [0] * (2 * n - 1) #这里巧妙在于row-col为负，可以索引列表
        dale_diagonals = [0] * (2 * n - 1) 
        queens = set()
        output = 0
        backtrack()
        return output
```
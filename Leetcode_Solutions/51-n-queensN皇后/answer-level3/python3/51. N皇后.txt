### 解题思路
这种比较大规模的回溯，和之前的解数独题一样，会把约束条件提前用适当的数据结构保存着，这样在回溯过程中就会更快，无论是集合还是这里的列表，总的来说都是哈希的思想，把当前位置输入进去，能够查到约束的情况。下面是官方代码。

### 代码

```python3
class Solution:
    def solveNQueens(self, n: int) -> List[List[str]]:
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
            solution = []
            for _, col in sorted(queens):
                solution.append('.' * col + 'Q' + '.' * (n - col - 1))
            output.append(solution)
        
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
        output = []
        backtrack()
        return output
```
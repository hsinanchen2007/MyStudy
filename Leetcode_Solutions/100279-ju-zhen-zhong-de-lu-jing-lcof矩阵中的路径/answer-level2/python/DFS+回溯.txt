一起组队刷题打卡，微博 [@爱编程的周鸟](https://weibo.com/iosxxoo) 求关注求交流。

### 代码
```python
# -*- coding:utf-8 -*-
def DFS(matrix, row, col, path, visited):
    if row < 0 or row >= len(matrix) or col < 0 or col >= len(matrix[0]) or (row, col) in visited: 
        return False
    if path[0] == matrix[row][col]:
        if len(path) == 1:
            return True
        return DFS(matrix, row+1, col, path[1:], visited| {(row, col)}) or \
            DFS(matrix, row-1, col, path[1:], visited| {(row, col)}) or \
            DFS(matrix, row, col-1, path[1:], visited| {(row, col)}) or \
            DFS(matrix, row, col+1, path[1:], visited| {(row, col)})

class Solution:
    def exist(self, board: List[List[str]], word: str) -> bool:
        """
        :type board: List[List[str]]
        :type word: str
        :rtype: bool
        """
        path = word
        rows = len(board)
        cols = len(board[0])
        for i in range(rows):
            for j in range(cols):
                visited = set()
                if DFS(board, i, j, list(path), visited): 
                    return True
        return False
```

### 解题思路
模拟如何获取螺旋矩阵的步骤:
定义四个方向: ['row_plus','col_minus','row_minus','col_plus']
我们发现，**每一次经过行增方向或者行减方向时，行进的距离都会减少1**，初始的距离是len(matrix)-1。
比如第一次行增时，行进len(matrix)-1个单位;第二次行减时，行进len(matrix)-2个单位。
同理，每一次经过列增方向和列减方向时，行进的距离同样会减少1。

我们设置初始点是(0,0),即可模拟这个过程了。

### 代码

```python3
class Solution:
    def spiralOrder(self, matrix: list) -> list:
        if len(matrix) == 0: return []
        option = ['row_plus','col_minus','row_minus','col_plus']
        result = [i for i in matrix[0]]
        move_col, move_row = len(matrix[0]), len(matrix)
        start = [1, len(matrix[0])-1]
        while 1:
            for opt in option:
                if opt == 'row_plus':
                    move_row -= 1
                    if move_row <= 0:
                        return result
                    for i in range(move_row):
                        result.append(matrix[start[0]][start[1]])
                        start = [start[0]+1,start[1]]
                    start = [start[0]-1, start[1]-1]
                elif opt == 'col_minus':
                    move_col -= 1
                    if move_col <= 0:
                        return result
                    for i in range(move_col):
                        result.append(matrix[start[0]][start[1]])
                        start = [start[0], start[1]-1]
                    start = [start[0]-1, start[1]+1]
                elif opt == 'row_minus':
                    move_row -= 1
                    if move_row <= 0:
                        return result
                    for i in range(move_row):
                        result.append(matrix[start[0]][start[1]])
                        start = [start[0]-1, start[1]]
                    start = [start[0]+1, start[1]+1]
                else:
                    move_col -= 1
                    if move_col <= 0:
                        return result
                    for i in range(move_col):
                        result.append(matrix[start[0]][start[1]])
                        start = [start[0],start[1]+1]
                    start = [start[0]+1, start[1]-1]







```
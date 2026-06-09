### 解题思路
如果横向出现重复，纵向出现重复，或者3X3方形内出现重复，则返回False
最后如果上述情况都没出现，返回True
在两层循环内同时遍历这三组数据：
```
for i in range(0, 9):
    for j in range(0, 9):
```
横向的数据索引为i, j
纵向的数据索引为j, i
3X3方形内的数据索引为**3X(i//3)+j//3, 3X(i%3)+j%3**


### 代码

```python3
class Solution:
    def isValidSudoku(self, board: List[List[str]]) -> bool:
        for i in range(0, 9):
            horizontal = []
            vertical = []
            box = []
            for j in range(0, 9):
                if board[i][j] in horizontal:  # 
                    return False
                else:
                    if board[i][j] != '.':
                        horizontal.append(board[i][j])
                if board[j][i] in vertical:
                    return False
                else:
                    if board[j][i] != '.':
                        vertical.append(board[j][i])
                if board[3*(i//3)+j//3][3*(i%3)+j%3] in box:
                    return False
                else:
                    if board[3*(i//3)+j//3][3*(i%3)+j%3] != '.':
                        box.append(board[3*(i//3)+j//3][3*(i%3)+j%3])
        return True
```
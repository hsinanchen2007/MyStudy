### 解题思路
用list在循环里直接查询

### 代码

```python3
class Solution:
    def isValidSudoku(self, board: List[List[str]]) -> bool:
        box = [[]for i in range(9)]
        row = [[]for i in range(9)]
        col = [[]for i in range(9)]
        for i in range(9):
            for j in range(9):
                s = board[i][j]
                if s != '.':
                    num = int(s)
                    box_index = i//3 *3 + j//3

                    if (num in row[i]) or (num in col[j]) or (num in box[box_index]):
                        return False

                    row[i].append(num)
                    col[j].append(num)
                    box[box_index].append(num)
        return True
                    



```
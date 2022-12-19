### 解题思路
box_index那个地方就不是很明白

### 代码

```python3
class Solution:
    def isValidSudoku(self, board: List[List[str]]) -> bool:
        row_count = [[0 for i in range(9)] for j in range(9)]
        col_count = [[0 for i in range(9)] for j in range(9)]
        box_count = [[0 for i in range(9)] for j in range(9)]

        for i in range(9):
            for j in range(9):
                num = board[i][j]
                if num != '.':
                    num = int(num)
                    box_index = (i // 3) * 3 + j // 3

                    row_count[i][num-1] += 1
                    col_count[j][num-1] += 1
                    box_count[box_index][num-1] += 1


                    print(box_count)
                    if row_count[i][num-1] > 1 or col_count[j][num-1] > 1 or box_count[box_index][num-1] > 1:
                        return False
        
        return True
```
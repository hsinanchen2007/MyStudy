### 解题思路
此处撰写解题思路

### 代码

```python3
from typing import List
import copy


class Solution:
    def solveSudoku(self, board: List[List[str]]) -> None:
        """
        Do not return anything, modify board in-place instead.
        """
        r_map = []
        c_map = []
        k_map = []
        new_set = set((1, 2, 3, 4, 5, 6, 7, 8, 9))
        visited = []
        for i in range(9):
            r_map.append(copy.deepcopy(new_set))
            c_map.append(copy.deepcopy(new_set))
            k_map.append(copy.deepcopy(new_set))

        def put_one(i, j, val):
            r_map[i].remove(val)
            c_map[j].remove(val)
            k_map[(i // 3) * 3 + j // 3].remove(val)
            board[i][j] = str(val)

        def remove_one(i, j, val):
            r_map[i].add(val)
            c_map[j].add(val)
            k_map[(i // 3) * 3 + j // 3].add(val)
            board[i][j] = '.'

        for i in range(9):
            for j in range(9):
                if board[i][j] != '.':
                    val = int(board[i][j])
                    put_one(i, j, val)

        def get_can_used(i, j):
            return r_map[i] & c_map[j] & k_map[(i // 3) * 3 + j // 3]

        def get_one():
            for i in range(9):
                for j in range(9):
                    if board[i][j] == '.':
                        return i, j

            return -1, -1

        def recursive():
            row, col = get_one()

            if (row, col) == (-1, -1):
                return 0

            can_use = get_can_used(row, col)
            for i in can_use:
                put_one(row, col, i)
                result = recursive()
                if result == 0:
                    return 0
                else:
                    remove_one(row, col, i)

        recursive()
```
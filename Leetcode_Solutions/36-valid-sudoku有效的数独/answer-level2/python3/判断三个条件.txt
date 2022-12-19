### 解题思路


### 代码

```python3
class Solution:
    def isValidSudoku(self, board: List[List[str]]) -> bool:
        if not board:
            return
        # raw = [set() for _ in range(9)]
        col = [set() for _ in range(9)]

        for i in range(3):
            raw = [set() for _ in range(3)]
            for j in range(3):
                Set = set()
                for _i in range(3):
                    for _j in range(3):
                        x = i * 3 + _i
                        y = j * 3 + _j
                        if board[x][y] != '.':
                            if board[x][y] in Set or board[x][y] in raw[x%3] or board[x][y] in col[y]:
                                return False
                            else:
                                Set.add(board[x][y])
                                raw[x%3].add(board[x][y])
                                col[y].add(board[x][y])
        return True
```
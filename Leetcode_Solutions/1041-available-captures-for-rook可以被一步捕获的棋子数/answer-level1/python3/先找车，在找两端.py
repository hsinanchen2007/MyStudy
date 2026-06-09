### 解题思路
此处撰写解题思路

### 代码

```python3
from typing import List


class Solution:
    def numRookCaptures(self, board: List[List[str]]) -> int:
        count = 0
        for i in range(board.__len__()):
            for j in range(board[i].__len__()):
                if board[i][j] == "R":
                    count += self.get_count(board[i], j-1, -1, ascending=False)
                    count += self.get_count(board[i], j+1, 8, ascending=True)
                    count += self.get_count(board, i-1, -1, column=j, ascending=False)
                    count += self.get_count(board, i+1, 8, column=j, ascending=True)

        return count

    def get_count(self, board, start, end, column=None, ascending=True):
        count = 0
        delta = 1 if ascending else -1
        for i1 in range(start, end, delta):
            temp_board = board[i1] if not column else board[i1][column]
            if temp_board == "B":
                break
            elif temp_board == "p":
                count += 1
                break
            else:
                continue
        return count
```
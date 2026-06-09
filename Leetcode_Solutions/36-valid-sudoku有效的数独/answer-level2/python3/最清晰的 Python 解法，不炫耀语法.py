```
class Solution:
    def isValidSudoku(self, board: List[List[str]]) -> bool:
        """
        这道题的关键就在于小格子也是可以用 i 和 j 来计算的：
        box_index = (row / 3) * 3 + columns / 3
        """
        used_i = [[0] * 9 for _ in range(9)]
        used_j = [[0] * 9 for _ in range(9)]
        used_k = [[0] * 9 for _ in range(9)]
        for i in range(9):
            for j in range(9):
                piece = board[i][j]
                if piece == ".":
                    continue
                n = int(piece) - 1
                k = i // 3 * 3 + j // 3
                if used_i[i][n] or used_j[j][n] or used_k[k][n]:
                    return False
                used_i[i][n] = used_j[j][n] = used_k[k][n] = 1
        return True
```

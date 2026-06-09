```
class Solution:
    def exist(self, board, word: str) -> bool:
        def backtrack(n, i, j, visited):
            if n == len(word):
                return True
            for ii, jj in [(1, 0), (-1, 0), (0, 1), (0, -1)]:
                _i, _j = i + ii, j + jj
                if 0 <= _i < r and 0 <= _j < c and board[_i][_j] == word[n] and (_i, _j) not in visited:
                    res = backtrack(n + 1, _i, _j, visited | {(_i, _j)})
                    if res:
                        return res

        r, c = len(board), len(board) and len(board[0])
        for i in range(r):
            for j in range(c):
                if word[0] == board[i][j]:
                    if backtrack(1, i, j, {(i, j)}):
                        return True
        return False

```

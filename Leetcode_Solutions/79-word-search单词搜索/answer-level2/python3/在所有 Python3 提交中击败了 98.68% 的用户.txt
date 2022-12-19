### 解题思路
不断循环，兄弟们
### 代码

```python3
class Solution:
    def exist(self, board, word: str) -> bool:
        m = len(board)
        n = len(board[0])
        for row in range(len(board)):
            for col in range(len(board[0])):
                c = word[0]
                if board[row][col] == c:
                    hitmap_copy = [[0] * n for i in range(m)]
                    hitmap_copy[row][col] = 1
                    semi_res = self.lookaround(board, hitmap_copy, 2, word, row, col)
                    if semi_res == True:
                        return True

        return False

    def lookaround(self, board, hitmap, n, word, row, col):
        if n > len(word):
            return True
        up, down, left, right = False, False, False, False
        if row > 0 and board[row - 1][col] == word[n - 1] and hitmap[row - 1][col] == 0:
            hitmap[row - 1][col] = 1
            up = self.lookaround(board, hitmap, n + 1, word, row - 1, col)
            if up == True:
                return True
            hitmap[row - 1][col] = 0

        if row < len(board) - 1 and board[row + 1][col] == word[n - 1] and hitmap[row + 1][col] == 0:
            hitmap[row + 1][col] = 1
            down = self.lookaround(board, hitmap, n + 1, word, row + 1, col)
            if down == True:
                return True
            hitmap[row + 1][col] = 0

        if col > 0 and board[row][col - 1] == word[n - 1] and hitmap[row][col - 1] == 0:
            hitmap[row][col - 1] = 1
            left = self.lookaround(board, hitmap, n + 1, word, row, col - 1)
            if left == True:
                return True
            hitmap[row][col - 1] = 0

        if col < len(board[0]) - 1 and board[row][col + 1] == word[n - 1] and hitmap[row][col + 1] == 0:
            hitmap[row][col + 1] = 1
            right = self.lookaround(board, hitmap, n + 1, word, row, col + 1)
            if right == True:
                return True
            hitmap[row][col + 1] = 0

        return False
```
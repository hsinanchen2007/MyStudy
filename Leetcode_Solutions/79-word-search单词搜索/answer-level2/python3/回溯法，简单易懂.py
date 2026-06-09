```python
class Solution:
    def exist(self, board: List[List[str]], word: str) -> bool:
        result = [False]
        if len(board) == 0 or len(board[0]) == 0: return False
        for i in range(len(board)):
            for j in range(len(board[0])):
                self.dfs(board, i, j, word, 0, result)
                if result[0]:
                    return True
        return result[0]


    def dfs(self, board, row, col, word, index, result):
        if result[0] or index == len(word):
            result[0] = True
            return
        
        if row < 0 or row >= len(board) or col < 0 or col >= len(board[0]) or board[row][col] != word[index]:
            return
        char = board[row][col]
        board[row][col] = '#'
        self.dfs(board, row - 1, col, word, index + 1, result)
        self.dfs(board, row + 1, col, word, index + 1, result)
        self.dfs(board, row, col - 1, word, index + 1, result)
        self.dfs(board, row, col + 1, word, index + 1, result)
        board[row][col] = char
        return

```

### 解题思路
思路参考JZoffer

### 代码

```python3
class Solution:
    def exist(self, board: List[List[str]], word: str) -> bool:
        rows = len(board)
        cols = len(board[0])
        if not rows:
            return 0
        mark = [[False for _ in range(cols)] for _ in range(rows)]
        word_idx = 0
        for row in range(rows):
            for col in range(cols):
                if self.pathCore(row, rows, col, cols, board, word, mark, word_idx):
                    return True
        return False

    def pathCore(self, row, rows, col, cols, board, word, mark, word_idx):
        if word_idx >= len(word):
            return True
        hasPath = False
        if 0 <= row < rows and 0 <= col < cols and not mark[row][col] \
            and board[row][col] == word[word_idx]:
            word_idx += 1
            mark[row][col] = True
            hasPath = self.pathCore(row+1, rows, col, cols, board, word, mark, word_idx) \
                   or self.pathCore(row-1, rows, col, cols, board, word, mark, word_idx) \
                   or self.pathCore(row, rows, col+1, cols, board, word, mark, word_idx) \
                   or self.pathCore(row, rows, col-1, cols, board, word, mark, word_idx) \
            
            if not hasPath:
                word_idx -= 1
                mark[row][col] = False
        return hasPath
    
```
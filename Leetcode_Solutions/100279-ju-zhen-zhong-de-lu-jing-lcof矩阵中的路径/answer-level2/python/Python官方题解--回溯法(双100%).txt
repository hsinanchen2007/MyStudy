![image.png](https://pic.leetcode-cn.com/22cb373b13ff78536aa6a4379fecebd3cc226d29dde268deeb09a59ee47225f8-image.png)


```python
class Solution(object):
    def exist(self, board, word):
        """
        :type board: List[List[str]]
        :type word: str
        :rtype: bool
        """
        if not board and not word:
            return False
        visited = [[0]*len(board[0]) for _ in range(len(board))]
        rows = len(board)
        cols = len(board[0])
        for row in range(len(board)):
            for col in range(len(board[0])):
                if self.search(row, col, rows, cols, board, word, visited):
                    return True
        return False
    
    def search(self,row, col, rows, cols, board, word, visited):
        if not word:
            return True
        hasPath = False
        if col >= 0 and col < cols and row >= 0 and row < rows and (not visited[row][col]) and word[0] == board[row][col]:
            visited[row][col] = 1
            hasPath = self.search(row-1, col, rows, cols, board, word[1:], visited) or self.search(row+1, col, rows, cols, board, word[1:], visited) \
            or self.search(row, col-1, rows, cols, board, word[1:], visited) or self.search(row, col+1, rows, cols, board, word[1:], visited)
            if not hasPath:
                visited[row][col] = 0
        return hasPath
            


            
















        
```
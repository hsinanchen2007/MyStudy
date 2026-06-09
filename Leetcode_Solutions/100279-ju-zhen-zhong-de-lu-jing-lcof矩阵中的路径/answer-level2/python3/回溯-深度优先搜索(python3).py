### 效率
![回溯.jpg](https://pic.leetcode-cn.com/2477d74ddf54c758785e0093b8863b3bc2d80af5c75ae2138eaec65a43e2061d-%E5%9B%9E%E6%BA%AF.jpg)

### 解题思路
```python3
class Solution:
    def exist(self, board: List[List[str]], word: str) -> bool:
        if not board or not board[0]: return False
        rows, cols = len(board), len(board[0])
        # 如果word的长比矩阵所有元素还多，必然不存在word
        if len(word) > rows * cols: return False
        # 记录访问足迹
        visited = [[False for _ in range(cols)] for _ in range(rows)]
        start = 0
        res = False
        # 每一个 board 开始的头， 和 word 从头到尾匹配
        for r in range(rows):
            for c in range(cols):
                if board[r][c] == word[start]:
                    visited[r][c] = True
                    res = res or self._dfs(r, c, board, word, visited, start + 1)
                    # 当前格子搜索完后退出，置 False
                    visited[r][c] = False
        return res
    
    # 深度优先搜索
    def _dfs(self, r, c, board, word, visited, start):
        # 但全部单词搜索完，结束
        if start == len(word):
            return True
        res = False
        rows, cols = len(board), len(board[0])
        # 搜索 (r, c) 的上下左右邻居 (nr, nc)
        for nr, nc in ((r + 1, c), (r - 1, c), (r, c + 1), (r, c - 1)):
            if 0 <= nr < rows and 0 <= nc < cols and board[nr][nc] == word[start] and not visited[nr][nc]:
                visited[nr][nc] = True
                res = res or self._dfs(nr, nc, board, word, visited, start + 1)
                visited[nr][nc] = False
        return res
```
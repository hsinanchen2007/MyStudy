### 解题思路
深度优先搜索，只有一个结束条件：如果探索的长度与字符串长度相等，那么一路返回True
如果在搜索过程中，某一个字符搜索不下去了，那么回溯，visited[i][j] = False， pos -= 1
对于数组里的每一个等于字符串的首字母的字符进行深搜
只要有一个深搜的结果为True，那么return True
数组中所有字符都遍历完毕还没有找到结果，return False
### 代码

```python3
class Solution:
    def exist(self, board: List[List[str]], word: str) -> bool:
        if board and word:
            m = len(board)
            n = len(board[0])
            pos = 0

            visited = [[False for j in range(n)] for i in range(m)]

            def dfs(i, j):
                nonlocal pos
                pos += 1
                visited[i][j] = True
                if pos == len(word):
                    return True

                for k, l in ((-1, 0), (0, 1), (1, 0), (0, -1)):
                    if 0 <= i + k < m and 0 <= j + l < n and not visited[i + k][j + l] \
                            and board[i + k][j + l] == word[pos]:
                        if dfs(i + k, j + l):
                            return True

                visited[i][j] = False
                pos -= 1

            for i in range(m):
                for j in range(n):
                    if board[i][j] == word[0]:
                        pos = 0
                        visited = [[False for j in range(n)] for i in range(m)]

                        if dfs(i, j):
                            return True

        return False
```
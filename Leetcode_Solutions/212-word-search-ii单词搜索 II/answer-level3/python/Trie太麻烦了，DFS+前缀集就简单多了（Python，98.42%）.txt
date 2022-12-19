把各单词的前缀加入到一个集合中，然后直接检查DFS中得到的前缀在该集合中是否存在。效率可能比Trie低一点，但Python还是在98%以上

```python
class Solution:
    def findWords(self, board: List[List[str]], words: List[str]) -> List[str]:
        if not board:
            return []

        prefix_set = set()
        words = set(words)

        for w in words:
            for i in range(1, len(w) + 1):
                prefix_set.add(w[0:i])

        m = len(board)
        n = len(board[0])

        visited = [[False for _ in range(n)] for _ in range(m)]

        ans = set()

        def search(x, y, prefix):
            if visited[x][y]:
                return

            ch = board[x][y]
            prefix += ch

            if prefix not in prefix_set:
                return

            if prefix in words:
                ans.add(prefix)

            visited[x][y] = True

            if y + 1 < n:
                search(x, y + 1, prefix)

            if x + 1 < m:
                search(x + 1, y, prefix)

            if y - 1 >= 0:
                search(x, y - 1, prefix)

            if x - 1 >= 0:
                search(x - 1, y, prefix)

            visited[x][y] = False

        for i in range(m):
            for j in range(n):
                search(i, j, "")

        return list(ans)
```

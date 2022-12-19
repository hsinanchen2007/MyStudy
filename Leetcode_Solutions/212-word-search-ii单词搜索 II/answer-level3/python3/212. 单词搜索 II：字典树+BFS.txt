一遍过了，没啥优化，就是先把词存进字典，然后遍历矩阵，对前缀进行宽搜，优化的点在于对字典树删词，有点麻烦就没做。

```python []
class Solution:
    def findWords(self, board: List[List[str]], words: List[str]) -> List[str]:
        d = {}
        for s in words:
            t = d
            for c in s:
                if c not in t:
                    t[c] = {}
                t = t[c]
            t['word'] = s
        ans = []
        def bfs(i, j):
            que = [([(i, j)], d[board[i][j]])]
            tmp_ans = []
            while que:
                tmp = []
                for vst, t in que:
                    if 'word' in t:
                        ans.append(t.pop('word'))
                    xi, yi = vst[-1]
                    for x, y in [(xi + 1, yi), (xi - 1, yi), (xi, yi + 1), (xi, yi - 1)]:
                        if 0 <= x < m and 0 <= y < n and (x, y) not in vst and board[x][y] in t:
                            tmp += [(vst + [(x, y)], t[board[x][y]])]
                que = tmp
        m, n = len(board), len(board[0])
        for i in range(m):
            for j in range(n):
                if board[i][j] in d:
                    bfs(i, j)
        return sorted(ans)
```

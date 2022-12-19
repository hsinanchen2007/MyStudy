## 思路:

思路一：BFS

思路二：DFS

感觉第二种也是BFS !

## 代码

思路一：

```python
class Solution:
    def minMutation(self, start: str, end: str, bank: List[str]) -> int:
        from collections import deque
        bank = set(bank)
        if end not in bank:
            return -1
        visited = set()
        visited.add(start)
        mutation = {"A", "C", "G", "T"}

        # 产生只差一个字母的基因
        def oneMutation(cur):
            for i, val in enumerate(cur):
                for t in mutation - {val}:
                    tmp = cur[:i] + t + cur[i + 1:]
                    if tmp in bank:
                        yield tmp

        queue = deque()
        queue.appendleft([start, 0])
        while queue:
            cur, res = queue.pop()
            if cur == end:
                return res
            for nxt in oneMutation(cur):
                if nxt not in visited:
                    visited.add(nxt)
                    queue.appendleft((nxt, res + 1))
        return -1
```

思路二：

```python
class Solution:
    def minMutation(self, start: str, end: str, bank: List[str]) -> int:
        bank = set(bank)

        if end not in bank:
            return -1
        visited = set()
        visited.add(start)
        mutation = {"A", "C", "G", "T"}

        def honeMutation(cur):
            for i, val in enumerate(cur):
                for t in mutation - {val}:
                    tmp = cur[:i] + t + cur[i + 1:]
                    if tmp in bank:
                        yield tmp

        def dfs(s):
            if s == end:
                return 0
            res = float("inf")
            for nxt in honeMutation(s):
                if nxt not in visited:
                    visited.add(nxt)
                    res = min(res, 1 + dfs(nxt))
                    visited.remove(nxt)
            return res

        res = dfs(start)
        return res if res != float("inf") else -1
```


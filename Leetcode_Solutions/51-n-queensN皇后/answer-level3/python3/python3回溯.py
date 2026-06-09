### 回溯算法，每次只记录每列Queen放置的位置。
见代码

### 代码

```python3
class Solution:
    def solveNQueens(self, n: int) -> List[List[str]]:
        res = []

        def dfs(tmp, row):
            nonlocal res
            if row == n:
                reslist = []
                for b in tmp:
                    reslist.append('.' * b + 'Q' + '.' * (n - 1 - b))
                res.append(list(reslist))
                return
            for col in range(n):
                flag = True
                for a, b in enumerate(tmp):
                    if row == a or col == b or row - a == col - b or a - row == col - b:
                        flag = False
                        break
                if not flag: continue
                # tmp.append((row, col))
                dfs(tmp + [col], row + 1)
                # tmp.pop()
        dfs([], 0)
        return res
```
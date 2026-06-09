### 解题思路
dfs搜索的组合问题

### 代码

```python3
class Solution:
    def combine(self, n: int, k: int) -> List[List[int]]:
        def dfs(res, tmp, k, cur):
            if k == 0:
                res.append(tmp.copy())
            for i in range(cur, n+1):
                tmp.append(i)
                dfs(res, tmp, k-1, i+1)
                tmp.pop()
        res = []
        dfs(res, [], k, 1)
        return res
```
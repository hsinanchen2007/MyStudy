### 解题思路
比较基础的DFS。

### 代码

```python
class Solution:
    def movingCount(self, m: int, n: int, k: int) -> int:
        seen = set()
        def d_sum(x):
            return sum(map(int, list(str(x))))
        self.res = 0
        def dfs(i, j):
            if 0 <= i < m and 0 <= j < n and (i, j) not in seen:
                seen.add((i, j))
                if d_sum(i) + d_sum(j) <= k:
                    self.res +=1
                    for x, y in [(i+1, j), (i-1, j), (i, j+1), (i, j-1)]:
                        dfs(x, y)
        
        dfs(0, 0)
        return self.res
                
                
```
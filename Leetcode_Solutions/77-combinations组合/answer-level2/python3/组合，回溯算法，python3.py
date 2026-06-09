### 解题思路
回溯算法都长得差不多

### 代码

```python3
class Solution:
    def combine(self, n: int, k: int) -> List[List[int]]:
        def backtrack(N, K, temp):
            if K == 0:
                res.append(temp)
                return
            for i in range(N, n+1):
                backtrack(i+1, K-1, temp+[i])
        res = []
        backtrack(1, k, [])
        return res
```
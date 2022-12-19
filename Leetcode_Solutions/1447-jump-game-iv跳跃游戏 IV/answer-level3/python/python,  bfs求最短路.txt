```python
from collections import defaultdict

class Solution:
    def minJumps(self, arr: List[int]) -> int:
        d = defaultdict(list)
        n = len(arr)

        for i in range(n):
            d[arr[i]].append(i)

        vis = [0] * n
        vis[0] = 1
        q = [(0, 0)]
        while q:
            i, k = q.pop(0)
            for j in d[arr[i]] + [i - 1, i + 1]:
                if j < 0 or j >= n or vis[j]:
                    continue
                if j == n - 1:
                    return k + 1
                vis[j] = 1
                q.append((j, k + 1))
            d[arr[i]] = []

        return 0
```

### 解题思路
此处撰写解题思路

### 代码

```python3
class Solution:
    def findCheapestPrice(self, n: int, flights: List[List[int]], src: int, dst: int, K: int) -> int:
        # 贝尔曼-福特算法
        from copy import deepcopy
        res = [float("inf")] * n
        K = min(K, n - 2)
        res[src] = 0
        for k in range(K + 1):
            ans = deepcopy(res)
            for f in flights:
                ans[f[1]] = min(ans[f[1]], res[f[0]] + f[2])
            res = deepcopy(ans)
        return res[dst] if res[dst] != float("inf") else -1       

```
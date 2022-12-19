### 解题思路
此处撰写解题思路

### 代码

```python3
class Solution:
    def frogPosition(self, n: int, edges: List[List[int]], t: int, target: int) -> float:
        g = [[] for _ in range(n)]
        for e in edges:
            g[min(e) - 1].append(max(e) - 1)

        def dfs(node, deep, t, target, p):
            if deep >= t:
                return p if node == target else 0

            if not g[node]:
                return dfs(node, deep + 1, t, target, p)

            return max(
                dfs(i, deep + 1, t, target, p * float(1 / len(g[node])))
                for i in g[node])

        return dfs(0, 0, t, target - 1, 1)

```
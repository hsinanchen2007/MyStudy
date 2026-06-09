### 解题思路
由叶子向根过滤节点

### 代码

```python3
class Solution:
    def findMinHeightTrees(self, n: int, edges: List[List[int]]) -> List[int]:
        indegree = [0 for _ in range(n)]
        adj = [[] for _ in range(n)]
        queue = []
        for i,j in edges:
            adj[i].append(j)
            adj[j].append(i)
            indegree[i] += 1
            indegree[j] += 1
        for i in range(n):
            if indegree[i] == 1:
                queue.append(i)
        if n == 1:
            return [0]
        if n == 2:
            return [0, 1]
        while n > 2:
            l = len(queue)
            n -= l
            for i in range(l):
                v = queue.pop(0)
                for j in adj[v]:
                    indegree[j] -= 1
                    if indegree[j] == 1:
                        queue.append(j)
        return queue
```
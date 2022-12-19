### 解题思路
图的深度优先遍历

### 代码

```python3
"""
# Definition for a Node.
class Node:
    def __init__(self, val = 0, neighbors = []):
        self.val = val
        self.neighbors = neighbors
"""
class Solution:
    def cloneGraph(self, node: 'Node') -> 'Node':
        a = {}

        def dfs(node):
            if not node: return
            if node in a:
                return a[node]
            clone = Node(node.val, [])
            a[node] = clone
            for n in node.neighbors:
                clone.neighbors.append(dfs(n))

            return clone

        return dfs(node)
```
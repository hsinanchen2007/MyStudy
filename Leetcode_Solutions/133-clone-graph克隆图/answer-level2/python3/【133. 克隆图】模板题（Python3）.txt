## 思路

题目非常简单，没有啥好说的。 DFS和BFS都可以。 但是DFS写起来比较简单，推荐大家DFS。

我们使用普通的DFS去做，然后用一个hashmap存储访问过的节点，防止成环即可。

## 代码

```python
"""
# Definition for a Node.
class Node:
    def __init__(self, val = 0, neighbors = []):
        self.val = val
        self.neighbors = neighbors
"""
class Solution:
    def dfs(self, node: 'Node') -> 'Node':
        if not node: return node
        if node.val in self.visited: return self.visited.get(node.val)
        ans = Node(node.val)
        self.visited[node.val] = ans

        for neighbor in node.neighbors:
            ans.neighbors.append(self.dfs(neighbor))
        return ans
    def cloneGraph(self, node: 'Node') -> 'Node':
        self.visited = dict()
        return self.dfs(node)
        
```


**复杂度分析**
- 时间复杂度：$O(N)$
- 空间复杂度：$O(N)$


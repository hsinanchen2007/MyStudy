### 解题思路
1. 从原图给定的点找到所有点
2. 复制所有的点
3. 复制所有的边

### 代码

```python3
"""
# Definition for a Node.
class Node:
    def __init__(self, val, neighbors):
        self.val = val
        self.neighbors = neighbors
"""
class Solution:
    def cloneGraph(self, node: 'Node') -> 'Node':
        if not node:
            return node
        root = node
        # 1. get all nodes
        nodes = self.get_all_nodes(node)
        
        # 2. copy all nodes
        mapping = {}
        for node in nodes:
            mapping[node] = Node(node.val, [])
        
        # 3. copy all edges
        for node in nodes:
            new_node = mapping[node]
            for neighbor in node.neighbors:
                new_neighbor = mapping[neighbor]
                new_node.neighbors.append(new_neighbor)
        
        return mapping[root]
    
    def get_all_nodes(self, node):
        queue = collections.deque([node])
        result = set([node])
        while queue:
            cur_node = queue.popleft()
            for neighbor in cur_node.neighbors:
                if neighbor not in result:
                    result.add(neighbor)
                    queue.append(neighbor)
        return result
```
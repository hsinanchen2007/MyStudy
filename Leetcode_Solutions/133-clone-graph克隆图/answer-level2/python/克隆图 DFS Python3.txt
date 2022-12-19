### 解题思路
有个地方不明白：
现在的seen每一对是{node: new_node},
而换成{node.val: new_node}（如下面注释所示），
测试的时候可以通过，但提交的时候会出错

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
    
    seen = {}
    
    def cloneGraph(self, node: 'Node') -> 'Node':
        if not node:
            return None
        
        if node in self.seen:
            return self.seen[node]
        # if node.val in self.seen:
            # return self.seen[node.val]
        
        new_node = Node(node.val)
        self.seen[node] = new_node
        # self.seen[node.val] = new_node
        
        for neighbor in node.neighbors:
            new_node.neighbors.append(self.cloneGraph(neighbor))
                
        return new_node

                
```
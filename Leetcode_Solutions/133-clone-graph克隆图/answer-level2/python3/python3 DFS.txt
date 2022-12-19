### 解题思路
dfs: 创建节点的复制节点，遍历子节点，递归执行拷贝工作，将拷贝了的子节点加入neighbors。

用dict保存已经复制了的节点，在递归调用时首先判断是否已经在dict中（被复制过了），是，则直接返回节点；否，则递归调用拷贝函数。
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
        def cg(node,md):
            if node.val in md:
                newNode = md[node.val]
            else:
                newNode = Node(node.val,[])
                md[node.val] = newNode                
                for nd in node.neighbors:
                    newNode.neighbors.append(cg(nd,md))
            return newNode
        return cg(node,dict())
```
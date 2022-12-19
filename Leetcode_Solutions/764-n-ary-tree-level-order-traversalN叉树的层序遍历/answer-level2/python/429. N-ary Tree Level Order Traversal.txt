```
"""
# Definition for a Node.
class Node:
    def __init__(self, val, children):
        self.val = val
        self.children = children
"""
"""
广度优先搜索
初始化数据: 
- L: 存放所有层级的数据
- level: 当前层级
- L[level]: 当前层级的数据

步骤:
1. 是否有当前层级的的初始存储, 没有的话, 创建个L[level]
2. L[level] 存放children的数据
"""
class Solution:
    def levelOrder(self, root: 'Node') -> List[List[int]]:
        if root is None:
            return []
        L = []
        def traverse(node, level):
            if node:
                if len(L) == level:
                    L.append([])
                L[level].append(node.val)

                if node.children:
                    for child in node.children:
                        traverse(child, level + 1)
        
        traverse(root, 0)
        return L
```

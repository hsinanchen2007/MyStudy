### 解题思路
解决树的问题，递归好像就是首选。

### 代码

```python3
"""
# Definition for a Node.
class Node:
    def __init__(self, val=None, children=None):
        self.val = val
        self.children = children
"""
class Solution:
    def preorder(self, root: 'Node') -> List[int]:
        res = []

        def helper(root):
            if not root:
                return
            res.append(root.val)
            for child in root.children: # 循环当前节点的所有child
                helper(child)
        
        helper(root)
        return res
```
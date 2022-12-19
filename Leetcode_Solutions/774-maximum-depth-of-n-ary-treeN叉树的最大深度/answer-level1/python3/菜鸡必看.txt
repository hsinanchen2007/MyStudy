### 解题思路
本质还是遍历

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
    def maxDepth(self, root: 'Node') -> int:
        res=[]
        def helper(root,n) :
            nonlocal res
            if not root :
                return 
            if not root.children :
                res.append(n+1)
                return 
            for c in root.children :
                helper(c,n+1)
        if not root :
            return 0
        helper(root,0)
        return max(res)
```
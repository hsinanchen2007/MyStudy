```python
"""
# Definition for a Node.
class Node:
    def __init__(self, val, children):
        self.val = val
        self.children = children
"""
class Solution:
    def preorder(self, root: 'Node') -> List[int]:
        return root and sum([[root.val], *map(self.preorder, root.children)], []) or []
```

```python
"""
# Definition for a Node.
class Node:
    def __init__(self, val=None, children):
        self.val = val
        self.children = children
"""
class Solution:
    def preorder(self, root: 'Node') -> List[int]:
        s = bool(root) * [root]
        r = []
        
        while s:
            root = s.pop()
            r.append(root.val)
            s += root.children[::-1]
        
        return r
```


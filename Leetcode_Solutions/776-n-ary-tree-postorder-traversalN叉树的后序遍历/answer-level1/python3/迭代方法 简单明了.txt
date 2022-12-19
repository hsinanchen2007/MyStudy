```
"""
# Definition for a Node.
class Node:
    def __init__(self, val=None, children=None):
        self.val = val
        self.children = children
"""
class Solution:
    def postorder(self, root: 'Node') -> List[int]:
        if not root:
            return []
        s = [root]
        res = []
        while s:
            cur = s.pop()
            res.append(cur.val)
            for i in cur.children:
                s.append(i)
        return res[::-1]
```

```python
from typing import List

# Definition for a binary tree node.
class TreeNode:
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None

class Solution:
    def preorderTraversal(self, root: TreeNode) -> List[int]:
        if not root: return []
        res = []
        stack = [root]
        while stack :
            cur = stack .pop()
            if cur.right: stack .append(cur.right)
            if cur.left: stack .append(cur.left)
            res.append(cur.val)
        return res
```
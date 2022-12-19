```python
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:

    def is_mirror(self, l: TreeNode, r: TreeNode) -> bool:
        if l is None or r is None:
            return (l is None) and (r is None)
        return l.val == r.val and self.is_mirror(l.left, r.right) and self.is_mirror(l.right, r.left)

    def isSymmetric(self, root: TreeNode) -> bool:
        if root is None:
            return True
        return self.is_mirror(root.left, root.right)
```
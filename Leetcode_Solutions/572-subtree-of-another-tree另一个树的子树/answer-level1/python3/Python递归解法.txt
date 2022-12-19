```
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def isSubtree(self, s: TreeNode, t: TreeNode) -> bool:

        def is_same(p1, p2):
            if not p1 and not p2:
                return True
            if not p1 or not p2:
                return False
            if p1.val == p2.val:
                return is_same(p1.left, p2.left) and is_same(p1.right, p2.right) 
            return False

        if not s:
            return False
        if is_same(s, t):
            return True
        return self.isSubtree(s.left, t) or self.isSubtree(s.right, t)  
```

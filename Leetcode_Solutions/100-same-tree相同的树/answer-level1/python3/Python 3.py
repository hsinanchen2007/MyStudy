
```
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def isSameTree(self, p: TreeNode, q: TreeNode) -> bool:
        if [p,q].count(None) == 2:
            return True
        if [p,q].count(None) == 1:
            return False
        if p.val != q.val:
            return False
        else:
            return(self.isSameTree(p.left,q.left) and self.isSameTree(p.right,q.right))
```

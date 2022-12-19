注意：该题是完整路径，结果一定是没有其他子树的路径
```
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None
#      1
#   -2   -3
#  1. 3. -2
#. -1

class Solution:
    def hasPathSum(self, root: TreeNode, sum: int) -> bool:
        if not root:
            return False
        if root.val == sum:
            if not root.left and not root.right:
                return True
        if not root.left and not root.right:
            return False
        osum = sum - root.val
        return self.hasPathSum(root.left, osum) or self.hasPathSum(root.right, osum)
```

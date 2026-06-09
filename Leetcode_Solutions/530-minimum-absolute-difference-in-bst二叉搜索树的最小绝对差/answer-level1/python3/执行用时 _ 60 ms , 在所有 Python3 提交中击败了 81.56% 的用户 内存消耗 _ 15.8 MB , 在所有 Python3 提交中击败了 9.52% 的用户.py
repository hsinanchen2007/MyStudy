# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

```
class Solution:
    def getMinimumDifference(self, root: TreeNode) -> int:
        stack = []
        min_val = float('inf')
        pre = -float('inf')
        while stack or root:
            while root:
                stack.append(root)
                root = root.left
            root = stack.pop()
            if abs(root.val-pre) < min_val:
                min_val = abs(root.val-pre)
            pre = root.val
            root = root.right
        return min_val
```

DFS
```
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def hasPathSum(self, root: TreeNode, sum: int) -> bool:
        if not root:
            return False
        stack = [(root.val,root)]
        while stack:
            s,node = stack.pop()
            if (not node.right) and (not node.left):
                if s == sum:
                    return True
            if node.right:
                stack.append((s+node.right.val,node.right))
            if node.left:
                stack.append((s+node.left.val,node.left))
        return False
```

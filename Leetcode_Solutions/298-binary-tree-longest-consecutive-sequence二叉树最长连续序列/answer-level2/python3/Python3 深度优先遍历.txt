打败100%....

```python
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def longestConsecutive(self, root: TreeNode) -> int:
        def dfs(node, last, length):
            nonlocal res
            if last + 1 == node.val:
                if not (node.left or node.right):
                    res = max(res, length + 1)
                if node.left:
                    dfs(node.left, node.val, length + 1)
                if node.right:
                    dfs(node.right, node.val, length + 1)
            else:
                res = max(res, length)
                if node.left:
                    dfs(node.left, node.val, 1)
                if node.right:
                    dfs(node.right, node.val, 1)
            
        res = 0
        if root:
            dfs(root, root.val, 1)
        return res
```
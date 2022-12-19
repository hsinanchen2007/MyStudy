```python
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def countUnivalSubtrees(self, root: TreeNode) -> int:
        res = 0
        # dfs
        # if child = True and node.val == child.val: res += 1
        def dfs(node, val):
            nonlocal res
            if not node:  return (True, val)
            left_flag, left_val = dfs(node.left, node.val)
            right_flag, right_val = dfs(node.right, node.val)
            if left_flag and right_flag and left_val == node.val and right_val == node.val:
                res += 1
                return (True, node.val)
            return (False, node.val)
        if root is None: return 0
        dfs(root, root.val)
        return res
```
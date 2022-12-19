```python
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def maxPathSum(self, root: TreeNode) -> int:
        ans = float('-inf')
        def dfs(node):
            nonlocal ans
            if node == None: return 0
            left_val = dfs(node.left)
            right_val = dfs(node.right)
            ans = max(ans, left_val + right_val + node.val)
            if left_val + node.val < 0 and right_val + node.val < 0: return 0 
            return max(left_val + node.val, right_val + node.val)
        dfs(root)
        return ans
```
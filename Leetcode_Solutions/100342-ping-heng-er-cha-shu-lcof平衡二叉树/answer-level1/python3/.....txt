```python
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def isBalanced(self, root: TreeNode) -> bool:

        def recur(root):
            if not root: return 0, True
            left, valid_left = recur(root.left)
            right, valid_right = 0, False
            if valid_left:
                right, valid_right = recur(root.right)
            return max(left, right) + 1, valid_left and valid_right and abs(right - left) <= 1

        _, valid = recur(root)

        return valid 
```
```python
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def convertBST(self, root: TreeNode) -> TreeNode:
        bigger_sum = 0
        def traverse(node):
            nonlocal bigger_sum
            if not node: return 0
            traverse(node.right)
            node.val += bigger_sum
            bigger_sum = node.val
            traverse(node.left)
        traverse(root)
        return root
```
```python
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def lowestCommonAncestor(self, root: 'TreeNode', p: 'TreeNode', q: 'TreeNode') -> 'TreeNode':
        res = None
        def traverse(node):
            nonlocal res
            if not node: return 0
            val = traverse(node.left) + traverse(node.right)
            if node.val == p.val or node.val == q.val: val += 1
            if val == 2:
                res = node
                return 0
            return val 
        traverse(root)
        return res
```
```python
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def longestConsecutive(self, root: TreeNode)-> int:
        res = 0
        def traverse(node):
            nonlocal res
            ld, la, rd, ra = 0, 0, 0, 0
            if node.left:
                ld, la, _, _ = traverse(node.left)
                if node.left.val + 1 != node.val:
                    la = 0
                if node.left.val - 1 != node.val:
                    ld = 0
            if node.right:
                _, _, rd, ra = traverse(node.right)
                if node.right.val + 1 != node.val:
                    ra = 0
                if node.right.val - 1 != node.val:
                    rd = 0
            res = max(ld + ra + 1, la + rd + 1, res)
            la = ra = max(la, ra)
            ld = rd = max(ld, rd)
            return (1 + ld, 1 + la, 1 + rd, 1 + ra)
        if root == None: return 0
        traverse(root)
        return res
```
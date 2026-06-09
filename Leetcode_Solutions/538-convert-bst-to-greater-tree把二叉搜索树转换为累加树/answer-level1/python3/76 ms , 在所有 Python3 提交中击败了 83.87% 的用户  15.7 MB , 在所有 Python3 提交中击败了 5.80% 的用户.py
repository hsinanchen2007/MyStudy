```
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def convertBST(self, root: TreeNode) -> TreeNode:
        if not root:
            return None
        stack = []
        node = root
        tmp = 0
        while stack or node:
            while node:
                stack.append(node)
                node = node.right
            node = stack.pop()
            node.val = node.val + tmp
            tmp = node.val
            node = node.left
        return root
```

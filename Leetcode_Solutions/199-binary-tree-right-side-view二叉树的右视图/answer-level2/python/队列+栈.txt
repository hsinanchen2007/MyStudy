```python3
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def rightSideView(self, root: TreeNode) -> list:
        q_node = []
        stack = []
        if root:
            q_node.append((0, root))
        while q_node:
            deep, node = q_node.pop(0)
            if stack and (deep == stack[-1][0]):
                stack.pop(-1)
            stack.append((deep, node.val))
            if node.left:
                q_node.append((deep+1, node.left))
            if node.right:
                q_node.append((deep+1, node.right))
            
        return [x[1] for x in stack]

```
```
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def invertTree(self, root: TreeNode) -> TreeNode:
        def invert(node):
            if not node:
                return
            temp = node.left
            node.left = node.right
            node.right = temp
            invert(node.left)
            invert(node.right)
        invert(root)
        return root
        
        
```
交换左右子节点，如果节点为空，则返回

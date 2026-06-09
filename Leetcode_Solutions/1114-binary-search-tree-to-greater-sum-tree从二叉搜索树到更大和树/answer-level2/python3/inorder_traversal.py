```
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    
    
    def inorder_traversal(self, n):
        if n:
            self.inorder_traversal(n.right)
            n.val = self.temp = n.val + self.temp
            self.inorder_traversal(n.left)
            
        
        
    def bstToGst(self, root: TreeNode) -> TreeNode:
        self.temp = 0
        self.inorder_traversal(root)
        return root
```

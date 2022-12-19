
root                   L 
                           
  L         R    ------->>  R    Root  


```python3
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def upsideDownBinaryTree(self, root: TreeNode) -> TreeNode:
        if root is None or root.left is None and root.right is None:
            return root
        
        newroot = self.upsideDownBinaryTree(root.left)
        root.left.left = root.right
        root.left.right = root

        root.left = None
        root.right = None

        return newroot
```
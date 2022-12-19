```
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def buildTree(self, preorder: List[int], inorder: List[int]) -> TreeNode:
        if len(preorder) == 0:
            return None
        
        root = TreeNode(preorder[0])
        idx = inorder.index(root.val)
        
        root.left = self.buildTree(preorder[1:1+idx],inorder[:idx])
        root.right = self.buildTree(preorder[1+idx:],inorder[1+idx:])
        return root

```

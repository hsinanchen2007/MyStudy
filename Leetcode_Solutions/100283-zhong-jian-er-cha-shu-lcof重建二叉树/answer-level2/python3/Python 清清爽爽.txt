```
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def buildTree(self, preorder: List[int], inorder: List[int]) -> TreeNode:
        
        if preorder==inorder==[]:
            return None
        if len(preorder)==len(inorder)==1:
            return TreeNode(preorder[0])
        
        rootval=preorder[0]
        inorderrootindex=inorder.index(rootval)

        root=TreeNode(rootval)
        root.left=self.buildTree(preorder[1:inorderrootindex+1],inorder[0:inorderrootindex])
        root.right=self.buildTree(preorder[inorderrootindex+1:],inorder[inorderrootindex+1:])
        return root        
```

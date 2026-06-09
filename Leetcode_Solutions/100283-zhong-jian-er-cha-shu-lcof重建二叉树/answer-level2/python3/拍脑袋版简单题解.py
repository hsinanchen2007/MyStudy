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
        res = TreeNode(preorder[0])
        inorder_idx = inorder.index(preorder[0])
        res.left = self.buildTree(preorder[1:inorder_idx+1], inorder[0:inorder_idx])
        res.right = self.buildTree(preorder[inorder_idx+1:], inorder[inorder_idx+1:])
        return res

```

``` python []
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def invertTree(self, root: TreeNode) -> TreeNode:
        if not root: #如果不满足树的条件就返回
            return
        root.left,root.right=root.right,root.left #交换左右子树
        root.left = self.invertTree(root.left) #回溯求解左子树下面的子树
        root.right = self.invertTree(root.right)#回溯求解右子树下面的子树
        return root 
```
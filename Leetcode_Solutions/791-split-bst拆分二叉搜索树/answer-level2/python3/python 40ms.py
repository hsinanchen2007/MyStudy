> 简单递归
```python
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def splitBST(self, root: TreeNode, V: int) -> List[TreeNode]:
        
        if not root:
            return None,None
        if not root.left and not root.right:
            if root.val > V:
                return None,root
            else:
                return root,None
        if root.val > V:
            small,large = self.splitBST(root.left,V)
            root.left = large
            return small,root
        else:
            small,large = self.splitBST(root.right,V)
            root.right = small
            return root,large
```
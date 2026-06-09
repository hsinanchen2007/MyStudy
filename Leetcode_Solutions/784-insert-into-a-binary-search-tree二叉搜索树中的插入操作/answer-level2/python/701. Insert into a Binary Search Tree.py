100 ms, 在所有 Python 提交中击败了96.12%的用户

```
# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution(object):
    def insertIntoBST(self, root, val):
        """
        :type root: TreeNode
        :type val: int
        :rtype: TreeNode
        """
        if root is not None:
            if val < root.val:
                # left tree
                if root.left is not None:
                    self.insertIntoBST(root.left, val)
                else:
                    root.left = TreeNode(val)
            else:
                # right tree
                if root.right is not None:
                    self.insertIntoBST(root.right, val)
                else:
                    root.right = TreeNode(val)
        return root
```
代码块
```
```

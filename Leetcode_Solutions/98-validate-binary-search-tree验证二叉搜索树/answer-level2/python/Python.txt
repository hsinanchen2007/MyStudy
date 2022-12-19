### 解题思路
此处撰写解题思路

### 代码

```python
# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution(object):
    def isValidBST(self, root):
        """
        :type root: TreeNode
        :rtype: bool
        """
        if root==None:
            return True
        def help(root,low,high):
            if root==None:
                return True
            if root.val>low and root.val<high:
                return help(root.left,low,root.val) and help(root.right,root.val,high)

            else:
                return False

        return help(root,float('-inf'),float('inf'))

```
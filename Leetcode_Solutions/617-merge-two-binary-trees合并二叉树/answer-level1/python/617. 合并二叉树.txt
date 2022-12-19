```
# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution(object):
    def mergeTrees(self, t1, t2):
        """
        :type t1: TreeNode
        :type t2: TreeNode
        :rtype: TreeNode
        """
        if t1 and t2:
            t1.val = t1.val + t2.val
            # left 繁衍
            t1.left = self.mergeTrees(t1.left, t2.left)
            # right 繁衍
            t1.right = self.mergeTrees(t1.right, t2.right)
        elif not t1 and t2:
            return t2
        else:
            return t1
        
        return t1
```

迭代条件:
1. root.left.val == root.right.val
2. (root.left.left.val == root.right.right.val) and (root.left.right.val == root.right.left.val)
3. ...
4. 还有个考虑条件是: 为空情况


```
# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution(object):
    def isSymmetric(self, root):
        if not root:
            return True
        """
        :type root: TreeNode
        :rtype: bool
        """
        def compare(left, right):
            if not left and not right:
                return True
            if not left or not right:
                return False
            if left.val != right.val:
                return False
            return compare(left.left, right.right) and compare(left.right, right.left)
            
        return compare(root.left, root.right)

"""
条件为:
- left.val == right.val
- left.left.val == right.right.val
  left.right.val == right.left.val
- if left and right 为空 pass
- if left or right 为空 则返回False

"""
```

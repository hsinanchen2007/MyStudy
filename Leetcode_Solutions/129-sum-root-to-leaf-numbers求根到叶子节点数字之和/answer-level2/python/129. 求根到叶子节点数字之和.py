```
# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution(object):
    def sumNumbers(self, root):
        """
        :type root: TreeNode
        :rtype: int
        """
        self.sum = 0
        self.pathLeaf(root, '')
        return self.sum

    def pathLeaf(self, root, path = ''):
        if root is None:
            return
        # leaf
        if root.left is None and root.right is None:
            path += str(root.val)
            self.sum += int(path)
            return 

        self.pathLeaf(root.left, path + str(root.val))
        self.pathLeaf(root.right, path + str(root.val))
```

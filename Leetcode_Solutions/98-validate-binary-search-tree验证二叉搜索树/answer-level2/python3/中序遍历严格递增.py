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

        self.last = float('-inf')
        # 中序遍历是严格递增的，每次跟前一个元素比较，小于等于就记录为False
        def inoder(root):
            if not root:
                return True
            resleft = inoder(root.left)
            if root.val <= self.last:
                return False
            self.last = root.val
            resright = inoder(root.right)
            return resleft & resright

        return inoder(root)

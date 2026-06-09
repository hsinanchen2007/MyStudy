解题思路：
    对于每个树的根节点，使其左子树变为右子树，右子树变为左子树
class Solution(object):
    def mirrorTree(self, root):
        """
        :type root: TreeNode
        :rtype: TreeNode
        """
        if root is None:
            return
        root.left,root.right = self.mirrorTree(root.right), self.mirrorTree(root.left)
        return root
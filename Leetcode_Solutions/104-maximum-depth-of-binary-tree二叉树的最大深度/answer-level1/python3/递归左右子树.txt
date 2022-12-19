
最长路径的深度＝最长路径的叶结点数目，如果树只有一个结点，深度为１。如果有左右子树，则为左右的深度较大值加１。
```
class Solution(object):
    def maxDepth(self, root):
        """
        :type root: TreeNode
        :rtype: int
        """
        if not root:
            return 0
        l = self.maxDepth(root.left)
        r = self.maxDepth(root.right)
        return l+1 if l > r else r+1
```

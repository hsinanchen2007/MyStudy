递归
```
class Solution(object):
    def invertTree(self, root):
        """
        :type root: TreeNode
        :rtype: TreeNode
        """
        if root == None :
            return None
        root.right,root.left=self.invertTree(root.left),self.invertTree(root.right)
        return root
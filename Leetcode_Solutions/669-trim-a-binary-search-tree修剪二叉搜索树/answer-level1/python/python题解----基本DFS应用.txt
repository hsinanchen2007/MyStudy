```
class Solution(object):
    def trimBST(self, root, L, R):
        """
        :type root: TreeNode
        :type L: int
        :type R: int
        :rtype: TreeNode
        """
        if root is None:
            return None
        if root.val > R:
            return self.trimBST(root.left,L,R)
        if root.val < L:
            return self.trimBST(root.right,L,R)
        if root.val >= L and root.val <=R:
            root.left = self.trimBST(root.left,L,R)
            root.right = self.trimBST(root.right,L,R)
        return root
```

```
class Solution(object):

    def _isSymmetric(self, p, q):
        if not (p and q): return True if p == q else False
        return p.val == q.val and self._isSymmetric(p.left, q.right) and self._isSymmetric(p.right, q.left)

    def isSymmetric(self, root):
        """
        :type root: TreeNode
        :rtype: bool
        """
        if not root or not(root.left or root.right): return True
        return self._isSymmetric(root.left, root.right)
```

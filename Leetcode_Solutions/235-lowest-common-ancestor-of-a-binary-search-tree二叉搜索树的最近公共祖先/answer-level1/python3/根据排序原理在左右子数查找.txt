```
class Solution(object):
    def lowestCommonAncestor(self, root, p, q):
        """
        :type root: TreeNode
        :type p: TreeNode
        :type q: TreeNode
        :rtype: TreeNode
        """
        if not root:
            return None
        n = root
        if p.val > q.val:
            p, q = q, p
        while n:
            if q.val < n.val:
                n = n.left
            elif p.val > n.val:
                n = n.right
            else:
                break
        return n
```

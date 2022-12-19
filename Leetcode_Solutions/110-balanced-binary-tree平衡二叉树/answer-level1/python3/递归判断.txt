```
class Solution(object):
    def isBalanced(self, root):
        """
        :type root: TreeNode
        :rtype: bool
        """
        def check(n):
            if not n:
                return True,0
            l = check(n.left)
            if l[0] == False:
                return l
            r = check(n.right)
            if r[0] == False:
                return r
            if abs(l[1]-r[1]) > 1:
                return False,0
            return True, max(l[1], r[1])+1
        return check(root)[0]

```

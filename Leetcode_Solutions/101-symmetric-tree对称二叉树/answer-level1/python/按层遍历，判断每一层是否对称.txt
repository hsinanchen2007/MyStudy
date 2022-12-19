```
class Solution(object):
    def isSymmetric(self, root):
        """
        按层判断是否左右对称
        :type root: TreeNode
        :rtype: bool
        """
        return self.scanByLayer([root])

    def scanByLayer(self, lst):
        if len(lst) < 1:
            return True
        if self.check(lst) == False:
            return False
        next = []
        for x in lst:
            if x is None:
                continue
            next.append(x.left)
            next.append(x.right)
        return self.scanByLayer(next)

    def check(self, tmp):
        for i in range(len(tmp) / 2):
            l = tmp[i]
            r = tmp[len(tmp) - 1 - i]
            if l is None and r is None:
                continue
            elif l is None or r is None:
                return False
            elif l.val != r.val:
                return False
        return True
```

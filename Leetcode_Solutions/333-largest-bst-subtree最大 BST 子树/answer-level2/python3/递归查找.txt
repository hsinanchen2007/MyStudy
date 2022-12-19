```
class Solution:
    def largestBSTSubtree(self, root: TreeNode) -> int:
        maxtree = 0
        def checkTree(n):
            nonlocal maxtree
            if not n:
                return [False]
            num = 1
            lv = rv = n.val
            l = v = []
            status = True
            if n.left:
                l = checkTree(n.left)
                if l[0] == False or l[2]>=n.val:
                    status = False
                else:
                    num += l[3]
                    lv = l[1]
            if n.right:
                r = checkTree(n.right)
                if r[0] == False or r[1]<=n.val:
                    status = False
                else:
                    num += r[3]
                    rv = r[2]
            if status and num>maxtree:
                maxtree = num
            return [status, lv, rv, num]
        checkTree(root)
        return maxtree
```

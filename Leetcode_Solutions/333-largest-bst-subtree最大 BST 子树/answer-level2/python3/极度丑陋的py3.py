```
class Solution:
    def largestBSTSubtree(self, root: TreeNode) -> int:
        ans = 1
        if not root:
            return 0
        def check(r = root):
            nonlocal ans
            cl, cr = 0, 0
            if not r.left and not r.right:
                return 1, r.val, r.val
            if r.left:
                cl, lm, ls = check(r.left)
            if r.right:
                cr, rm, rs = check(r.right)
            if r.left and not r.right :
                if r.val > lm and cl != 0 :
                    ans = max(ans, cl+1)
                    return cl+1, max(lm, r.val), min(r.val, ls)
                else:
                    return 0, 0, 0
            elif not r.left and r.right:
                if r.val < rs and cr != 0 :
                    ans = max(ans, cr+1)
                    return cr+1, max(rm, r.val), min(rs, r.val)
                else:
                    return 0, 0, 0
            elif cl != 0 and cr != 0 and r.val > lm and  r.val < rs:
                
                ans = max(cl+cr+1, ans)
                return cl+cr+1, max(lm, rm, r.val), min(ls, rs, r.val)
            return 0, 0, 0
        check()
        return ans
```

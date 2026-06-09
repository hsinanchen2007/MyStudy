```
class Solution(object):
    def rob(self, root):
        def work(roo):
            if roo == None:
                return 0,0
            l1, l2 = work(roo.left)
            r1, r2 = work(roo.right)
            return max(roo.val + r2 +l2,l1+r1), l1+r1
        ans, ans_next =  work(root)
        return ans
```

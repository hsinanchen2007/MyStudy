```
ans = 0
class Solution:
    def bstToGst(self, root: TreeNode) -> TreeNode:
        global ans 
        ans = 0
        def check(t):
            global ans
            if t:
                check(t.right)
                t1 = t.val
                t.val += ans
                ans += t1
                check(t.left)
        check(root)
        return root
```

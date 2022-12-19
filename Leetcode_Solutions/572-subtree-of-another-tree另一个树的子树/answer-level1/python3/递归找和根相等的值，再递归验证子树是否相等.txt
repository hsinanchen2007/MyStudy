![image.png](https://pic.leetcode-cn.com/d027bafce0fce44f5e1b78c17d90279ad77f53b0b3a655645546a1eef09ed9c3-image.png)

递归找和根相等的值，这里取或，再递归验证子树是否相等，这里取且，比较简单的思路，但不是很快
```
class Solution:
    def isSubtree(self, s: TreeNode, t: TreeNode) -> bool:
        def g(a,b):
            if not a and not b:
                return True
            if a and b:
                return a.val==b.val and g(a.left,b.left) and g(a.right,b.right)
            return False
        
        def f(r):
            if not r:
                return False
            return  f(r.left) or f(r.right) or (g(r,t) if r.val==t.val else False)
        
        return f(s)
```

![image.png](https://pic.leetcode-cn.com/dc21694efaafceb3af09d8029c82fe15ce9815b9f80c5793dd4bf95e72f5542f-image.png)


比较快捷简单，不用费脑调BUG。
```
class Solution:
    def largestValues(self, root: TreeNode) -> List[int]:
        d={}
        def f(r,i):
            if r:
                if i in d:
                    d[i]=max(d[i],r.val)
                else:
                    d[i]=r.val
                f(r.left,i+1)
                f(r.right,i+1)
        f(root,0)
        return list(d.values())
```

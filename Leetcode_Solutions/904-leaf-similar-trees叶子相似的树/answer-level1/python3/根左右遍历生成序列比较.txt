![image.png](https://pic.leetcode-cn.com/4d3306db778041b874e0d033bc07adf65a24d2093edd80f72c38fc8cba768011-image.png)


可能是函数传值只传序号不传数组，所以快了一点点
```
class Solution:
    def leafSimilar(self, root1: TreeNode, root2: TreeNode) -> bool:
        a=[[],[]]
        def f(r,i):
            if not r:
                return
            if not r.left and not r.right:
                a[i].append(r.val)
            f(r.left,i)
            f(r.right,i)
        f(root1,0)
        f(root2,1)
        return a[0]==a[1]
```

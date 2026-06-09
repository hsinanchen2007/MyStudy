![image.png](https://pic.leetcode-cn.com/226750b7db97c64afc8453ede02128b2239f217223f2ffe62aeac3ca36219d6a-image.png)

简单易理解，除了O(N)也没啥额外空间，递归也不用传值

```python []
class Solution:
    def increasingBST(self, root: TreeNode) -> TreeNode:
        d = []
        def f(r):
            if r:
                f(r.left)
                d.append(r)
                f(r.right)
        f(root)
        ans = t = TreeNode(0)
        for r in d:
            t.left = None
            t.right = r
            t = r
        t.left = None
        return ans.right
```

更短更优的递归
![image.png](https://pic.leetcode-cn.com/8259532c078e268d9350ac25036bc85a233e572478a57ac46e2a029ecb93d9e3-image.png)


```python []
class Solution:
    def increasingBST(self, root: TreeNode) -> TreeNode:
        def f(r, t):
            if r:
                ans = f(r.left, r)
                r.left = None
                r.right = f(r.right, t)
                return ans
            return t
        return f(root, None)
```

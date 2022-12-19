似乎没有用到排序树的性质，纯当两数之和来做了，时间复杂度$O(M+N)$，空间复杂度$O(M)$。

```python
class Solution:
    def twoSumBSTs(self, root1: TreeNode, root2: TreeNode, target: int) -> bool:
        d = set()
        def f(r):
            if r:
                d.add(target - r.val)
                f(r.left)
                f(r.right)
        f(root1)
        ans = False
        def g(r):
            nonlocal ans
            if r and not ans:
                if r.val in d:
                    ans = True
                g(r.left)
                g(r.right)
        g(root2)
        return ans
```

![image.png](https://pic.leetcode-cn.com/790007b7edd7098d27f16723e568960e0d2db7fe175f5c567ac9dc6b1252868d-image.png)

80ms仅供参考。
![image.png](https://pic.leetcode-cn.com/60be02d7cf957357b864f0757dcfd0fa2d05f1d76602927aa2c5aef9964445e1-image.png)

左右根遍历树，得到每个子树下的最大值和最小值，并全局比较记录答案。

```python []
class Solution:
    def maxAncestorDiff(self, root: TreeNode) -> int:
        ans = 0
        def f(root):
            if not root:
                return float('inf'), -float('inf')
            lmin, lmax = f(root.left)
            rmin, rmax = f(root.right)
            rootmin = min(root.val, lmin, rmin)
            rootmax = max(root.val, lmax, rmax)
            nonlocal ans
            ans = max(ans, abs(root.val - rootmin), abs(root.val - rootmax))
            return rootmin, rootmax
        f(root)
        return ans
```

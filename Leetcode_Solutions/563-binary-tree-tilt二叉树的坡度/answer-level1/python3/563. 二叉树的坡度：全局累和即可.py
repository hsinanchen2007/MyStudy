![image.png](https://pic.leetcode-cn.com/7267c1bc0f18cecf8c938afc41d527359d3344a2cb8797ef1bbcff7273abdc92-image.png)

用nonlocal记录全局信息

```python []
class Solution:
    def findTilt(self, root: TreeNode) -> int:
        ans = 0
        def f(r):
            if not r:
                return 0
            sumleft, sumright = f(r.left), f(r.right)
            nonlocal ans
            ans += abs(sumleft - sumright)
            return sumleft + sumright + r.val
        f(root)
        return ans
```

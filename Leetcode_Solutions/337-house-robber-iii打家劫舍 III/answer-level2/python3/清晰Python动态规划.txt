### 代码

```python3
class Solution:
    import functools
    @functools.lru_cache(None)
    def rob(self, root: TreeNode) -> int:
        # base case
        if not root:
            return 0
        # 抢然后去下下家
        left = 0 if not root.left else self.rob(root.left.left) + self.rob(root.left.right)
        right = 0 if not root.right else self.rob(root.right.left) + self.rob(root.right.right)
        do = root.val + left + right
        # 不抢然后去下家
        not_do = self.rob(root.left) + self.rob(root.right)
        res = max(do, not_do)
        return res
```
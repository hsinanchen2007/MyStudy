
```python []
class Solution:
    def pathSum(self, root: TreeNode, sum: int) -> List[List[int]]:
        ans = []
        def f(r, s, p):
            if r:
                s += r.val
                if not r.left and not r.right and s == sum:
                    ans.append(p + [r.val])
                f(r.left, s, p + [r.val])
                f(r.right, s, p + [r.val])
        f(root, 0, [])
        return ans
```
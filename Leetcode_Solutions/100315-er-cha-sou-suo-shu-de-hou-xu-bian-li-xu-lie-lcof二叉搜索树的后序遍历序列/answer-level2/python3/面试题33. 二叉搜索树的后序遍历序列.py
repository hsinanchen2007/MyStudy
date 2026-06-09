
```python []
class Solution:
    def verifyPostorder(self, postorder: List[int]) -> bool:
        d = {j: i for i, j in enumerate(sorted(postorder))}
        k = len(postorder) - 1
        def f(i, j):
            nonlocal k
            if i < j and k >= -2:
                t = TreeNode(postorder[k])
                k -= 1
                t.right = f(d[t.val] + 1, j)
                t.left = f(i, d[t.val])
                return t
        f(0, len(postorder))
        return k >= -1
```
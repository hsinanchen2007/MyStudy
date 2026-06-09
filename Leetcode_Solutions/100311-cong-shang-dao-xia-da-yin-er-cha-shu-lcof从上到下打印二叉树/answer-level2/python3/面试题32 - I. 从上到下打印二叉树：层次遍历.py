
```python []
class Solution:
    def levelOrder(self, root: TreeNode) -> List[int]:
        if root:
            d = [root]
            for r in d:
                yield r.val
                r.left and d.append(r.left)
                r.right and d.append(r.right)
```

```python []
class Solution:
    def levelOrder(self, root: TreeNode) -> List[int]:
        ans = []
        if root:
            d = [root]
            for r in d:
                ans.append(r.val)
                r.left and d.append(r.left)
                r.right and d.append(r.right)
        return ans
```

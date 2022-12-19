```python
def middle_order(root):
    if root is None: return
    yield from middle_order(root.left)
    yield root.val
    yield from middle_order(root.right)

class Solution:
    def isValidBST(self, root: TreeNode) -> bool:
        if root is None: return True
        gen = middle_order(root)
        prev = next(gen)
        for x in gen:
            if prev >= x:
                return False
            prev = x
        return True
```

- 时间复杂度 O(n)，n 为树节点个数。
- 空间复杂度 O(1)
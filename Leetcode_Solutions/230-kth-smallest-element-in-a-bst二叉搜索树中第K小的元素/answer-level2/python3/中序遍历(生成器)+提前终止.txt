
- 时间复杂度：依次遍历前 k 个节点，因此时间复杂度为 O(k)
- 空间复杂度：生成器只需要 O(1) 的空间，如果不考虑递归栈所占用的空间，那么复杂度为 O(1)

```python
class Solution:
    def mid_order(self, root):
        if not root: return
        yield from self.mid_order(root.left)
        yield root.val
        yield from self.mid_order(root.right)
        
    def kthSmallest(self, root: TreeNode, k: int) -> int:
        gen = self.mid_order(root)
        for _ in range(k - 1):
            next(gen)
        return next(gen)
```

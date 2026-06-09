使用 Python3 的 `yield` 语法优化内存占用：

```python
class Solution:
    def inorderTraversal(self, root: TreeNode) -> List[int]:
        return list(self.helper(root))
        
    def helper(self, node):
        if node is None: return
        yield from self.helper(node.left)
        yield node.val
        yield from self.helper(node.right)
```

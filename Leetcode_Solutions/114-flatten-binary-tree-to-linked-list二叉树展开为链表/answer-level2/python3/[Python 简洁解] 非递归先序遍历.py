非递归先序遍历，遍历过程中维护一个父节点，边遍历边原地修改

```python
class Solution:
    def flatten(self, root: TreeNode) -> None:
        """
        Do not return anything, modify root in-place instead.
        """
        stack = [root]
        prev = None
        while stack:
            node = stack.pop()
            if prev is not None:
                prev.right = node
                prev.left = None
            if node is not None:
                stack.append(node.right)
                stack.append(node.left)
                prev = node
```

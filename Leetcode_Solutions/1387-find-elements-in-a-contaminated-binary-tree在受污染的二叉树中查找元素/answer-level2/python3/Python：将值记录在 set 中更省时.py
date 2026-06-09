使用 list 保存值，执行用时 972 ms
使用 set  保存值，执行用时 124 ms

```python
class FindElements:

    def __init__(self, root: TreeNode):
        self.values = set()
        def recursion(root, value):
            if root is not None:
                self.values.add(value)
                root.left = recursion(root.left, 2 * value + 1)
                root.right = recursion(root.right, 2 * value + 2)
        recursion(root, 0)        

    def find(self, target: int) -> bool:
        return target in self.values
```

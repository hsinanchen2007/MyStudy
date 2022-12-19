知识点：
二进制转十进制：
int('100', 2)    -> 4
八进制转十进制:
int('17', 8)     -> 15
十六进制转十进制：
int('0xf', 16)   -> 15

十进制转二进制：
bin(4)   -> '0b100'

十进制转八进制：
oct(15)  -> '017'

十进制转十六进制：
hex(15)  -> '0xf'

```python []
class Solution:
    def _dfs(self, root, path):
        path.append(str(root.val))

        if root.left is None and root.right is None:
            tmp = int(''.join(path), 2)
            return tmp

        result = 0
        if root.left:
            result += self._dfs(root.left, path)
            path.pop()

        if root.right:
            result += self._dfs(root.right, path)
            path.pop()
        return result

    def sumRootToLeaf(self, root: TreeNode) -> int:
        if root is None:
            return 0

        path = []
        result = self._dfs(root, path)
        return result
```


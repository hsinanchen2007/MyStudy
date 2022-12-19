### 解题思路
使用递归将左子树和右子树交换。

### 代码

```python
class Solution:
    def mirrorTree(self, root: TreeNode) -> TreeNode:
        if root:
            root.left,root.right = self.mirrorTree(root.right), self.mirrorTree(root.left)
        return root
```
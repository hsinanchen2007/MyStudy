**解题思路：**
    对于一个非空的节点，将他镜像翻转只需要交换左右子节点即可
```python []
class Solution:
    def invertTree(self, root: TreeNode) -> TreeNode:
        if not root:
            return root
        root.right,root.left=root.left,root.right
        self.invertTree(root.right)
        self.invertTree(root.left)
        return root
```

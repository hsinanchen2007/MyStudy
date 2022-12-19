### 代码

```python3
class Solution:
    def insertIntoBST(self, root: TreeNode, val: int) -> TreeNode:
        # 将插入的节点作为叶子节点的子节点插入
        if root == None:
            return TreeNode(val)
        if root.val > val:
            root.left = self.insertIntoBST(root.left, val)
        if root.val < val:
            root.right = self.insertIntoBST(root.right, val)
        return root
```
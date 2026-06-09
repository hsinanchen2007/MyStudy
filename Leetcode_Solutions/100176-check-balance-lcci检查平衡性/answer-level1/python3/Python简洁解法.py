### 解题思路
注释如下

### 代码

```python3
class Solution:
    # 计算以当前节点为根的树深度
    def Depth(self, root: TreeNode) -> int:
        if root:
            return 1 + max(self.Depth(root.left), self.Depth(root.right))
        return 0


    def isBalanced(self, root: TreeNode) -> bool:
        # 空树是AVL
        if not root:
            return True
        # 若左右子树深度超过1，非AVL
        if abs(self.Depth(root.left) - self.Depth(root.right)) > 1:
            return False
        # 递归执行，当出现不满足AVL性质的子树时，执行短路运算立即返回结果
        return self.isBalanced(root.left) and self.isBalanced(root.right)
```
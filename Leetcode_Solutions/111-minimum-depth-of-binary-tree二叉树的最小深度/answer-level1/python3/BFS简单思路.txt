树节点分四种情况：
1、节点为None，返回0（这只是为了通过空列表[]的样例）
2、节点左右子树都不为空，返回左右子树深度的最小值
3、左子树为空或右子树为空，返回该子树深度
4、左右子树都为空，返回1

```
class Solution:
    def minDepth(self, root: TreeNode) -> int:
        if not root:
            return 0
        if root.left and root.right:
            return min(self.minDepth(root.left)+1, self.minDepth(root.right)+1)
        elif root.left:
            return self.minDepth(root.left) + 1
        elif root.right:
            return self.minDepth(root.right) + 1
        else:
            return 1
```

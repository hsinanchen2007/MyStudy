### 解题思路
dps遍历，计算每一个节点到根节点的路径和，当到达叶子节点的时候，判断是否等于目标和

### 代码

```python3
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def hasPathSum(self, root: TreeNode, sum: int) -> bool:
        def dps(tree:TreeNode, val_sum:int) -> int:
            if tree.left and dps(tree.left, val_sum+tree.val):
                return True
            if tree.right and dps(tree.right, val_sum+tree.val):
                return True
            if not tree.left and not tree.right and val_sum + tree.val == sum:
                return True
            return False

        if not root: return False
        return bool(dps(root, 0))
```
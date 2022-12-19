### 解题思路
需要考虑的特殊情况是：左右两个子树中有一个为空，即单边树的情况

### 代码

```python3
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def minDepth(self, root: TreeNode) -> int:
        if root is None:  # 空树
            return 0
        elif root.left is None:  # 如果左子树为空，则当前根节点的右子树的最小深度是该根节点的最小深度
            return self.minDepth(root.right) + 1
        elif root.right is None: # 如果右子树为空，则当前根节点的左子树的最小深度是该根节点的最小深度
            return self.minDepth(root.left) + 1
        else:   # 如果两个子树都不为空，则比较左右两棵子树
            return min(self.minDepth(root.left), self.minDepth(root.right)) + 1



     

```
### 解题思路
1、左子树所有节点的val均需要小于root.val，右子树的所有节点的val均需要大于root.val；
2、不能只判断root.left.val < root.val和root.right.val > root.val，这样会有一些情况覆盖不到，不能达到1描述的效果，因此需要使用上下界；
3、每次递归，更新最小值、最大值，遍历左子树，最大值更新为root.val，遍历右子树，最小值更新为root.val（因为左子树最大不能超过root.val，右子树最小不能小于root.val）。

### 代码

```python3
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def isValidBST(self, root: TreeNode) -> bool:
        if root is None:
            return True
        def tree(root, low, up):
            if root is None:
                return True
            if root.left is not None:
                if root.left.val >= root.val or root.left.val <= low:
                    return False
            if root.right is not None:
                if root.right.val <= root.val or root.right.val >= up:
                    return False
            return tree(root.left, low, root.val) and tree(root.right, root.val, up)
        return tree(root, float("-inf"), float("inf"))
```
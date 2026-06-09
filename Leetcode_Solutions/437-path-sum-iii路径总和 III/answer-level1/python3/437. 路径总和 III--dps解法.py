### 解题思路
dps解法，保存当前节点到根节点的路径和。

### 代码

```python3
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def pathSum(self, root: TreeNode, sum: int) -> int:
        def dps(tree:TreeNode, sum_from_root:list) -> int:
            if not tree: return 0
            sum_from_root = [tree.val + i for i in sum_from_root] + [tree.val]
            return sum_from_root.count(sum)+dps(tree.left, sum_from_root)+dps(tree.right, sum_from_root)
        return dps(root, [])

```
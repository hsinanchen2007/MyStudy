```
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def minDepth(self, root: TreeNode) -> int:
        # 如果根节点不存在，直接返回树高度为0
        if not root:
            return 0
        # 分别递归获取左右字树木的高度
        left_depth, right_depth = 0, 0
        left_depth = self.minDepth(root.left)
        right_depth = self.minDepth(root.right)
        # 万一其中一侧的树不在，则获取另一侧树的高度
        if (root.left == None) or (root.right == None):
            return left_depth + right_depth + 1;
        # 正常的树就获取最小高度 + 根节点记录为1
        return 1 + min(left_depth, right_depth);
```

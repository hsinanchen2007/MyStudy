# 说明
本解法翻译自: https://leetcode-cn.com/problems/flatten-binary-tree-to-linked-list/solution/xiang-xi-tong-su-de-si-lu-fen-xi-duo-jie-fa-by--26 java 版代码。

# 代码
```
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

import typing

class Solution:
    def right_most_node(self, root: TreeNode) -> typing.Union[TreeNode, None]:
        """
        @function: 寻找当前节点的最右侧节点
        """
        if root == None or root.right == None:
            return root
        
        return self.right_most_node(root.right)

    def flatten(self, root: TreeNode) -> None:
        """
        Do not return anything, modify root in-place instead.
        """
        # 当前节点为空，则遍历结束，直接返回
        if root == None:
            return

        # 如果左子树为空，那么就对右子树展开
        if root.left == None:
            return self.flatten(root.right)

        # left 和 right 分别指向左子树和右子树
        right = root.right
        # 将当前节点的左子树转换为右子树
        root.right = root.left
        right_most_node = self.right_most_node(root.left)
        if right_most_node != None:
            # 将右子树作为当前节点左子树最右侧节点的右子树
            right_most_node.right = right
        # 将当前节点的左子树设置为空
        # 这一步很重要!!!
        root.left = None

        # 继续下一轮右子树的展开
        return self.flatten(root.right)
```

# 题解思路
自顶向下的递归会有重复部分；
此题采用自底向上的递归，自底向上判断当前节点的左右子树的高度差是否大于1，若大于1，上面的都不用遍历了直接-1回溯回去返回False即可；若小于1，则可利用当前的高度去判断它的父节点是否平衡。

# 代码
```
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def isBalanced(self, root: TreeNode) -> bool:
        return self.Depth(root) != -1
        
    def Depth(self, root):
        if not root:
            return 0
        left = self.Depth(root.left)
        if left == -1:
            return -1
        right = self.Depth(root.right)
        if right == -1:
            return -1
        return max(left, right) + 1 if abs(left - right) < 2 else -1
```

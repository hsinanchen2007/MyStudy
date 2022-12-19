深度优先，遍历二叉树，判断当前节点是否可以和父节点连接，从而更新最长序列长度
```
# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution(object):
    def longestConsecutive(self, root):
        """
        :type root: TreeNode
        :rtype: int
        """
        self.len = 0
        def helper(root):
            if not root:
                return 0
            left = helper(root.left)
            right = helper(root.right)
            cur_len = 1
            if root.left and root.left.val == root.val + 1:
                cur_len = max(cur_len,left + 1)
            if root.right and root.right.val == root.val + 1:
                cur_len = max(cur_len,right + 1)
            self.len = max(self.len,cur_len,left,right)
            return cur_len
        helper(root)
        return self.len
```

请利用二叉搜索树这个特点

```
# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution(object):
    def rangeSumBST(self, root, L, R):
        """
        :type root: TreeNode
        :type L: int
        :type R: int
        :rtype: int
        """
        self._sum = 0
        if root is not None:
            self.search(root, L, R)
            return self._sum + L + R
        else:
            return 0

    def search(self, root, L, R):
        if root:
            if L < root.val and root.val < R:
                self._sum += root.val
            if root.val < L:
                self.search(root.right, L, R)
            elif root.val > R:
                self.search(root.left, L, R)
            else:
                self.search(root.right, L, R)
                self.search(root.left, L, R)
                

"""
二叉搜索树 BST
- root.val > root.left.val
- root.val < root.right.val

目标是:
sum = L + R + val
条件: L <= val <= R
因为是二叉搜索树, 可以过滤掉不必要的迭代
- 当node.val < L: 结点值都小于最小值的话, 不必继续找左子树下去;
- 当node.val > R: 结点值都小于最大值的话, 不必继续找右子树下去;
"""
```
### 解题思路
此处撰写解题思路

### 代码

```python
# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution(object):
    def upsideDownBinaryTree(self, root):
        """
        :type root: TreeNode
        :rtype: TreeNode
        """
        if not root or (not root.left and not root.right):
            return root
        left_tree = self.upsideDownBinaryTree(root.left)
        right_tree = self.upsideDownBinaryTree(root.right)
        cur = left_tree
        while cur.right:
            cur = cur.right
        cur.left = right_tree
        cur.right = root
        root.left = None
        root.right = None
        return left_tree
        

```
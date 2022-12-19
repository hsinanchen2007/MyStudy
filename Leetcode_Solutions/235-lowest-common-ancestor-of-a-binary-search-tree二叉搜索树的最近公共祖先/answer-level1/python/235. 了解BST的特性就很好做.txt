### 解题思路
1. BST特征，左树比当前节点小，右树比当前节点大，因此先来判断p,q在哪一侧。
2. 如果在同一侧，只顺着这一边向下继续递归。如果在两侧返回节点即可。

### 代码

```python3
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def lowestCommonAncestor(self, root: 'TreeNode', p: 'TreeNode', q: 'TreeNode') -> 'TreeNode':
        # BST 的特点，左面的永远都小于右面的。 
        if p.val < root.val and q.val < root.val:
            return self.lowestCommonAncestor(root.left, p, q)
        elif p.val > root.val and q.val > root.val:
            return self.lowestCommonAncestor(root.right, p, q)
        else:
            return root

```
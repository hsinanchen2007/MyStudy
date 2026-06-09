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
    def lowestCommonAncestor(self, root, p, q):
        """
        :type root: TreeNode
        :type p: TreeNode
        :type q: TreeNode
        :rtype: TreeNode
        """
        if root is None:
            return None
        if p.val >q.val:
            p,q=q,p
        while True:
            if root.val>q.val:
                root=root.left
            elif root.val<p.val:
                root=root.right
            else:
                return root
```
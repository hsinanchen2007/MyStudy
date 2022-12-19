### 解题思路
此处撰写解题思路

代码一看就懂

```python3
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def lowestCommonAncestor(self, root: 'TreeNode', p: 'TreeNode', q: 'TreeNode') -> 'TreeNode':
        if root:
            if root.val<=max(p.val,q.val) and root.val>=min(q.val,p.val):
                return root
            elif root.val<min(q.val,p.val):
                return self.lowestCommonAncestor(root.right,p,q)
            else:
                return self.lowestCommonAncestor(root.left,p,q)
```
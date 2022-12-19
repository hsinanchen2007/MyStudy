### 解题思路 如果要查找的两个节点1.任一个等于根结点值，或者这两个节点指分别位于根节点值的两侧，则返回根节点。2.如果这两个节点只在根节点值的左侧，在左子树查找，3.否则在右子树查找。
**注意返回的是节点而非节点的值**
此处撰写解题思路

### 代码

```python
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def lowestCommonAncestor(self, root: 'TreeNode', p: 'TreeNode', q: 'TreeNode') -> 'TreeNode':
        if p.val>q.val:
            p,q = q,p
        if p==root or q == root:
            return root
        if p.val<root.val and q.val> root.val:
            return root
        if p.val<root.val and q.val<root.val:
            return self.lowestCommonAncestor(root.left,p,q)
        if p.val>root.val and q.val>root.val:
            return self.lowestCommonAncestor(root.right,p,q)


        
```
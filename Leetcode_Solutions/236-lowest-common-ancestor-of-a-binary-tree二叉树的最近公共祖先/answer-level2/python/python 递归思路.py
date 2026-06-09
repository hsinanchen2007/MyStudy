### 解题思路
此处撰写解题思路
递归判断  如果左为空，则右包含p,q,如果右为空则左包含p,q

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

        if ((root==q)|(root==None)|(root==p)):
            return root
        ri = self.lowestCommonAncestor(root.right,p,q)
        le = self.lowestCommonAncestor(root.left,p,q)
        if ri==None:
            return le
        if le==None:
            return ri
        return root    
```
### 解题思路
此处撰写解题思路

### 代码

```python3
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    
    def maxPathSum(self, root: TreeNode) -> int:
        
        nu=-inf
        def dsf(root):
            if root==None:
                return 0
            le = dsf(root.left)
            ri = dsf(root.right)
            nonlocal nu
            nu = max(nu,le+ri+root.val)
            return max(0,root.val+max(le,ri))
        dsf(root)
        return nu
            

```
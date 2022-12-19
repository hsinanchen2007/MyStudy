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
    def isSymmetric(self, root: TreeNode) -> bool:
        if root==None:
            return True
        def ds(l,r):
            if l==None and r==None:
                return True
            if l==None or r==None:
                return False
            if l.val!=r.val:
                return False

            return ds(l.left,r.right)&ds(l.right,r.left)
        return ds(root.left,root.right)
```
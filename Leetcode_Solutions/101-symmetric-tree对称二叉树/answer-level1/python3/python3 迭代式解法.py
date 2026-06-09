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
        le,ri = [],[] 
        l ,r = root.left,root.right        
        while(l or r or (len(le)>0) or (len(ri))>0):
            while(l and r):
                le.append(l)
                l = l.left
                ri.append(r)
                r = r.right
            if l or r:
                return False
            l,r = le[-1],ri[-1]
            le.pop()
            ri.pop()
            if l.val!=r.val:
                return False
      
            l = l.right
            r = r.left
        return True
```
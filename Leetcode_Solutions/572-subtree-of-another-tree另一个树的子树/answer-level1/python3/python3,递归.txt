### 解题思路
递归的思想很重要.

### 代码

```python3
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def isSubtree(self, s: TreeNode, t: TreeNode) -> bool:


        def issame(p, q):
            if not p and not q:
                return True
            if not p or not q:
                return False
            return p.val == q.val and issame(p.left, q.left) and issame(p.right, q.right)


        if not t:
            return True
        if not s:
            return False
        return issame(s, t) or self.isSubtree(s.left, t) or self.isSubtree(s.right, t)
        
```
### 解题思路
判断子树。

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
        def issame(s, t):
            if s==None and t==None:
                return True
            elif s==None or t==None:
                return False
            else:
            # return s.val==t.val and issame(s.left, t.right) and issame(s.right, t.right)  # 敲错了导致 bug
                return s.val==t.val and issame(s.left, t.left) and issame(s.right, t.right)
        if s==None and t==None:
            return True
        elif s==None or t==None:
            return False
        elif s.val == t.val:
            if issame(s.left, t.left) and issame(s.right, t.right):
                return True
            else:
                return self.isSubtree(s.left, t) or self.isSubtree(s.right, t)
        else:
            return self.isSubtree(s.left, t) or self.isSubtree(s.right, t)

```
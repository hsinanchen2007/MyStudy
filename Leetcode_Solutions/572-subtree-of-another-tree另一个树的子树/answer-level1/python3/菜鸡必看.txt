### 解题思路
两个递归 
子方法用到了100题

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
        def sameT(a,b) :
            if not a and not b:
                return True 
            if  a and b :
                return a.val==b.val and sameT(a.left,b.left) and sameT(a.right,b.right)
            return False
        if not t :
            return True
        if not s :
            return False
        return sameT(s,t) or self.isSubtree(s.left,t) or self.isSubtree(s.right,t)
        
```
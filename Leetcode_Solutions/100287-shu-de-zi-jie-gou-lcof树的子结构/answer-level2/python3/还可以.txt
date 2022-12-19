### 解题思路
如果A有左子树，B无左子树，那么左支为True；
如果A有左子树，B有左子树，那么递归比较；
如果A无左子树，B有左子树，那么左支为False。

### 代码

```python3
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def isSubStructure(self, A: TreeNode, B: TreeNode) -> bool:
        if not B: return False
        nodes = self.findSame(A, B.val)
        for i in nodes:
            if self.isMatch(i, B):
                return True
        return False
        
        
    def findSame(self, A, n):
        # 在A里面找到为节点值为n的节点集合
        if not A:   return []
        return [A] if A.val == n else [] + self.findSame(A.left, n) + self.findSame(A.right, n)
    
    def isMatch(self, A, B):
        b1, b2 = False, False
        if A.val == B.val:
            if not B.left:
                b1 = True
            elif A.left and B.left:
                b1 = self.isMatch(A.left, B.left)
            if not B.right:
                b2 = True
            elif A.right and B.right:
                b2 = self.isMatch(A.right, B.right)
        return b1 and b2
            
```
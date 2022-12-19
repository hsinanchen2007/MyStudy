### 解题思路
想来想去还是需要额外写一个函数。

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
        if A == None or B == None:
            return False
        return self.dfs(A,B) or self.isSubStructure(A.left,B) or self.isSubStructure(A.right,B)
    
    def dfs(self, A: TreeNode, B: TreeNode) -> bool:
        if B == None:
            return True
        if A == None:
            return False
        return A.val == B.val and self.dfs(A.left,B.left) and self.dfs(A.right,B.right)
```
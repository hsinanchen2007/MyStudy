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
    def isBalanced(self, root: TreeNode) -> bool:
        def isBalanced(root):
            if root is None: return 0, True    
            dep_left, isbLeft = isBalanced(root.left)
            dep_right, isbRight = isBalanced(root.right)
            if isb := abs(dep_right - dep_left) <= 1 and isbLeft and isbRight:
                return max(dep_left, dep_right)+1, isb
            return 0, False
        return isBalanced(root)[1]
```
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
    def sumEvenGrandparent(self, root: TreeNode) -> int:
        ans = 0
        def solver(pp,p,root):
            if not root: return
            if pp%2==0:
                nonlocal ans
                ans += root.val
            solver(p,root.val,root.left)
            solver(p,root.val,root.right)
        solver(-1,-1,root)
        return ans
```
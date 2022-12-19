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
    def maxAncestorDiff(self, root: TreeNode) -> int:
        self.ans = 0
        def search(root,parentmax,parentmin):
            if root:
                self.ans=max(abs(root.val-parentmax),abs(root.val-parentmin),self.ans)
                parentmax = max(parentmax,root.val)
                parentmin = min(parentmin,root.val)
                search(root.left,parentmax,parentmin )
                search(root.right,parentmax,parentmin )
        
        search(root,root.val,root.val)
        return self.ans
```
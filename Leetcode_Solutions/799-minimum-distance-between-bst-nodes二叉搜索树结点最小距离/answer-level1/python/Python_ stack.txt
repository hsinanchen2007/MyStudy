### 代码

```python
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def minDiffInBST(self, root: TreeNode) -> int:
        min_diff = float('inf')
        s, cur = [root], -float('inf')
        seen = set()
        while s:
            node = s.pop()
            if node not in seen:
                seen.add(node)
                if node.right: s.append(node.right)
                s.append(node)
                if node.left: s.append(node.left)
            else:
                min_diff = min(min_diff, node.val - cur)
                cur = node.val
        return min_diff
```
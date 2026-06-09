### 解题思路

使用 [::(-1) ** idx] 来调整输出顺序

### 代码

```python3
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None
from collections import defaultdict
class Solution:
    def levelOrder(self, root: TreeNode) -> List[List[int]]:
        self.ans = defaultdict(list)
        def recursion(node, depth):
            if node:
                self.ans[depth].append(node.val)
                recursion(node.left, depth+1)
                recursion(node.right, depth+1)
        recursion(root, 0)
        return [a[1][::(-1) ** idx] for idx, a in enumerate(sorted(self.ans.items()))]
```
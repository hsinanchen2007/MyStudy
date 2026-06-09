### 解题思路
-   DFS深度优先搜索

-   每次向下传递当前的值，路径长度，并更新最大路径值




### 代码

```python
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def longestConsecutive(self, root: TreeNode) -> int:
        if not root:
            return 0
        ans = 0

        def dfs(node, parent, parent_path):
            nonlocal ans
            if not node:
                return
            cur = 1
            if node.val == parent + 1:
                cur += parent_path

            ans = max(ans, cur)
            dfs(node.left, node.val, cur)
            dfs(node.right, node.val, cur)

        dfs(root, root.val + 1, 0)
        return ans
```
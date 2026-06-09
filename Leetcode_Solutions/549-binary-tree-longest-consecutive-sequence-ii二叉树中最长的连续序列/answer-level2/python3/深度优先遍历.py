### 解题思路
-   每个节点都想上传递下面三个值

```
val, up, down

- 当前节点的值
- 当前当前节点向下递增的最长序列
- 当前当前节点向下递减的最长序列
```

-   **注意**：考虑左右节点同时存在，并且左右节点以当前节点为中心的连接，更新结果值即可



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

        def dfs(node):
            nonlocal ans
            if not node.left and not node.right:
                ans = max(ans, 1)
                return node.val, 1, 1
            current_up = 1
            current_down = 1
            if node.left and node.right:
                left = dfs(node.left)
                right = dfs(node.right)
                if node.val == left[0] - 1 and node.val == right[0] + 1:
                    ans = max(ans, left[1] + right[2] + 1)
                if node.val == left[0] + 1 and node.val == right[0] - 1:
                    ans = max(ans, left[2] + right[1] + 1)
                if node.val == left[0] - 1:
                    current_up = max(current_up, 1 + left[1])
                if node.val == right[0] - 1:
                    current_up = max(current_up, 1 + right[1])
                if node.val == left[0] + 1:
                    current_down = max(current_down, 1 + left[2])
                if node.val == right[0] + 1:
                    current_down = max(current_down, 1 + right[2])
                ans = max(ans, current_up, current_down)
                return node.val, current_up, current_down

            elif node.left and not node.right:
                left = dfs(node.left)
                if node.val == left[0] - 1:
                    current_up = max(current_up, 1 + left[1])
                if node.val == left[0] + 1:
                    current_down = max(current_down, 1 + left[2])
                ans = max(ans, current_up, current_down)
                return node.val, current_up, current_down

            elif not node.left and node.right:
                right = dfs(node.right)
                if node.val == right[0] - 1:
                    current_up = max(current_up, 1 + right[1])
                if node.val == right[0] + 1:
                    current_down = max(current_down, 1 + right[2])
                ans = max(ans, current_up, current_down)
                return node.val, current_up, current_down
        dfs(root)
        return ans
```
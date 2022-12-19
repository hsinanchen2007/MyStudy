### 解题思路
子树的高度作为分组的标准
每次都是先左后右

### 代码

```python3
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def findLeaves(self, root: TreeNode) -> List[List[int]]:
        ans = []

        def dfs(node):
            if not node:
                return 0
            current_level = max(dfs(node.left), dfs(node.right))
            if current_level >= len(ans):
                ans.append([])

            ans[current_level].append(node.val)
            return current_level + 1

        dfs(root)
        return ans
```
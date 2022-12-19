### 解题思路
![image.png](https://pic.leetcode-cn.com/f2a27b73d42fe0122cf3e1492e83a20ba8748b7016a9d89130344c3fe59d7ea4-image.png)

- DFS
- 从子节点向上传递三个值
   - 最小值
   - 最大值
   - 搜索节点的数量

如果搜索节点的数量是-1，表示子树已经不是搜索树了

### 代码

```python
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def largestBSTSubtree(self, root: TreeNode) -> int:
        if not root:
            return 0
        ans = 0

        def dfs(node):
            nonlocal ans
            if not node.left and not node.right:
                ans = max(ans, 1)
                return node.val, node.val, 1

            if node.left and node.right:
                left_min, left_max, left_num = dfs(node.left)
                right_min, right_max, right_num = dfs(node.right)
                if left_num != -1 and right_num != -1:
                    if left_max < node.val < right_min:
                        ans = max(ans, left_num + right_num + 1)
                        return left_min, right_max, left_num + right_num + 1

            elif node.left and not node.right:
                left_min, left_max, left_num = dfs(node.left)
                if left_num != -1:
                    if left_max < node.val:
                        ans = max(ans, left_num + 1)
                        return left_min, node.val, left_num + 1
            elif not node.left and node.right:
                right_min, right_max, right_num = dfs(node.right)
                if right_num != -1:
                    if node.val < right_min:
                        ans = max(ans, right_num + 1)
                        return node.val, right_max, right_num + 1

            return -1, -1, -1

        dfs(root)
        return ans
```
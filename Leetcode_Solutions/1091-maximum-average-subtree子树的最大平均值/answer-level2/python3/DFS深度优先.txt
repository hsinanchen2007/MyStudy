### 解题思路
![image.png](https://pic.leetcode-cn.com/592232d48a25bd025859ffcf654196f1cf17061f10c93be4e4bfaba0bc1e9876-image.png)
- 从底部向上更新，向上返回当前树的和值与节点数

### 代码

```python
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def maximumAverageSubtree(self, root: TreeNode) -> float:
        ans = float('-inf')

        def dfs(node):
            nonlocal ans
            if not node:
                return 0, 0
            left_sum, left_count = dfs(node.left)
            right_sum, right_count = dfs(node.right)
            cur_sum = left_sum + right_sum + node.val
            cur_count = left_count + right_count + 1
            ans = max(ans, cur_sum / cur_count)
            return cur_sum, cur_count

        dfs(root)
        return ans
```
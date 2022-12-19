### 解题思路
注意，这个问题的终止条件，是左子树或者右子树满足，都算满足

### 代码

```python3
class Solution:
    def _dfs(self, root, curr_sum: int, sum: int) -> bool:
        if not root:
            return False

        curr_sum += root.val

        if not root.left and not root.right and curr_sum == sum:
            return True

        return self._dfs(root.right, curr_sum, sum) or self._dfs(root.left, curr_sum, sum)

    def hasPathSum(self, root: TreeNode, sum: int) -> bool:
        if not root:
            return False
        return self._dfs(root, 0, sum)
```
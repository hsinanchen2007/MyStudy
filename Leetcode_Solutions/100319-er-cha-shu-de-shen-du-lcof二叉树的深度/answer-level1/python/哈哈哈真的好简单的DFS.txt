### 解题思路
如果是None则是0
否则，就是左孩子、右还在的高度的最大值，再加上自身的高度1

### 代码

```python3
class Solution:
    def maxDepth(self, root: TreeNode) -> int:
        if not root:
            return 0

        return max(self.maxDepth(root.left), self.maxDepth(root.right)) + 1
```
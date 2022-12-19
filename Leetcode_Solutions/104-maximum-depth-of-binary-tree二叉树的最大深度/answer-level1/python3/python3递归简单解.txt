### 解题思路
此处撰写解题思路

### 代码

```python3
class Solution:
    def maxDepth(self, root: TreeNode) -> int:
        def test(depth, node):
            if not node:
                return depth
            return max(test(depth +1 , node.left), test(depth +1 , node.right))
        return test(0,root)
```
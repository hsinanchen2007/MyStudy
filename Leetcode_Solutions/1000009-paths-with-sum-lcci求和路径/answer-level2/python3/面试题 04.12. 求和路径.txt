### 解题思路

前序遍历，前缀和栈化。

### 代码

```python []
class Solution:
    def pathSum(self, root: TreeNode, sum: int) -> int:
        def f(r, s):
            if r:
                s = [i + r.val for i in s] + [r.val]
                return s.count(sum) + f(r.left, s) + f(r.right, s)
            return 0
        return f(root, []) 
```
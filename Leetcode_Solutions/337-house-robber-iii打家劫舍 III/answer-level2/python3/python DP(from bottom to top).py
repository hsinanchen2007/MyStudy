Thinking: 自底向上递归， max(该节点 + 孙子节点之和, 子节点之和)
Note: 不用cache过不了， 以后递归尽量都加上cache

```python
from functools import lru_cache
class Solution:
    @lru_cache(None) # 对节点进行缓存 相当于用了一个map
    def rob(self, root: TreeNode) -> int:
        if root == None: return 0
        r1 = self.rob(root.left) + self.rob(root.right)
        r2 = 0
        if root.left != None:
            r2 += self.rob(root.left.left) + self.rob(root.left.right)
        if root.right != None:
            r2 += self.rob(root.right.left) + self.rob(root.right.right)
        return max(r1, r2 + root.val)
```

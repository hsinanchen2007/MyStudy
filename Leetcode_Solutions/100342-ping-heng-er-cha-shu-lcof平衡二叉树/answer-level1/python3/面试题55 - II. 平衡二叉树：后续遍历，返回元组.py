### 解题思路
后续遍历树，返回该子树是否是平衡二叉树以及树的深度的元组。

### 代码

```python []
class Solution:
    def isBalanced(self, root: TreeNode) -> bool:
        def f(r):
            if r:
                ansleft, hleft = f(r.left)
                ansright, hright = f(r.right)
                return ansleft and ansright and abs(hleft - hright) <= 1, max(hleft, hright) + 1
            return True, 0
        return f(root)[0]
```
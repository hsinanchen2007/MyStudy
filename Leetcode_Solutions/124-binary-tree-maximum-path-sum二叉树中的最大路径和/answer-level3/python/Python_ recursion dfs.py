### 解题思路
此题做搜索的时候要返回两个值，分别是节点最大的一边路径和，以及节点及左右两边的路径和，他们均可以通过其左右连个子节点的这两个值求得。
做搜索的时候也要记录当前的最大路径和，最后返回的时候还要比较下根节点。

### 代码

```python
class Solution:
    def maxPathSum(self, root: TreeNode) -> int: 
        self.res = -float('inf')
        def dfs(root):
            if not root:
                return (0, -float('inf')) #single path, total
            left, l_tot = dfs(root.left)
            right, r_tot = dfs(root.right)
            self.res = max(l_tot, r_tot, self.res)
            return (root.val + max(left, right, 0), root.val + max(left, right, left + right, 0))
        
        return max(dfs(root)[1], self.res)
```
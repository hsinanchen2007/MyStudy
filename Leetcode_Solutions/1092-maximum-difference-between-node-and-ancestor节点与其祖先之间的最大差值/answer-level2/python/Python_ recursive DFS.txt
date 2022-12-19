### 解题思路
此题使用递归的关键点在于传什么信息给子节点。因为原题要找的是 path range，那么我们需要把当前路径里的最大最小值传给子节点，如果子节点不在这个范围内，更新路径的最大或最小值。由此得到此路径的最大差值，然后和全局最大差值作比较。

### 代码

```python
class Solution:
    def maxAncestorDiff(self, root: TreeNode) -> int:
        if not root: return 0
        self.res = 0
        self.dfs(root, root.val, root.val)
        return self.res

    def dfs(self, root, hi, lo):
        self.res = max(hi - lo, self.res)
        if root:
            hi, lo = max(hi, root.val), min(lo, root.val)
            self.dfs(root.left, hi, lo)
            self.dfs(root.right, hi, lo)


```
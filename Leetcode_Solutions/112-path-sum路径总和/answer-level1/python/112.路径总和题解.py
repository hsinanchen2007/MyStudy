从根节点开始，每当遇到一个节点的时候，从目标值里减去节点值，一直到叶子节点判断目标值是不是被扣完。
```
class Solution:
    def hasPathSum(self, root: TreeNode, sum: int) -> bool:
        if not root: return False
        t = sum - root.val
        if not root.left and not root.right:
            return t == 0
        return self.hasPathSum(root.left, t) or self.hasPathSum(root.right, t)


```
许多树的题目均可以使用该模版进行解决：
```
def func(self, root: TreeNode) -> int:
        if not root: return XXX
        if condition(root): return XXX
        l = self.func(root.left)
        r = self.func(root.right)
        return sol(l,r)
```
其中condition(root)表示特殊条件下需要返回值，例如111题需要考虑左子树或者右子树为空的情形下，返回另一棵子树的深度。

sol(l,r)表示根据题目的需要对左右子树做相应的处理以得出最终的结果。

就本题而言没有额外的特殊条件，不需要condition(root)。

根据题意要求得到最大深度，因此我们查找左右子树中最高的那一棵加上根节点即可，即max(l,r)+1。

```
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def maxDepth(self, root: TreeNode) -> int:
        if not root: return 0
        l = self.maxDepth(root.left)
        r = self.maxDepth(root.right)
        return max(l,r)+1
```

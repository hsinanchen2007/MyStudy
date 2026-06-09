```python
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def hasPathSum(self, root: TreeNode, sum: int) -> bool:
        if not root: return False
        l, r, f = root.left, root.right, lambda x: self.hasPathSum(x, sum - root.val)
        return l is r and sum == root.val or f(l) or f(r)
```
- 考虑初始状态：当树不存在时直接返回 False
- 考虑支路1：当前节点为叶节点时直接判断总和是否达到要求
- 考虑支路2：当前节点为非叶节点时将总和缩小并继续递归，判断左右节点是否存在满足条件的
- 当递归函数到达叶节点时，sum 已经被削减了多次，此时 `sum - node.val` 即为 `原始的sum - 整条路径的总和`
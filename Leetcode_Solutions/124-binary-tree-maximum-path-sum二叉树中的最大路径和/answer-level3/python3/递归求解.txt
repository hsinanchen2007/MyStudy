在递归当前节点时，需要分如下情况讨论，在返回时，以下两种情况所得最大值都需要返回
1. 当前节点可以与父节点连接，则最大值（代码中 max_in_branch ）需要从如下情况中取值
   - 当前节点与左子树的 max_in_branch 之和
   - 当前节点与右子树的 max_in_brach 之和
   - 当前节点自身的值
2. 当前节点不与父节点连接，则最大值（代码中 max_in_tre e）需要从如下情况中取值
   - 左子树的 max_in_brach
   - 右子树的 max_in_brach
   - 当前节点与左右子树的 max_in_branch 之和
   - 左子树的 max_in_branch 因为未连接当前节点，所以可以看作一条封闭路径
   - 右子树的 max_in_branch

```python3
n_inf = float('-inf')

def max_tree(root: TreeNode) -> [int, int]:
    left_root = right_root = left = right = n_inf  # 初始化为负无穷，可以省去很多对 None 的处理
    if root.left is not None:
        [left, left_root] = max_tree(root.left)
    if root.right is not None:
        [right, right_root] = max_tree(root.right)
    max_in_tree = max(left_root, right_root, left + root.val + right, left, right)
    max_in_branch = max(left + root.val, root.val + right, root.val)
    return [max_in_branch, max_in_tree]


class Solution:
    def maxPathSum(self, root: TreeNode) -> int:
        max_arr = max_tree(root)
        return max(max_arr)
```

上述代码总长不到 20 行，测评结果为 92ms（93.73%），19.5MB（100%）

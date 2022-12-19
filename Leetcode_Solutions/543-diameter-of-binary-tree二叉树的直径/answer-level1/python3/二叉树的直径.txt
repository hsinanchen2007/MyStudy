### 解题思路
* 递归
* 以节点`curr`为根节点的树的直径 = max(`curr`左子树的直径，`curr`右子树的直径，经过`curr`节点的路径的长度）
* 其中，经过`curr`节点的路径的长度 = `curr`左子树深度 + `curr`右子树深度 + 2(2个edges)
* 因此，递归返回两个值：`diameter`和`depth`。`diameter`是该节点为根的树的直径；`depth`是该节点为根的树的深度，返回是为了让父节点调用计算。
* p.s. 认为单节点形成的树的深度为0

### 代码

```python []
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def diameterOfBinaryTree(self, root: TreeNode) -> int:
        def helper(curr: TreeNode):
            if curr is None:
                return 0, -1
            left_diameter, left_depth = helper(curr.left)
            right_diameter, right_depth = helper(curr.right)
            depth = max(left_depth, right_depth) + 1
            diameter = max([left_diameter, right_diameter, left_depth+right_depth+2])
            return diameter, depth
        if root is None:
            return 0
        diameter, _ = helper(root)
        return diameter
```
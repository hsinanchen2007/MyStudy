### 解题思路
每个点的最大值有三种可能 max（左分支+右分支+val，左分支+val，右分支+val，val）
作为经过路径的子节点，该节点的值转换为路径的最大值 max（左分支+val，右分支+val，val）

### 代码

```python3
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def maxPathSum(self, root: TreeNode) -> int:
        res=-float('inf')
        def get_max_solution(rt):
            nonlocal res
            if rt.left:
                get_max_solution(rt.left)
            if rt.right:
                get_max_solution(rt.right)
            val=rt.val
            value_left=-float('inf')
            value_right=-float('inf')
            if rt.left:
                value_left=rt.left.val
            if rt.right:
                value_right=rt.right.val
            max_leave_value=max(value_left,value_right)
            res=max(res,val+value_left+value_right,val+max_leave_value,val)
            rt.val=max(val,val+max_leave_value)
        get_max_solution(root)
        return res

```
### 解题思路
利用前序遍历和栈的思想解题

### 代码

```python3
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def pathSum(self, root: TreeNode, sum: int) -> List[List[int]]:
        self.path = []
        self.path_value = 0
        res_path = []
        def help(root, sum, res_path, path, path_value):
            if root == None:
                return
            path_value = path_value + root.val
            path.append(root.val)
            if root.left == None and root.right == None and path_value == sum:
                res_path.append(path[:])
            help(root.left, sum, res_path, path, path_value)
            help(root.right, sum, res_path, path, path_value)
            path.pop()
        help(root, sum, res_path, self.path, self.path_value)       
        return res_path
```
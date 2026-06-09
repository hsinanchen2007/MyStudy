### 解题思路
其实真正想明白了思路代码写起来没有几行...

官方解答的思路就是: return node.val + left_gain + right_gain. 本质上就是最正常的树的递归遍历嘛..
但是这其中要注意到判断new_tree_value, 如果 node.val + left_max_gain + right_max_gain > global_max了, 就要把global_max更新一下了.

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
        def max_gain(node):
            nonlocal global_max
            if node is None:
                return 0
            left_max_gain = max(max_gain(node.left), 0)
            right_max_gain = max(max_gain(node.right), 0)
            new_tree_value = node.val + left_max_gain + right_max_gain  # 判断当前root树能否更新global_max
            global_max = max(global_max, new_tree_value)
            return node.val + max(left_max_gain, right_max_gain)
        global_max = float('-inf')
        max_gain(root) # 此处不需要接收返回值.
        return global_max
    
    
```
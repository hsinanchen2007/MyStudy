### 解题思路

先得保证深度相同
再保证不同的父节点.
时间复杂度:o(n)
空间复杂度:o(1)
### 代码

```python
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def isCousins(self, root: TreeNode, x: int, y: int) -> bool:
        def helper(root,goal):
            '''层次遍历3'''
            if not root:
                return None
            current = [root]
            depth = 0
            while current:
                next_layer = []
                depth += 1
                for node in current:
                    if node:
                        if node.val == goal:
                            return [node.val,depth-1]
                        elif node.left and node.left.val == goal:
                            return [node.val,depth]
                        elif node.right and node.right.val == goal:
                            return [node.val,depth]
                        next_layer.extend([node.left, node.right])
                current = next_layer
            
        result_x = helper(root,x)
        result_y = helper(root,y)
        x_root = result_x[0]
        y_root = result_y[0]
        x_depth = result_x[1]
        y_depth = result_y[1]        
        # 先得保证深度相同
        # 再保证不同的父节点
        if x_depth == y_depth and x_root != y_root:
            return True
        else:
            return False
        
```
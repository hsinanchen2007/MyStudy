##### 自底向上，计算坡度，并向上返回该子树的和, 以便上一层的根节点计算坡度

```
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def findTilt(self, root: TreeNode) -> int:
        result = 0
       
        # tree_sum 得到以root为根节点的树的所有节点的和
        def tree_sum(root):
            nonlocal result
            if root is None:
                return 0
            l_sum = tree_sum(root.left)
            r_sum = tree_sum(root.right)
            result += abs(l_sum-r_sum)
            return l_sum+r_sum+root.val
        
        tree_sum(root)
        return result
            
```

递归验证 ，大致思路如下：  
1. 如果当前节点可用，则将当前节点值与其上、下限进行比较
2. 然后对于左、右子树重复该步骤

需要注意以下几点：  
1. 程序初始化时，上、下限分别为对应语言中正无穷和负无穷，python中使用float('-inf')和float('inf')表示
2. 递归过程中需不断更新上、下限，左子节点上限为当前节点值，右子节点下限为当前节点值

```reasonml
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

import sys
class Solution:
    def isValidBST(self, root: TreeNode) -> bool:
        
        def helper(node, lower, upper):
            if not node:
                return True
            
            if node.val > lower and node.val < upper:
                return helper(node.left, lower, node.val) and helper(node.right, node.val, upper)
            else:
                return False
        
        return helper(root, float('-inf'), float('inf'))
        
            
        
```
 
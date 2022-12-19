```
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def isSymmetric(self, root: TreeNode) -> bool:
        """
           涉及到树，首先想到的要么是深搜，要么是广搜
           
           
        """
        if root is None:
            return True
        
#         # 方法一, 使用递归, 也就是将同一行相邻的A和B两个节点, 即比较A的右节点与B的左节点
#         # A的左节点和B的右节点
#         def helper(node_1, node_2):
#             if node_1 is None and node_2 is None:
#                 return True
#             if node_1 is not None and node_2 is not None:
#                 if node_1.val != node_2.val:
#                     return False
#             else:
#                 return False
            
#             return helper(node_1.right, node_2.left) and helper(node_1.left, node_2.right)
        
        
#         return helper(root.left, root.right)
        
        # 方法二, 使用迭代的方式, 宽度优先搜索
        stacks = [root.left, root.right]
        while len(stacks) > 0:
            tmp_left = stacks.pop(0)
            tmp_right = stacks.pop(0)
            
            if tmp_left is None and tmp_right is None:
                continue
            
            if tmp_left is not None and tmp_right is not None:
                if tmp_left.val != tmp_right.val:
                    return False
                else:
                    stacks.append(tmp_left.left)
                    stacks.append(tmp_right.right)
                    stacks.append(tmp_left.right)
                    stacks.append(tmp_right.left)
            else:
                return False
        
        return True
```

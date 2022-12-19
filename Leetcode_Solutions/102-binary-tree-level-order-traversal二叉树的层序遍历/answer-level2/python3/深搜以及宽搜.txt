```
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def levelOrder(self, root: TreeNode) -> List[List[int]]:
        """
           既然是按照层进行输出，第一想到的肯定就是宽度优先搜索
        """
        if root is None:
            return []
        
#         # 方法一，迭代, 使用宽度优先搜索的方式
#         ancor = [root]
#         val_ans = [[root.val]]
        
#         while True:
#             tmp_append_list = []
#             for x in ancor:
#                 if x.left is not None:
#                     tmp_append_list.append(x.left)
#                 if x.right is not None:
#                     tmp_append_list.append(x.right)
#             if len(tmp_append_list) == 0:
#                 break
#             else:
#                 ancor = tmp_append_list
            
#             val_ans.append([x.val for x in tmp_append_list])
                
        
#         return val_ans
        # 方法二, 使用递归的方式, 此时需要记录层的索引, 这里记录层的索引非常重要
          
        val_ans = []
        def helper(node, level):
            if len(val_ans) < level:
                val_ans.append([])
            val_ans[level-1].append(node.val)
            
            if node.left is not None:
                helper(node.left, level+1)
            
            if node.right is not None:
                helper(node.right, level+1)
        
        helper(root, 1)
        
        return val_ans
            
          
```

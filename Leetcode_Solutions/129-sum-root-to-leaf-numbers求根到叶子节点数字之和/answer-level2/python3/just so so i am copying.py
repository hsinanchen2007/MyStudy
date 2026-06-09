```
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    #存储过程
    def sumNumbers(self, root: TreeNode) -> int:
        if not root: return 0

        res = 0 
        def dfs(root, value):
            nonlocal res
            if not  root:
                 value.append(0)
                 return 
            else:
                value.append(root.val)

            if value and not root.left and not root.right:
                print(value)
                i = 1
                for v in value[::-1]:
                    res += v*i
                    i *= 10
                return 
            
            dfs(root.left,value)
            if len(value) != 1:
                value.pop()
            dfs(root.right,value)
            value.pop()
            
        dfs(root, [])
        return res

    # 回溯当前值，不需要存储
    def sumNumbers(self, root: TreeNode) -> int:
        if not root: return 0
        
        res = 0 
        def dfs(root, value):
            nonlocal res
            value += root.val  
            if not root.left and not root.right:
                res += value
                return        
            if root.left:
                dfs(root.left,value*10)
            if root.right:
                dfs(root.right,value*10)
 
            
        dfs(root, 0)
        return res


```

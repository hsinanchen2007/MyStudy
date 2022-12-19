Python 3 递归和非递归
```
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
     def convertBST(self, root: TreeNode) -> TreeNode:
         # 递归算法 分析：先遍历右节点，再存储根节点，最后遍历左节点
         self.sum = 0
         def dfs(root):
             if not root: return root
             dfs(root.right)
             self.sum = self.sum + root.val
             root.val = self.sum
             dfs(root.left)
             return root
         return dfs(root)
    
```
非递归算法：使用栈做DFS
```
class Solution:

    def convertBST(self, root: TreeNode) -> TreeNode:
        self.sum = 0
        # 非递归算法
        def dfs(root):
            if not root: return root
            stack = []
            node = root
            while node or stack:
                while node:
                    stack.append(node)
                    node = node.right
                node = stack.pop()
                self.sum += node.val
                node.val = self.sum
                self.sum = node.val
                node = node.left
            return root
        return dfs(root)
```
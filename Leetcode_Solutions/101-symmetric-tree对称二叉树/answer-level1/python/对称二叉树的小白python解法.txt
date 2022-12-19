### 解题思路
python递归 迭代算法

### 代码

```python递归
# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution(object):
    # def isSymmetric(self, root):
    #     """
    #     :type root: TreeNode
    #     :rtype: bool
    #     """
    #     if not root:
    #         return True
    #     def dfs(left,right):
    #         if(left==None and right==None):
    #             return True
    #         if(left==None or right==None):
    #             return False
    #         if(left.val != right.val):
    #             return False
    #         return dfs(left.left,right.right) and dfs(left.right,right.left)
    #     #用递归函数比较左节点和右节点
    #     return dfs(root.left,root.right)
    
    #python迭代
    def isSymmetric(self,root):
        if root==None:
            return True
        queue = [root.left,root.right]

        while queue:
            left = queue.pop(0)
            right = queue.pop(0)
            print(left)
            print(right)
            if left==None and right==None:
                continue
            if left==None or right==None:
                return False
            if left.val != right.val:
                return False
            
            queue.append(left.left)
            print(queue)
            queue.append(right.right)
            print(queue)
            queue.append(left.right)
            print(queue)
            queue.append(right.left)
            print(queue)
        return True

```

```python []
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def mergeTrees(self, t1: TreeNode, t2: TreeNode) -> TreeNode:
        if not t1 and t2: #判断t1是否存在 如果不存在就直接返回t2来替代t1的位置
            return t2
        elif t1 and t2: #如果t1 和 t2 都存在 将他们的值相加并给t1.val
            t1.val += t2.val
            t1.left = self.mergeTrees(t1.left,t2.left) #递归求解左子树
            t1.right = self.mergeTrees(t1.right,t2.right) #递归求解右子树
        return t1 #返回t1 （包含如果上述条件都不满足 想当于 t2不存在 直接返回t1的情况）
```

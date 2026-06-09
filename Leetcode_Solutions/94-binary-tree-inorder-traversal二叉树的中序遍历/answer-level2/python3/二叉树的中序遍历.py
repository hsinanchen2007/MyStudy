### 解题思路
当函数最终需要返回一个列表（或者字典、元组、集合）时，则应该定义一个函数内部的递归函数。

### 代码

```python
# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution(object):
    def inorderTraversal(self, root):
        """
        :type root: TreeNode
        :rtype: List[int]
        """
        res = []  # 需要返回一个列表
        def helper(root):  # 递归主体是helper，而不是inorderTraversal函数
            if not root:   
                return 
            helper(root.left)  # 递归leftChild
            res.append(root.val) # 将局部根结点加入列表（即遍历根节点）
            helper(root.right)   # 递归rightChild
        helper(root)  # 调用递归函数
        return res
        

```
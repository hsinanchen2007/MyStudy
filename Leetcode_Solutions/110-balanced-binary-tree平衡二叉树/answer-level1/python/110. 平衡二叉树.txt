### 解题思路
递归，自上向下，计算每一节点子树深度差

### 代码

```python
# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution(object):
    def isBalanced(self, root):
        #计算二叉树每一节点深度
        def depth(root1):
            if not root1:
                return -1
            根节点深度为左右子树深度的最大值
            return 1 + max(depth(root1.left),depth(root1.right))
        if not root:return True
        #自顶向下查询深度差
        if abs(depth(root.left) - depth(root.right)) > 1:
            return False
        else:
            return self.isBalanced(root.left) and self.isBalanced(root.right)
```
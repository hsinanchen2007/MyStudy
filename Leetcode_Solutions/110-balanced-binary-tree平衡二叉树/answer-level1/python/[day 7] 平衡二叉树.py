### 解题思路

套模版
后序遍历
只要有一个 不平衡 就返回 false

### 代码

```python
# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution(object):
    def balance(self,root):
        left , right = 0,0
        if not root.left and not root.right:
            return 1
        if root.left:
            if not self.balance(root.left):
                return False
            left += self.balance(root.left)
        if root.right:
            if not self.balance(root.right):
                return False
            right += self.balance(root.right)
        # print(left,right)
        if abs(left-right)>1:
            return False
        return max(left,right)+1

    def isBalanced(self, root):
        """
        :type root: TreeNode
        :rtype: bool
        """
        if not root:
            return True
        res =  self.balance(root)
        # print('res',res)
        if res == False:
            return False
        return True
        


```
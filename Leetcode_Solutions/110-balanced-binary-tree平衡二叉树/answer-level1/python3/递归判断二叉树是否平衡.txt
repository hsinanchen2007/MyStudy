### 解题思路
1.先计算每一个节点的高度
2.计算每一个节点的高度差，并判断左右节点是否平衡
### 代码

```python
# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution(object):
    def height(self,root):
        if not root:
            return -1
        root_left = self.height(root.left)    
        root_right = self.height(root.right)
        max_height = max(root_left,root_right) + 1
        return max_height
    def isBalanced(self, root):
        """
        :type root: TreeNode
        :rtype: bool
        """
        if not root:
            return True
        return abs((self.height(root.left)-self.height(root.right)))<2 and self.isBalanced(root.left) and self.isBalanced(root.right) 

        
```
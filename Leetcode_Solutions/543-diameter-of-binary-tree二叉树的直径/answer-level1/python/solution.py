### 解题思路
此处撰写解题思路

### 代码

```python
# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution(object):
    # def getHeight(self,root):
    #     if (root == None):
    #         return 0
    #     left_height = self.getHeight(root.left)
    #     right_height = self.getHeight(root.right)
    #     return max(left_height,right_height) + 1

    def diameterOfBinaryTree(self, root):
        """
        :type root: TreeNode
        :rtype: int
        """
        if root == None:
            return 0
        self.diameter = 0

        def getHeight(root):
            if (root == None):
                return 0
            left_height = getHeight(root.left)
            right_height = getHeight(root.right)
            self.diameter = max(self.diameter, left_height+right_height+1)
            return max(left_height,right_height) + 1

        getHeight(root)
        return self.diameter-1
```
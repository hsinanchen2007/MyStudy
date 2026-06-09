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
    def buildTree(self, inorder, postorder):
        """
        :type inorder: List[int]
        :type postorder: List[int]
        :rtype: TreeNode
        """
        def Build(i1, j1, i2, j2):
            root = TreeNode(postorder[j2-1])
            index = inorder.index(postorder[j2-1])
            if index>i1:
                root.left = Build(i1, index, i2,i2+index-i1)
            if index<j1-1:
                root.right = Build(index+1, j1, i2+index-i1, j2-1)
            return root
        length = len(inorder)
        if not length:
            return None
        return Build(0, length, 0, length)
```
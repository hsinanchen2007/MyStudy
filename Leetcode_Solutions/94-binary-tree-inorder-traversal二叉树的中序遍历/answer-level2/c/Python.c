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
    def inorderTraversal(self, root):
        ans=[]
        def inorder(root):
            if root!=None:
                inorder(root.left)
                ans.append(root.val)
                
                inorder(root.right)
        inorder(root)
        return ans


```
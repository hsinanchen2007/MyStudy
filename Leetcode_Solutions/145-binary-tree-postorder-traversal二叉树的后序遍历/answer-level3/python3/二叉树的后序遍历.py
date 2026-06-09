### 解题思路
此处撰写解题思路

### 代码

```python3
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def postorderTraversal(self, root: TreeNode) -> List[int]:
        res=[]
        if root:
            res+=self.postorderTraversal(root.left)
            res+=self.postorderTraversal(root.right) 
            res.append(root.val)
        return res
```
### 解题思路
此处撰写解题思路
![image.png](https://pic.leetcode-cn.com/98a5c040e7ce9f465a766b417ab9e308cda8d300cf0d2174a537bd406e744e88-image.png)

### 代码

```python3
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    sum0 = 0
    def bstToGst(self, root: TreeNode) -> TreeNode:  
        if root.right:
            self.bstToGst(root.right)
        self.sum0 += root.val
        root.val = self.sum0    
        if root.left:
            self.bstToGst(root.left)
        

        return root
            
            
```
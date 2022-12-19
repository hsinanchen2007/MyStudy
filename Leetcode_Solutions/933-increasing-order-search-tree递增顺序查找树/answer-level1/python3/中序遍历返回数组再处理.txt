### 解题思路
中序遍历返回数组

### 代码

```python3
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def increasingBST(self, root: TreeNode) -> TreeNode:
        res = self.helper(root)
        for i in range(len(res)-1):
            res[i].left , res[i].right = None , res[i+1]
        res[-1].left = None
        res[-1].right = None
        return res[0]
    
    #中序遍历返回数组
    def helper(self,root):
        if not root:
            return []
        else:
            return self.helper(root.left) + [root] + self.helper(root.right)


```
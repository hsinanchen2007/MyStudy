### 解题思路
返回二叉搜索树中序遍历结果：递增数组
### 代码

```python3
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def minDiffInBST(self, root: TreeNode) -> int:
        res = self.helper(root)
        if len(res) < 2:
            return
        m = res[2] - res[1]
        for i in range(len(res)-1):
            if res[i+1] - res[i] < m:
                m = res[i+1] - res[i]
        return m
    
    #返回二叉搜索树中序遍历结果：递增数组
    def helper(self,root):
        if not root:
            return []
        else:
            return self.helper(root.left) + [root.val] + self.helper(root.right)
```
### 解题思路
中序遍历二叉搜索树返回递增数组索引为k-1的元素

### 代码

```python3
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def kthSmallest(self, root: TreeNode, k: int) -> int:
        res = self.helper(root)
        return res[k-1]
    
    #中序遍历二叉搜索树返回递增数组
    def helper(self,root):
        if not root:
            return []
        else:
            return self.helper(root.left) + [root.val] + self.helper(root.right)
```
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
    def kthLargest(self, root: TreeNode, k: int) -> int:
        """
        思路：利用二叉搜索树的中序遍历是递增序列的性质。
        中序遍历：左 + 根 + 右
        """
        if not root:
            return None
        def _dfs(node):
            if not node:
                return []
            return _dfs(node.right) + [node.val] + _dfs(node.left)
        res = _dfs(root)
        # print(res)
        return res[k-1]
            
            
```
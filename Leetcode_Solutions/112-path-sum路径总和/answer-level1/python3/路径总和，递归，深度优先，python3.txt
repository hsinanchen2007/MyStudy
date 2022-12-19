### 解题思路
如过root为空，返回空
如果当前节点为叶节点，比较sum和节点值是否相等，相等返回True
否则递归调用本函数


```
if dfs(T.left, s-T.val): return True
if dfs(T.right, s-T.val): return True

```
### 代码

```python3
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def hasPathSum(self, root: TreeNode, sum: int) -> bool:
        def dfs(T, s):
            if not T:
                return
            if not T.left and not T.right:
                if T.val == s: return True
            if dfs(T.left, s-T.val): return True
            if dfs(T.right, s-T.val): return True
        return dfs(root, sum)
```
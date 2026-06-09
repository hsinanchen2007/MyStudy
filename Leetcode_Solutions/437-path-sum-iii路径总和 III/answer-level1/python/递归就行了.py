### 解题思路
递归

### 代码

```python3
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def pathSum(self, root: TreeNode, sum: int) -> int:
        if not root:
            return 0
        def dfs(node,target):
            if not node:
                return 0
            l,r=0,0
            target=[node.val]+[_ + node.val for _ in target]
            l=dfs(node.left,target)
            r=dfs(node.right,target)
            return target.count(sum)+l+r
        return dfs(root,[])


```
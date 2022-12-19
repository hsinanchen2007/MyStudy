### 解题思路
求树最大路径
每步求包含此节点根节点的最大路径以及不包含此节点根节点的最大路径
学会用self


### 代码

```python3
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def maxPathSum(self, root: TreeNode) -> int:
        def dfssum(root):
            if not root:
                return 0
            val = root.val
            suml = max(0,dfssum(root.left))
            sumr = max(0,dfssum(root.right))
            self.res = max(self.res,sumr+suml+val)
            return max(suml,sumr)+val
        self.res = -1e10
        dfssum(root)
        return self.res


```
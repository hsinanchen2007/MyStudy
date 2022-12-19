### 解题思路
从二叉树问题的遍历的框架开始思考问题，这里要知道左右子树的和才能处理后续的动作，所以优先选择后续遍历。
在便利过程中，对所有节点求和剪枝。并将局部最优解记录到全局变量中。

### 代码

```python3
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    ans = -float('inf')
    def maxPathSum(self, root: TreeNode) -> int:
        return max(self.OneSideMax(root), self.ans)

    def OneSideMax(self, root):
        if root is None:
            return 0
        left = max(0, self.OneSideMax(root.left))
        right = max(0, self.OneSideMax(root.right))
        self.ans = max(self.ans, left+right+root.val)
        return max(left, right) + root.val 
```
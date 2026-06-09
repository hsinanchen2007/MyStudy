### 解题思路
遍历从根节点到叶子节点的过程中，寻找最大数和最小数，再比较差值大小

时间复杂度： o(n)
空间复杂度： 如果不算递归栈的调用的话，空间复杂度为o(1), 算的话是，空间复杂度是o(n)

### 代码

```python3
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def maxAncestorDiff(self, root: TreeNode) -> int:
        if not root:
            return 
        self.max = None
        def dfs(root, max_num, min_num):
            if not root:
                return
            max_num = max(root.val, max_num)
            min_num = min(root.val, min_num)
            tmp = abs(max_num - min_num)
            if not self.max or self.max < tmp:
                self.max = tmp
            dfs(root.left, max_num, min_num)
            dfs(root.right, max_num, min_num)
        dfs(root, float('-inf'), float('inf'))
        return self.max
```
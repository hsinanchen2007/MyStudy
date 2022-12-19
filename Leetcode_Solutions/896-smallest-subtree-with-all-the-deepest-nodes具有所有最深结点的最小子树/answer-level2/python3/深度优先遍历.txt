### 解题思路
深度遍历，从下往上考虑
dfs(node) 返回第一位为节点，第二位为所在层，当node 为None时，返回None, 0;

根据示例图：
dfs(7), 返回7, 1; dfs(4), 返回4, 1
dfs(2), 返回2, 2; dfs(6), 返回6, 1; dfs(0) 返回 0, 1, dfs(8) 返回8, 1
dfs(5) 由于右边的深度大于左边，所以返回2, 3; dfs(1) 返回1, 2
dfs(3) 返回2, 4。

1123题同样的解法：
[https://leetcode-cn.com/problems/lowest-common-ancestor-of-deepest-leaves/]()

### 代码

```python3
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def subtreeWithAllDeepest(self, root: TreeNode) -> TreeNode:
        def dfs(root):
            if not root:
                return None, 0
            left, i = dfs(root.left)
            right, j = dfs(root.right)
            if i > j:
                return left, i + 1
            elif j > i:
                return right, j + 1
            return root, i + 1
        return dfs(root)[0]
```
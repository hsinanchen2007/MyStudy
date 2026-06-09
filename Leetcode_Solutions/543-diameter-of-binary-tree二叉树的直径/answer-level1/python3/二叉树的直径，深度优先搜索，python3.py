### 解题思路
首先定义一个变量res用来存储最大直径
定义一个函数，来获取树的最大深度
将左子树的最大深度L加上右子树的最大深度T与res作比较，取较大值赋给res
递归调用本函数

### 代码

```python3
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def diameterOfBinaryTree(self, root: TreeNode) -> int:
        self.res = 0
        def dfs(T):
            if not T:
                return 0
            L = dfs(T.left)
            R = dfs(T.right)
            if L+R > self.res:
                self.res = L+R
            return max(L+1, R+1)
        dfs(root)
        return self.res

```
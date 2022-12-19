### 解题思路
理解 python 的语言特性， self.val 变量，以及闭包 (Class内部函数, 函数内部函数)，以及 传值还是传引用

这一题官方代码写的不是非常清楚。看了很久才懂。
我自己写的比较清楚。

### 代码

```python3
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def rangeSumBST(self, root: TreeNode, L: int, R: int) -> int:

        def dfs(node):
            result = 0
            if node:
                if L<= node.val <=R:
                    result += node.val
                    result += dfs(node.left)
                    result += dfs(node.right)
                elif node.val < L:
                    result += dfs(node.right)
                else:
                    result += dfs(node.left)
            return result
            
        result = dfs(root)  # 传引用
        return result

```
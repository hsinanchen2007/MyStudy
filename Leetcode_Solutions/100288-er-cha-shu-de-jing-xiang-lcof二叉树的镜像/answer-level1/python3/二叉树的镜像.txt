### 解题思路
二叉树--**递归**！
注意：
1. 类比面试题55-1 求二叉树的深度；
2. 和上述题不太一样的是不需要重新定义递归函数，因为本题输入变量仅为root，而无其他变量；
3. 需要定义一个中间变量，避免覆盖原值的情况。

### 代码

```python3
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def mirrorTree(self, root: TreeNode) -> TreeNode:
        if root == None: return None
        temp = root.left
        root.left = self.mirrorTree(root.right)
        root.right = self.mirrorTree(temp)
        return root
```
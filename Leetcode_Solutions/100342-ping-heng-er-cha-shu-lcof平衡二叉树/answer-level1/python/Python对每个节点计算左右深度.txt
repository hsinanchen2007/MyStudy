### 解题思路
写了三个子函数。清楚一点。
分别用来计算节点深度，节点的左子树深度，节点的右子树深度。

### 代码

```python3
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def isBalanced(self, root: TreeNode) -> bool:
        def HeightofNode(node):
            if node == None:
                return 0
            L = HeightofNode(node.left)
            R = HeightofNode(node.right)
            return max(L,R) + 1
        def LHeightofNode(node):
            if node.left == None:
                return 0
            return HeightofNode(node.left)
        def RHeightofNode(node):
            if node.right == None:
                return 0
            return HeightofNode(node.right)
        if root == None:
            return True
        stack = [root]
        while stack:
            node = stack.pop(0)
            if abs(LHeightofNode(node) - RHeightofNode(node)) <= 1:
                if node.left:
                    stack.append(node.left)
                if node.right:
                    stack.append(node.right)
            else:
                return False
        return True
```
### 解题思路
遍历所有节点

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
        self.ans = 1
        def depth(root_node):
            if not root_node:
                return 0
            else:
                L = depth(root_node.left)
                R = depth(root_node.right)
                self.ans = max(self.ans, L+R+1)
                return max(L,R) + 1
        depth(root)
        return self.ans - 1
```
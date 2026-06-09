### 解题思路
此处撰写解题思路

### 代码

```python3
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def countNodes(self, root: TreeNode) -> int:
        if not root:
            return 0
        stack = [root]
        # bfs
        n = 0
        while stack:
            n += 1
            node = stack.pop(0)
            if not node.left:
                return 2 * n - 1
         
            else:
                if not node.right:
                    return 2 * n
                stack.append(node.left)
                
            stack.append(node.right)   

```